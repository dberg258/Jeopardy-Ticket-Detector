# Jeopardy Ticket Detector

A script for determining if there are jeopardy tickets available. If there are, you will be sent an email/sms.

![](https://i.imgur.com/mnxAkwq.jpg)

Configuration:

1- Create a folder to host the project files and provide the file path in jeopardy_email.cpp:
      
    char path[] = "<path to project folder>";

2- Provide either the email or phone number you would like to be contacted at (jeopardy_email.cpp): 
  
    (Only fill out one of the below variables; comment the other) 
    char to[] = "<phone number>@vtext.com"; // this is for Verizon; check the phone_urls file for other carriers
    char to[] = "<e-mail>";

3- Change the file path in "jeopardy_script.sh": 
            
    /Users/Daniel/jeopardy_email/tickets  --->  <file path to project folder>/tickets

3- (Optional) Scheduler: I have provided an example scheduler program in schedule_instructions.
      
    This example is for launchd on mac systems. The file paths and file names must be changed. 
