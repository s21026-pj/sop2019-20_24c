#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t PID = getpid();
    pid_t PPID = getppid();
    printf("PID: %d\n",PID);
    printf("PPID: %d\n",PPID);
}