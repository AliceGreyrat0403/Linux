#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    fork();

    printf("我是一个进程：pid: %d,ppid: %d\n",getpid(),getppid());

    sleep(1);

    return 0;
}

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>                   
//
//int main()
//{
//    char pwd[128];
//    getcwd(pwd,128);   
//    printf("before: %s\n",pwd);
//    chdir("/home/Alice/118_12_7/linux-git/12_7"); 
//    getcwd(pwd,128);
//    printf("after: %s\n",pwd);  
//    
//    pid_t id = getpid();
//    FILE *fp = fopen("log.txt","w");
//    (void)fp;
//
//    while(1)
//    {
//        printf("hello,I am process,pid: %d\n",id);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>                   
//                                    
//int main()              
//{
//    pid_t id = getpid();                        
//    FILE *fp = fopen("log.txt","w");              
//    (void)fp;                                   

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>                   
//                                    
//int main()              
//{
//    pid_t id = getpid();                        
//    FILE *fp = fopen("log.txt","w");              
//    (void)fp;                                   

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>                   
//                                    
//int main()              
//{
//    pid_t id = getpid();                        
//    FILE *fp = fopen("log.txt","w");              
//    (void)fp;                                   

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>                   
//                                    
//int main()              
//{
//    pid_t id = getpid();                        
//    FILE *fp = fopen("log.txt","w");              
//    (void)fp;                                   
//                                
//    while(1)                                    
//    {
//        printf("hello,I am process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}



//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<unistd.h>                                                          
//#include<sys/types.h>
//
//int main()
//{
//    pid_t id = getpid();
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n",id);
//        sleep(1);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n");
//        sleep(1);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n");
//        sleep(1);
//    }
//    return 0;
//}
//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process,pid: %d\n");
//        sleep(1);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;
//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;

//#include<stdio.h>
//#include<unistd.h>
//
//int main()
//{
//    while(1)
//    {
//        printf("hello,I am a process\n");
//        sleep(1);
//    }
//    return 0;
//}
