#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) 
{
    int ret;
    char buf[5];
    int s,n,fd;
    struct sockaddr_in p;
    struct hostent *h;
    char *str = argv[1]; //Client przyjmuje jako argument nazwe pliku który chce pobrać

    fd = open (str,O_CREAT | O_TRUNC | O_WRONLY,S_IRUSR|S_IWUSR); // Tworzy plik o podanej nazwie, jeśli istnieje usuwa jego zawartość jeśli ie istnieje tworzy go
    h = gethostbyname("DESKTOP-9JJI6AE"); //Wpisanie nazwy hosta na stałe - do zmiany w zależnośći od tego na jakim hoście testujemy

    bzero(&p,sizeof(p));
    p.sin_family = AF_INET;
    p.sin_addr.s_addr = htonl(INADDR_ANY);
    p.sin_addr.s_addr = ((struct in_addr*)(h->h_addr))->s_addr;
    p.sin_port = htons(51515); //Wpisanie portu na stałe

    s = socket (AF_INET,SOCK_STREAM,0);
    connect (s,(struct sockaddr *)&p,sizeof(p));
    n = write (s,str,strlen(str));
    int idx = 0;
    int l=0;
    do {
        n = read (s,buf,5);
        idx += n;
        printf(".");
        fflush(stdout);
        if(buf[0]=='-'&&buf[1]=='1'){
            remove(str);
            l=1;
        }else
        {
            write (fd,buf,n);
        }
        
    } while (n > 0);
    if(l==1){
        printf("\n Unable to get flie : %s \n",str);
    }
    close (fd);
    close (s);
    return 0;
}