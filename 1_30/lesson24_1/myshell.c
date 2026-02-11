#include "myshell.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

// 提示符(真的是字符串)相关
static char username[32];
static char hostname[64];
static char cwd[256];
static char commandline[256];

// 命令行相关
static char *argv[64];  // 一般最多也就十几个
static int argc = 0;    
static const char *sep = " ";

// 与退出码有关
static int lastcode;

// 与环境变量有关，应该由bash来维护，从系统配置文件读，直接从系统bash拷贝即可
char **_environ = NULL;
static int envc = 0;    // 计数器

// 与重定向相关
// ls -a -l > text,txt
#define NONE_REDIR 0
#define IN_REDIR 1
#define OUT_REDIR 2
#define APP_REDIR 3
static int redir_type = NONE_REDIR;
static char *redir_filename = NULL;

#define CLEAR_LEFT_SPACE(pos) do{while(isspace(*pos)) pos++;} while(0) // issplace: 剔除空格

static void GetUserName()
{
    char *_username = getenv("USER");   // 获取环境变量
    strcpy(username,(_username ? _username : "None"));
}

static void GetHostName()
{
    char *_hostname = getenv("HOSTNAME");   // 获取环境变量
    strcpy(hostname,(_hostname ? _hostname : "None"));
}

//static void GetCwdName()    // 要详细处理，包括只保留"/"之后的路径
//{
//    char *_cwd = getenv("PWD");   // 获取环境变量
//    strcpy(cwd,(_cwd ? _cwd : "None"));
//}

static void GetCwdName()    // 要详细处理，包括只保留"/"之后的路径
{
    char _cwd[256];
    getcwd(_cwd,sizeof(_cwd));
    if(strcmp(_cwd,"/") == 0)
    {
        strcpy(cwd,_cwd);
    }
    else
    {
        int end = strlen(_cwd) - 1;
        while(end >= 0)
        {
            if(_cwd[end] == '/')
            {
                // 如 /home/Alice
                strcpy(cwd,&_cwd[end + 1]);
                break;
            }
            end--;
        }
    }
}

void PrintPrompt()
{
    GetUserName();
    GetHostName();
    GetCwdName();
    printf("[%s@%s %s]# ",username,hostname,cwd);
    fflush(stdout); // 直接刷新缓冲区
}

static void GetCommandLine()
{
    if(fgets(commandline,sizeof(commandline),stdin) != NULL)
    {
        // 比如"abcd\n" -> "abcd"
        commandline[strlen(commandline) - 1] = 0;
        // printf("debug:%s\n",commandline);
    }
}

static void ParseCommandLine()
{
    // 清空
    argc = 0;
    memset(argv,0,sizeof(argv));
    // 判空
    if(strlen(commandline) == 0)
        return;
    // 解析 ls -a -l
    argv[argc] = strtok(commandline,sep);   // strtok分割字符串，变成几个子串
    while((argv[++argc] = strtok(NULL,sep)));   // argc的大小即子串个数

    // 检查别名: 到别名表里
// // 调试信息注释掉
//    printf("argc:%d\n",argc);
//    int i = 0;
//    for(;argv[i];i++)
//    {
//        printf("argv[%d]:%s\n",i,argv[i]);
//    }
}

// 创建子进程
void Execute()
{
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork");
        return;
    }
    else if(id == 0)
    {
        // printf("child running..\n");
        // 子进程
        // 程序替换
        
        // 伪代码
        // cat file.c
        // 1.判断命令类型: cat
        // 2.获取用户身份，用户名，包括用户id
        // 3.获取文件的属性，用户，所属组，Mode
        // 4.权限管理
        // 要不要重定向，怎么重定向
        // filename
        if(redir_type == IN_REDIR)
        {
            int fd = open(redir_filename,O_RDONLY);
            (void)fd;   // 这里我没有判定，判定可以写一下的
            dup2(fd,0);
        }
        if(redir_type == OUT_REDIR)
        {
            int fd = open(redir_filename,O_CREAT | O_WRONLY | O_TRUNC,0666);
            (void)fd;
            dup2(fd,1);
        }
        if(redir_type == APP_REDIR)
        {
            int fd = open(redir_filename,O_CREAT | O_WRONLY | O_APPEND,0666);
            (void)fd;
            dup2(fd,2);
        }
        else{
            // do nothing
        }
        execvp(argv[0],argv);
        exit(1);
    }
    else{
        // 父进程
        int status = 0;
        pid_t rid = waitpid(id,&status,0);  // 得到状态
        (void)rid;
        lastcode = WEXITSTATUS(status);
    }
}

