#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void Printlog()
{
    printf("")
}


//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{



    printf("我是父进程, pid :%d, ppid : %d\n", getpid(), getppid());
    pid_t id = fork();
    if(id == 0)
    {
        //child
        int cnt = 5;
        while(cnt)
        {
            printf("我是子进程, pid :%d, ppid : %d, cnt: %d\n", getpid(), getppid(), cnt);
            sleep(1);
            cnt--;
            //int *p = NULL;
            //*p = 100;
           // int a = 10;
           // a/=0;
        }
        exit(13);
    }

    while(1)
    {
        int status = 0;
        pid_t rid = waitpid(id, &status, WNOHANG);
        if(rid > 0)
        {
            // status >>= 8 || status = status>>8
            // 7F : 0111 1111
            //printf("wait success, who: %d, status: %d, exit code: %d, exit sig: %d\n", rid, status, (status>>8)&0xFF, status & 0x7F);
            if(WIFEXITED(status))
            {
                printf("子进程正常退出, 退出码: %d\n", WEXITSTATUS(status));
            }
            else
            {
                printf("进程出异常了,请注意!\n");
            }
            break;
        }
        else if(rid == 0)
        {
            sleep(1);
            printf("子进程还没有退出，父进程轮询!\n");
            for(int i = 0; i < 3; i++)
            {
                tasks[i]();
            }
        }
        else{
            printf("wait failed, who: %d, status: %d\n", rid, status);
            break;
        }
    }
    return 0;
}
