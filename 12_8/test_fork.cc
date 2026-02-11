#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

void Loop()
{
    while(true)
    {
        printf("我是子进程: %d, ppid: %d\n", getpid(), getppid());
        sleep(1);
    }
}

int main()
{
    const int num = 10;
    for(int i = 0 ; i < num; i++)
    {
        pid_t id = fork();
        if(id == 0)
        {
            //子进程
            Loop();
        }
        else if(id > 0)
        {
            //父进程
        }
        else{
            break;
        }
        sleep(1);
    }

    while(true)
    {
        printf("我是父进程: %d, ppid: %d\n", getpid(), getppid());
        sleep(1);
    }
}

