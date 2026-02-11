#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    umask(0);   // 就近原则
    int fd = open("log.txt",O_CREAT | O_WRONLY | O_TRUNC,0666); // OS本身自带的系统调用，相当于w
    if(fd < 0)  // 打开文件失败
    {
        perror("open");
        return 1;
    }
    //const char *message = "1234567890abcdefg\n";
    const char *message = "ccc";
    write(fd,message,strlen(message));

    close(fd);
    return 0;
}

//#define ONE (1<<0)   // 1
//#define TWO (1<<1)   // 2
//#define THREE (1<<2)   // 4
//#define FOUR (1<<3)   // 8
//#define FIVE (1<<4)   // 16
//
//void Print(int flags)
//{
//    if(flags & ONE)
//        printf("ONE\n");
//    if(flags & TWO)
//        printf("TWO\n");
//    if(flags & THREE)
//        printf("THREE\n");
//    if(flags & FOUR)
//        printf("FOUR\n");
//    if(flags & FIVE)
//        printf("FIVE\n");
//}
//
//int main()
//{
//    Print(ONE);
//    printf("\n");
//    Print(TWO);
//    printf("\n");
//    Print(ONE | TWO);
//    printf("\n");
//    Print(ONE | TWO | THREE);
//    printf("\n");
//    Print(ONE | TWO | THREE | FOUR);
//    printf("\n");
//    Print(TWO | THREE | FOUR | FIVE);
//}

//int main()
//{
//    //chdir("/home/Alice/118/linux-git"); // 可以修改文件新建的路径
//    //char pwd[64];
//    //getcwd(pwd, sizeof(pwd));
//    //printf("cwd: %s\n", pwd);
//
//
//    FILE *fp = fopen("log.txt", "w");
//    if(NULL == fp)
//    {
//        perror("fopen");
//        return 0;
//    }
//
//    char inbuffer[1024];
//    while(1)
//    {
//        long pos = ftell(fp);
//        printf("pos: %ld\n", pos);
//        int ch = fgetc(fp);
//        if(ch == EOF)
//        {
//            break;
//        }
//        printf("%c\n", ch);
//        //if(!fgets(inbuffer, sizeof(inbuffer), fp))
//        //{
//        //    break;
//        //}
//        printf("file : %s", inbuffer);
//    }
//
//    //const char *message = "abcd\n";
//    //fputs(message, fp);
//    ////int cnt = 0;
//    //while(cnt < 10)
//    //{
//    //    //fwrite(message, 1, strlen(message) + 1, fp);  // 文件的字符串这里不用+1，+1即算上了\0(C语言)
//    //    fputs(message, fp);
//    //    //fprintf(fp, "hello Alice: %d\n", cnt);
//    //    cnt++;
//    //}
//
//    fclose(fp);
//    return 0;
//}
