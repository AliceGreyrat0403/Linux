#include <iostream>
#include <cstdio>   // 混编
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "comm.h"

int main()
{
    // 1.创建管道文件
    umask(0);   // 关闭系统的权限，用我们指定的权限
    int n = mkfifo(fifoname.c_str(),0666);  // 系统调用mkfifo
    if(n < 0)
    {
        if(errno != EEXIST)
        {
            perror("mkfifo");
            return 1;
        }
        // 文件已存在，忽略错误，继续执行
    }

    // 2.打开管道文件
    std::cout << "open begin" << std::endl;
    int rfd = open(fifoname.c_str(),O_RDONLY);
    if(rfd < 0)
    {
        perror("open");
        return 2; 
    }

    std::cout << "open end" << std::endl;

    char inbuffer[1024];

    // 3、进行通信
    while(true)
    {
        ssize_t n = read(rfd,inbuffer,sizeof(inbuffer) - 1);
        if(n > 0)
        {
            inbuffer[n] = 0;
            std::cout << "client say# " << inbuffer << std::endl;
        }
        else if(n == 0)
        {
            // 写端关闭了
            break;
        }
        else{
            perror("read");
            break;
        }
    }

    // 4.关闭
    close(rfd);

    // 5.删除管道文件
    unlink(fifoname.c_str());

    return 0;
}
