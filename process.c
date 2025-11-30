#include "process.h"
#include <string.h>
#include <unistd.h>

#define SIZE 102
#define LABLE '='

void Process(double total, double current, double speed, const char *userinfo)
{
    if(current > total)
        return;

    // 旋转光标和下载本身有关吗? Process函数是否被调用有关
    static const char *lable="|/-\\";
    static int index = 0;
    int size = strlen(lable);
    // 绝对不能一次循环就把整个进度推荐完毕
    // 1. 计算比率, 10.4
    double rate = current*100.0/total; // 65.0 / 100.0 = 0.65 * 100.0 = 65.0
    char out_bar[SIZE];
    memset(out_bar, '\0', sizeof(out_bar));
    // 2. 填充进度字符
    int i = 0;
    for(; i < (int)rate; i++)
    {
        out_bar[i] = LABLE;
    }
    // 3. 刷新进度条
    printf("[%-100s][%5.1lf%%][%c] | %.1lf/%.1lf,speed: %.1lf%s\r",\
            out_bar, rate, lable[index], total, current, speed, userinfo);
    fflush(stdout);
    index++;
    index %= size;

    // 4. 进度条完成,换行
    if(current >= total)
        printf("\r\n");
}


// 进度条的version1版本
void ProcessVersion()
{
    const char *lable="|/-\\";
    int len = strlen(lable);
    int cnt = 0;
    char out_bar[SIZE];
    memset(out_bar, '\0', sizeof(out_bar));
    while(cnt<=100)
    {
        printf("[%-100s][%3d%%][%c]\r", out_bar, cnt, lable[cnt%len]);
        fflush(stdout);
        out_bar[cnt] = LABLE;
        cnt++;

        usleep(30000);
    }

    printf("\r\n");
}

//void Process()
//{
//    const char *lable[] = {
//        "load.",
//        "load..",
//        "load...",
//    };
//    int size = sizeof(lable)/sizeof(lable[0]);
//    int cnt = 0;
//    char out_bar[SIZE];
//    memset(out_bar, '\0', sizeof(out_bar));
//    while(cnt<=100)
//    {
//        printf("[%-100s][%3d%%][%-7s]\r", out_bar, cnt, lable[cnt%size]);
//        fflush(stdout);
//        out_bar[cnt] = LABLE;
//        cnt++;
//
//        usleep(1000000);
//    }
//
//    printf("\r\n");
//}

