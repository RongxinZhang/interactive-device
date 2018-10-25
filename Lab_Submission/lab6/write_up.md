# Chat Bot

*A lab report by Rongxin Zhang rz345*

## In this Report

## Updated ChatBot Code

[Full Code](https://github.com/RongxinZhang/IDD-Fa18-Lab6/blob/master/chatServer.js)

The places with updates have a comment

```js
/*
  * RONGXIN: Changed
 */
```

```js
/*
chatServer.js
Author: David Goedicke (da.goedicke@gmail.com)
Closley based on work from Nikolas Martelaro (nmartelaro@gmail.com) as well as Captain Anonymous (https://codepen.io/anon/pen/PEVYXz) who forked of an original work by Ian Tairea (https://codepen.io/mrtairea/pen/yJapwv)
*/

var express = require('express'); // web server application
var app = express(); // webapp
var http = require('http').Server(app); // connects http library to server
var io = require('socket.io')(http); // connect websocket library to server
var serverPort = 8000;


//---------------------- WEBAPP SERVER SETUP ---------------------------------//
// use express to create the simple webapp
app.use(express.static('public')); // find pages in public directory

// start the server and say what port it is on
http.listen(serverPort, function() {
  console.log('listening on *:%s', serverPort);
});
//----------------------------------------------------------------------------//


//---------------------- WEBSOCKET COMMUNICATION -----------------------------//
// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', function(socket) {
  console.log('a new user connected');
  var questionNum = 0; // keep count of question, used for IF condition.
  socket.on('loaded', function() { // we wait until the client has loaded and contacted us that it is ready to go.

    /*
     * RONGXIN: Changed
     */
    socket.emit('answer', "Hey, hello I am BLU a bipolar chat bot."); //We start with the introduction;
    setTimeout(timedQuestion, 5000, socket, "What is your name?"); // Wait a moment and respond with a question.

  });
  socket.on('message', (data) => { // If we get a new message from the client we process it;
    console.log(data);
    questionNum = bot(data, socket, questionNum); // run the bot function with the new message
  });
  socket.on('disconnect', function() { // This function  gets called when the browser window gets closed
    console.log('user disconnected');
  });
});
//--------------------------CHAT BOT FUNCTION-------------------------------//
function bot(data, socket, questionNum) {
  var input = data; // This is generally really terrible from a security point of view ToDo avoid code injection
  var answer;
  var question;
  var waitTime;

  /// These are the main statments that make up the conversation.
  if (questionNum == 0) {
    answer = 'Hello ' + input + ' :-)'; // output response
    waitTime = 5000;
    /*
     * RONGXIN: Changed
     */
    question = 'What is your favorite day of the week?'; // load next question
  } else if (questionNum == 1) {
    /*
     * RONGXIN: Changed
     */
    if (input.toLowerCase().includes("thu"))
      answer = 'Woow! Me too!'
    else
      answer = input + ' is probably the worst day in the week...sorry, we can\'t be friends anymore';

      waitTime = 5000;
      question = 'Where do you live?'; // load next question
  }
```
## A video of friend using chatbot

[![](http://img.youtube.com/vi/km_utV647gs/0.jpg)](https://youtu.be/km_utV647gs)
