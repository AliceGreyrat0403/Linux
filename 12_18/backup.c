//#include<time.h>
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<string.h>
//
//int print()
//{
//    printf("haha,I'm a process! pid: %d, ppid: %d\n",getpid(),getppid());
//    _exit(13);
//}
//
//int main()
//{
//    int n = printf();
//    printf("n = %d\n", n);
//    
//    return 10;
//}

#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    while(1)
    {
        printf("haha,I'm a process! pid: %d, ppid: %d\n",getpid(),getppid());
        sleep(1);
        int a = 10;
        a/=0;   // 有/0错误，但是符合C语言语法，最多给一个告警，程序照样能够跑，过了1秒程序退出，因为出异常了
    }

}

//// 证明信号可以杀死进程，但是还不能直观地证明进程中间出异常退出是因为受到信号的影响
//#include<stdio.h>
//#include<unistd.h>
//#include<time.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("haha,I'm a process! pid: %d, ppid: %d\n",getpid(),getppid());
//        sleep(1);
//    }
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<time.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    int i = 0;
//    for(;i < 255;i++)
//        printf("%d->%s\n",i,strerror(i));
//    printf("haha,I'm a process! pid: %d,ppid: %d\n",getpid(),getppid());
//
//    return 88;
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<time.h>
//#include<stdlib.h>
//
//#define NUM 10
//
//int data[NUM] = {0};
//
//void Backup()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        // 子进程
//        int i = 0;
//        printf("Backup: ");
//        for(i = 0;i < NUM;i++)
//        {
//            printf("%d ",data[i]);
//        }
//        printf("\n");
//        sleep(10);
//        exit(0);    // 进程结束
//    }
//}
//
//void ChangeData()
//{
//    int i = 0;
//    for(;i < NUM;i++)
//    {
//        data[i] = i + rand();
//    }
//    printf("origin data: ");
//    for(i = 0;i < NUM;i++)
//    {
//        printf("%d ",data[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    srand(time(NULL));
//    while(1)
//    {
//        // 修改
//        ChangeData();
//        // 备份
//        Backup();
//        sleep(5);
//    }
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<time.h>
//#include<stdlib.h>
//
//#define NUM 10
//
//int data[NUM] = {0};
//
//void Backup()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        // 子进程
//        int i = 0;
//        printf("Backup: ");
//        for(i = 0;i < NUM;i++)
//        {
//            printf("%d ",data[i]);
//        }
//        printf("\n");
//        sleep(10);
//        exit(0);    // 进程结束
//    }
//}
//
//void ChangeData()
//{
//    int i = 0;
//    for(;i < NUM;i++)
//    {
//        data[i] = i + rand();
//    }
//}
//
//int main()
//{
//    srand(time(NULL));
//    while(1)
//    {
//        // 修改
//        ChangeData();
//        // 备份
//        Backup();
//        sleep(5);
//    }
//}
