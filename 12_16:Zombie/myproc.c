#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("我是父进程:%d\n",getpid());

    pid_t id = fork();
    if(id == 0)
    {
        // 子进程
        int cnt = 5;
        while(1)
        {
            sleep(1);
            printf("我是子进程，我正在运行: %d,ppid: %d\n",getpid(),getppid());
            cnt--;
        }
        printf("我是子进程，我退出了: %d,ppid: %d\n",getpid(),getppid());
    }
    else if(id > 0)
    {
        // 父进程
        int cnt = 5;
        while(cnt--)
        {
            sleep(1);
            printf("我是父进程，我退出了: %d,ppid: %d\n",getpid(),getppid());
        }
    }
    else{}

    return 0;
}
