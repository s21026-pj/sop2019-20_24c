#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sstream>
int fd;
void my_handler(int s){
           printf("\nClosing listening socket\n**********EXIT**********\n");
           close(fd);
           exit(1); 

}


int main (int argc,char *argv[])
{
    int log;
    log = open ("Log.txt",O_CREAT | O_TRUNC | O_WRONLY,S_IRUSR|S_IWUSR);
    char msg4 []="LOGI:";
    write(log,msg4,sizeof(msg4));
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    struct sockaddr_in p;
    struct sockaddr_in q;
    int z,s,t,x,n = sizeof(q);
    socklen_t b=sizeof(q);
    char buf[23];
    

    s = socket(AF_INET,SOCK_STREAM,0);

    bzero (&p,sizeof(p));
    p.sin_family = AF_INET;
    p.sin_addr.s_addr = INADDR_ANY;
    p.sin_port = htons(51515);

    bind (s,(struct sockaddr*)&p,sizeof(p));
    listen(s,13);

    while (1) {
        t = accept (s,(struct sockaddr*)&q, &b);

        unsigned short port=q.sin_port;
        printf("Port: %u\n",port);
        auto ports=std::to_string(port);
        char *portc = &ports[0];
        char msg[]="\nPort: ";
        write (log,msg,sizeof(msg));
        write (log,portc,sizeof(portc));
        

        struct sockaddr_in *addr_in = (struct sockaddr_in *)&q;
        char *IP = inet_ntoa(addr_in->sin_addr);
        printf("IP address: %s\n", IP);
        char msg2[]=" | IP: ";
        write (log,msg2,sizeof(msg2));
        write (log,IP,sizeof(IP)+1);

        n = read(t,buf,23);
        buf[n] = 0;
        char msg3[]=" | Requested file:";
        write (log,msg3,sizeof(msg3));
        write (log,buf,n);
        
        printf("%s sent: ",buf);
        fd = open (buf,O_RDONLY);
        if(fd==-1){
            printf("File not found\n");
            char msg5[]=" | File not found! ";
            write (log,msg5,sizeof(msg5));
            buf[0]='-';
            buf[1]='1';
            write (t,buf,2);
        }
        else
        {

        z = lseek(fd,0,SEEK_END);
        lseek(fd,0,SEEK_SET);
        x = 0;
        do {
            n = read (fd,buf,23);
            write (t,buf,n);
            x += n;
        } while (x < z);
        printf("%d/%d\n",x,z);
        close(fd);
        }
        close(t);
    }
}