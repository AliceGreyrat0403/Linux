#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("我是父进程: pid: %d,ppid: %d\n",getpid(),getppid());
    execl("/usr/bin/ls","ls","-a","-l",NULL);
    printf("我正常退出了...\n");
    return 0;
}
