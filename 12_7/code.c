#include <stdio.h>
#include <unistd.h>

int main()
{
    int a = 10;
    scanf("%d", &a);
   // while(1)
   // {
   //     printf("我是一个进程, 我正在运行: %d？\n", getpid());
   // }
    return 0;
}


//struct obj
//{
//    int a;
//    int b;
//    char c;
//    double d;
//};
//
//int main()
//{
//    struct obj x;
//    printf("&x: %p, &(x.a): %p\n", &x, &(x.a));
//    long long offset = (long long)&(((struct obj*)0)->d);
//
//    long long start = (long long)&(x.d) - offset;
//    printf("offset: %d\n", offset);
//
//    printf("addr对比: %p, %p\n", &x, start);
//
//    return 0;
//}

// -----------------------------------------------------------------

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//
//int main()
//{
//    fork();
//
//    printf("我是一个进程: pid: %d,ppid: %d\n",getpid(),getppid());
//
//    sleep(1);
//
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    int a = 10;
//    scanf("%d",&a);
//    printf("hello %d\n",a);
//
//    return 0;
//}

//#include <stdio.h>
//#include <unistd.h>
//
//int main()
//{
//    int a = 10;
//    scanf("%d", &a);
//   // while(1)
//   // {
//   //     printf("我是一个进程, 我正在运行: %d？\n", getpid());
//   // }
//    return 0;
//}

//struct obj
//{
//    int a;
//    int b;
//    char c;
//    double d;
//};
//
//int main()
//{
//    struct obj x;
//    printf("&x: %p, &(x.a): %p\n", &x, &(x.a));
//    long long offset = (long long)&(((struct obj*)0)->d);
//
//    long long start = (long long)&(x.d) - offset;
//    printf("offset: %d\n", offset);
//
//    printf("addr对比: %p, %p\n", &x, start);
//
//    return 0;
//}
