#include "my_stdio.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h> // malloc
#include <unistd.h>

static mode_t global_mode = 0666;

// My_FILE *fp = Myfopen("log.txt","a");
// 我写的和库的基本的细节肯定不一样，但是核心思想在大的轮廓上是一样的
My_FILE *Myfopen(const char *pathname,const char *mode) // r w a方式(在内部选择不同的模式)
{
    if(pathname == NULL || mode == NULL)   
        return NULL;
    umask(0);
    int fd = 0;
    int flags = 0;
    if(strcmp(mode,"w") == 0)
    {
        flags = O_CREAT | O_WRONLY | O_TRUNC;
        fd = open(pathname,flags,global_mode);
        (void)fd;
    }
    if(strcmp(mode,"r") == 0)
    {
        flags = O_RDONLY;
        fd = open(pathname,flags);   // 传两参数的open
        (void)fd;
    }
    if(strcmp(mode,"a") == 0)
    {
        flags = O_CREAT | O_WRONLY | O_APPEND;
        fd = open(pathname,flags,global_mode);
        (void)fd;
    }
    else
    {}

    if(fd < 0)  // 文件打开失败
        return NULL;

    // 创建My_FILE对象
    My_FILE* fp = (My_FILE*)malloc(sizeof(My_FILE));
    if(!fp) // 声明失败，直接返回
        return NULL;

    fp->fd = fd;
    fp->flags = flags;
    fp->mode = LINE_CACHE;
    fp->cap = 1024; // 容量，因为缓冲区大小定义的就是1024，这一块也可以定义成宏
    fp->size = 0;   // 当前缓冲区里没有数据，size是0
    //fp->outbuffer[0] = '\0';    // 我们把它当做字符串做的，我们这里默认这样就清空了，如果受不了这样写，可以像下面这样写
    memset(fp->outbuffer,0,sizeof(fp->outbuffer));
    return fp;  // 至此上层拿到了这个被打开的文件
}


int Myfwrite(const char *message,int size,int num,My_FILE *fp)  // 一定程度上减少系统调用次数，因为不一定所有的刷新条件都满足 --> 这个Myfwrite就是之前写的fwrite，是在进行把数据刷新到缓冲区里
{
    if(message == NULL || fp == NULL)
        return -1;
    // 向C语言文件里面写，本质是向（不是操作系统，而是）缓冲区写
    // fwrite这样的接口在我们看来90%的情况不是IO函数，而是一种拷贝函数，就好比用系统调用，比如write,
    // 用write的时候把用户数据拷贝到内核当中(也只是拷贝)，包括此时把内核中的数据(内存中)搬到了磁盘上，
    // 不也相当于一种拷贝嘛！只不过把存储到外设这个拷贝起名叫IO
    // 在计算机里面充满了大量的IO，包括未来学习网络部分的时候，把数据写到网络里面，从网络里读，
    // 其实本质上依然是从设备当中拷贝数据到内存，内存当中拷贝数据到外设，所以一切皆拷贝，
    // 当它都是拷贝时每个阶段不同的拷贝起个名字就叫IO
    // 所以向C语言文件里面写，本质是向缓冲区写，至于怎么办就不用我们管了
    int total = size * num;
    //if(total + fp->size > fp->cap)  // 没有考虑\0的问题
    if(total + fp->size > fp->cap - 1)  // 保证不会越界 --> 总容量给\0留个位置
        return -1;
    
    // 写入 --> 就相当于在进行数据拷贝 --> 核心
    memcpy(fp->outbuffer + fp->size,message,total); // 没有考虑\0的问题，保险起见就加个1，这里已经考虑到了
    fp->size +=  total;
    fp->outbuffer[fp->size] = 0;

    
    if(fp->outbuffer[fp->size - 1] == '\n' && (fp->mode & LINE_CACHE))
        Myfflush(fp);   // 如果字符串结尾是\n，并且模式是LINE(行缓冲)，就直接强制刷新

    //// fwrite判断是否刷新，这不就是刷新吗（所谓的刷新就是把数据拷贝给内存）！！！
    //if(fp->size > 0 && fp->outbuffer[fp->size - 1] == '\n' && (fp->mode & LINE_CACHE))  // 刷新条件满足时才会调用系统调用
    //{
    //    // 系统调用
    //    write(fp->fd,fp->outbuffer,fp->size);
    //    fp->size = 0;   // 清空
    //    //fp->outbuffer = 0;  // 不清空也行
    //    // printf格式化也是输出到缓冲区
    //}

    return num; // num: 一共写了多少字节
}

void Myfflush(My_FILE *fp)
{
    if(!fp)
        return;

    // fwrite判断是否刷新，这不就是刷新吗（所谓的刷新就是把数据拷贝给内存）！！！
    if(fp->size > 0) // 强制刷新，只要有数据就刷新
    {
        // 系统调用
        // 所谓的刷新就是把数据从用户缓冲区拷贝到内核
        // 像从用户缓冲区拷贝到内核这种模式叫做WB模式
        // WB: Write Back(写回)
        write(fp->fd,fp->outbuffer,fp->size);
        fp->size = 0;   // 清空
        //fp->outbuffer = 0;  // 不清空也行
        // printf格式化也是输出到缓冲区
        
        // WT模式，Write Though
        // 不仅仅要写入到内核缓冲区，还必须写到对应的硬件上
        fsync(fp->fd);  // 强度做大一点
    }   
}


void Myfclose(My_FILE *fp) // 关闭文件
{
    if(!fp)
        return;

    Myfflush(fp); // 只要有数据，无脑刷新
    close(fp->fd);  // 先刷新再关闭！先刷新，再关闭文件描述符！
}
