#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    printf("我是父进程,pid : %d,ppid : %d\n",getpid(),getppid());
    pid_t id = fork();
    if(id == 0)
    {
        // child
        int cnt = 5;
        while(cnt)
        {
            printf("我是子进程,pid : %d,ppid : %d\n",getpid(),getppid());
            sleep(1);
            cnt--;
        }
        exit(1);
    }
    
    int status = 0;
    pid_t rid = waitpid(id,&status,0);
    if(rid > 0)
    {
        printf("wait success,who: %d,status: %d\n",rid,status);
    }
    else{
        printf("wait failed,who: %d,status: %d\n",rid,status);
    }

    return 0;
}
