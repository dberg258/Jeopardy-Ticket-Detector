#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{
    char path[] = "/Users/Daniel/jeopardy_email/";
    char to[] = "2019949266@vtext.com";   

    char website_file[100], email_file[100], execel_path[100];
    strcpy(website_file, path);
    strcpy(email_file, path);
    strcpy(execel_path, path);
    strcat(website_file, "tickets");
    strcat(email_file, "email_body");
    strcat(execel_path, "jeopardy_script.sh");

    pid_t pid;
    //   while(1){    
    remove(website_file);
    pid = fork();
    if (pid < 0) {
        die("fork failed");
    } else if (pid == 0) {
        execl(execel_path, execel_path, (char*) 0);
        die("execl failed");
    }else{
        while(waitpid(pid, NULL, 0) != pid){
            die("waitpid failed.");
        }
        FILE* html = fopen(website_file,"rb");
        char buf[100000];
        fread(buf, 1, sizeof(buf), html);
        if(!strstr(buf, "There are no tapings scheduled at this time.")){
            char cmd[1000];  
            char body[] = "Jeopardy Tickets!!!!!\nhttps://www.jeopardy.com/tickets";   
            char tempFile[100];    
            strcpy(tempFile, email_file); 
            FILE *fp = fopen(tempFile,"w"); 
            fprintf(fp,"%s\n",body);        
            fclose(fp);             
            sprintf(cmd, "mail %s < %s", to, email_file); // if using for email, can use -s flag for subject
            printf("Sending message to %s.\n", to);
            system(cmd);        
            system("sendmail");
            system("osascript -e 'tell application (path to frontmost application as text) to display dialog \"Jeopardy Tickets!!!\" with icon stop'"); 
        }
        else if(buf[0] != 0 && buf[1] !=0){
            printf("No Jeopardy tickets availble at this time.\n");
        }
        //sleep(300);
    }
    // } 
    return 0;
}
