# Video Doorbell, Lab 7

*A lab report by Rongxin Zhang*

### In This Report

## Part A. HelloYou from the Raspberry Pi

**a. Link to a video of your HelloYou sketch running.**

Connected Door bell

[![](http://img.youtube.com/vi/phOI0Xnc0O8/0.jpg)](https://youtu.be/phOI0Xnc0O8) 

## Part B. Web Camera

**a. Compare `helloYou/server.js` and `IDD-Fa18-Lab7/pictureServer.js`. What elements had to be added or changed to enable the web camera? (Hint: It might be good to know that there is a UNIX command called `diff` that compares files.)**

**b. Include a video of your working video doorbell**

Connected arduino to P.I

[![](http://img.youtube.com/vi/LPhRzmFsg3s/0.jpg)](https://youtu.be/LPhRzmFsg3s) 

Door Bell controlled by button worked

[![](http://img.youtube.com/vi/FhTqDCBubmk/0.jpg)](https://youtu.be/FhTqDCBubmk) 


## Part C. Make it your own

**a. Find, install, and try out a node-based library and try to incorporate into your lab. Document your successes and failures (totally okay!) for your writeup. This will help others in class figure out cool new tools and capabilities.**

I installed 2 new packages, `nodeMailer` and `ip`.

The below functions sends and email to an email account with the link to the the image and the src of the images.

Below is the code that I edited.

```js
function emailSender(account, imageURL){
  let transporter = nodemailer.createTransport({
    host: 'smtp.ethereal.email',
    port: 587,
    secure: false, // true for 465, false for other ports
    auth: { user: account.user, pass: account.pass }
  });

  // setup email data with unicode symbols
  let mailOptions = {
      from: '"Thomas M Trad" <thomastrad@gmail.com>', // sender address
      to: 'you@mail.com', // list of receivers
      subject: 'House alert', // Subject line
      html: '<b>Someone is at the door!</b> <br/> <img src="'+imageURL+'"/>' // html body
  };

  // send mail with defined transport object
  transporter.sendMail(mailOptions, (error, info) => {
      if (error) {
          return console.log(error);
      }
      console.log('Message sent: %s', info.messageId);
      console.log('Preview URL: %s', nodemailer.getTestMessageUrl(info));
  });
}
```

The [Full Code](./takePicture.js) is available. I added the comments `RONGXIN:....` to the places that I made edits

**b. Upload a video of your working modified project**

Door Bell that sends an email to the user with the image of the person at the door.

[![](http://img.youtube.com/vi/PJScmfzYadU/0.jpg)](https://youtu.be/PJScmfzYadU) 

Example url: https://ethereal.email/message/W8i9HPS8igw5hZK7W8i9HsXuyAzkwm3PAAAAARndROawdyoNsCkWppPmSlk