// 1：yes
// 0：no
int CheckBuiltinAndExcute()
{
    int ret = 0;
    if(strcmp(argv[0],"cd") == 0)
    {
        // 内建命令
        ret = 1;
        if(argc == 2)   // 有选项
        {
            chdir(argv[1]);
        }
    }
    else if(strcmp(argv[0],"echo") == 0)
    {
        ret = 1;
        if(argc == 2)
        {
            // echo $?
            // echo $PATH
            // echo "helloworld"
            // echo helloworld
            if(argv[1][0] == '$')
            {
                if(strcmp(argv[1],"$?") == 0)
                {
                    printf("%d\n",lastcode);
                    lastcode = 0;   // 返回上一次的退出码
                }
                else
                {
                    // env：环境变量
                }
            }
            else
            {
                printf("%s\n",argv[1]); // 打印字符串，不细分什么""或者没有""了
            }
        }
    }
    else if(strcmp(argv[0],"env") == 0)
    {
        ret = 1;
        int i = 0;
        for(;i < envc;i++)
        {
            printf("%s\n",_environ[i]);
        }
    }
    else if(strcmp(argv[0],"export") == 0)
    {
        ret = 1;    // export：自建命令
        if(argc == 2)   // 必然有第2个参数
        {
            // export myval=100 -> 添加到环境变量表里面
            char *mem = (char*)malloc(strlen(argv[1] + 1));
            strcpy(mem,argv[1]);
            _environ[envc++] = mem;
            _environ[envc] = NULL;
        }
    }

    return ret;
}

void static LoadEnv()
{
    extern char **environ;
    for(envc = 0;environ[envc];envc++)
    {
        _environ[envc] = environ[envc];
    }
    _environ[envc] = NULL;
}

void Redir()
{
    // 核心目标
    // "ls -a -l >> > < filename"
    // redir_filename = filename
    // redir_type = IN_REDIR
    char *start = commandline;
    char *end = commandline + strlen(commandline);
    while(start < end)
    {
        // > >> <
        if(*start == '<')
        {
            if(*start == '<')
            {
                // 追加重定向
            }
            else
            {
                // 输出重定向
                redir_type = OUT_REDIR;
                *start = '\0';
                start++;
                CLEAR_LEFT_SPACE(start);
                redir_filename = start;
                break;
            }
        }
        else if(*start == '>')
        {
            // 输入重定向
        }
        else
        {
            start++;
        }
    }
}

void Bash()
{
    // 环境变量相关，应该由bash来维护，从配置文件读，直接从系统bash拷贝就可以了
    static char *env[64];
    _environ = env;

//    // 再形成一张表：本地变量表
//    static char *alais[64];
//    static char *local[64]; // 我们shell内部定义的变量，自己保存，比如a=100,b=200
    // 默认不带export，写到这个local本地变量表里面；
    // 带了export，写到env环境变量表里面
    
    // 第0步：获取环境变量
    LoadEnv();
    while(1)    // 软件都是死循环的
    {
        // 第1步：输出命令行
        PrintPrompt();

        // 第2步：等待用户输入，获取用户输入
        // char commandline[256]; -> scanf()
        // sleep(1);   // 等待一会儿
        GetCommandLine();
        
        // "ls -a -l > filename" -> "ls -a -l" "filename" redir_type
        // 第2.1步
        Redir();    // 调用重定向的成员函数

        // 第3步：解析字符串，"ls -a -l" -> "ls" "-a" "-l"
        ParseCommandLine();
        if(argc == 0)
            continue;

        // 第4步：有些命令，cd、ench、env、export等命令，不应该让子进程执行
        // 而应该让父进程自己执行，内建命令。bash内部的函数
        if(CheckBuiltinAndExcute())
        {
            continue;
        }

        // 第5步：执行命令
        Execute();
    }
}
