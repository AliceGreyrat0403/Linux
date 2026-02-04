#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[128];   // 缓冲区
    const char *msg = "linux so easy!";
    
    // 打开文件（不存在就创建），并且写入内容
    // 创建文件流对象
    FILE *fp = fopen("bite","w+");
    if(fp == NULL)
    {
        printf("文件打开失败!\n");
        return 1;
    }

    // 写入msg
    size_t message = fwrite(msg,1,strlen(msg),fp);
    if(message != strlen(msg))
    {
        printf("写入文件失败!\n");
        fclose(fp);
        return 1;
    }

    // 将文件指针移到开头，读取文件
    fseek(fp,0,SEEK_SET);
    
    // 从文件中读取
    size_t read_count = fread(buffer,1,strlen(msg),fp);
    if(read_count != strlen(msg))
    {
        printf("文件读取失败!\n");
        fclose(fp);
        return 1;
    }

    // 手动添加\0
    buffer[read_count] = '\0';
    
    // 打印到stdout
    printf("文件的内容: %s\n",buffer);

    // 关闭文件流指针
    fclose(fp);

    return 0;
}

