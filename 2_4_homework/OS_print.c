#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // 设置程序掩码
    umask(0);

    // 缓冲区
    char buffer[128];
    // 文件描述符
    int fd = open("bite",O_CREAT | O_RDWR | O_TRUNC,0666);
    const char* msg = "i like linux!";
    // 直接算出消息内容的长度
    size_t len_msg = strlen(msg);

    if(fd < 0)  // 打开失败
    {
        perror("open");
        return 1;
    }

    // 写入
    // 直接这里算一下写入的字节数
    ssize_t byte_write = write(fd,msg,len_msg);
    if(byte_write != len_msg)
    {
        perror("write");
        close(fd);
        return 1;
    }

    // 将文件指针移到开头
    if(lseek(fd,0,SEEK_SET) < 0)    // 移动失败
    {
        perror("lseek");
        return 1;
    }

    // 读取
    // 直接这里算一下读入的字节数
    ssize_t byte_read = read(fd,buffer,len_msg);
    if(byte_read != len_msg)
    {
        perror("read");
        return 1;
    }

    // 手动添加\0
    buffer[byte_read] = '\0';

    // 打印到stdout
    printf("文件内容: %s\n",buffer);

    // 关闭文件描述符
    // fflush(fd);
    close(fd);

    return 0;
}

//#include <string.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//
//int main()
//{
//    // 根据就近原则，设置权限掩码
//    umask(0);
//    // 创建文件流，以写方式打开文件(不存在就新建)
//    FILE *fp = open("bite",O_CREAT | O_WRONLY | O_TRUNC,0666);
//    const char *msg = write(fd,buffer,count);
//
//    return 0;
//}
