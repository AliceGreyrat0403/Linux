#pragma once

typedef struct{
    int fd;
    int flags;
    int mode;   // 刷新策略
    char outbuffer[1024];
    int cap;    // 缓冲区总容量
    int size;   // 缓冲区当前的数据量
    //char inbuffer[1024];
}My_FILE;

// 定义宏，是什么类型的缓冲
#define NONE_CACHE 1
#define LINE_CACHE 2
#define FULL_CACHE 4    // 1 2 4只有一个比特位为1（0001/0010/0100），检测起来比较容易

My_FILE *Myfopen(const char *pathname,const char *mode); // r w a方式 --> 打开文件
//int Myfputs(const char *message,My_FILE *fp);   // Myfputs可能太偏字符串，一会儿还要刷新，刷新还要写入，就用Myfwrite了
int Myfwrite(const char *message,int size,int num,My_FILE *fp); // 写文件
void Myfflush(My_FILE *fp); // 刷新
void Myfclose(My_FILE *fp); // 关闭文件
