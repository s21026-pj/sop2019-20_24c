#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{   
    pid_t MPID=getpid();
    pid_t p = fork();
    pid_t PID = getpid();
    pid_t PPID = getppid();
    printf("PID: %d\n",PID);
    printf("PPID: %d\n",PPID);
    int wej;
    scanf("%d",&wej);
    if(MPID==getpid()){
        int status=0;
        waitpid(0,&status,0);
    }
    return 0;
}