#include<stdio.h>
#include<unistd.h>

//int main()
//{
//    char *who = getenv("USSR");
//    if(strcmp(who,"whb") == 0)
//    {
//        printf("我是一个命令，变成了进程运行\n");
//    }
//    else{
//        printf("权限错误，不认识你: %s\n",who);
//    }
//    return 0;
//}

int main(int argc,char *argv[])
{
    (void)argc;
    if(strcmp(argv[1],"-a") == 0)
    {
        printf("这是我的程序的功能1\n");
    }
    else if(strcmp([1],"-b") == 0)
    {
        printf("这是我的程序的功能2\n");
    }
    else
    {
        printf("这是我的程序的默认功能\n");
    }
    return 0;
}

//int main(int argc,char *argv[])
//{
//    int i = 0;
//    for(;i < argc;i++)
//    {
//        printf("argc[%d]: %s\n",i,argv[i]);
//    }
//    return 0;
//}
