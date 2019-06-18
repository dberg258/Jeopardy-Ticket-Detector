# Jeopardy Ticket Detector

A script for determining if there are jeopardy tickets available. If there are, you will be sent an email/sms.

Configuration:

1- Create a folder to host the project files and provide the file path:
      
    char path[] = "<path to project folder>";

2- Provide either the email or phone number you would like to be contacted at: 
  
    (Only fill out one of the below variables; comment the other) 
    char to[] = "<phone number>@vtext.com"; // this is for a Verizon number; check the phone_links file for other carriers
    char to[] = "<e-mail>";
