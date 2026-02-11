#include"process.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

// 有一个下载任务
double gtotal = 1024.0;	// 目标文件的总大小
double gspeed = 1.0;    // 下载时的网络速度

// 回调函数
void Download(double total,flush_t cb)
{
    double level[] = {0.5,1.0,2.0,5.0,10.0,20.0,30.0,30.0,40.5,80.5};
    int num = sizeof(level) / sizeof(level[0]);

    double current = 0.0;   // 当前下载了多少
    while(1)
    {    
        usleep(100000);    // 模拟下载，单位微秒
        double speed = level[rand()%num];   // 随机网速
        current += speed;
        if(current >= total)
        {
            current = total;
            cb(total,current,speed,"MB/s"); // 更新进度条
            break;
        }
        else{
            cb(total,current,speed,"MB/s"); // 更新进度条
        }
    }
}

// 添加进度条色块

int main()
{
    //// version
    // Process();  // 进度条程序

    srand(time(NULL));
    // 多个不同大小程序的下载
    printf("download：\n");
    Download(gtotal,Process);

    printf("download：\n");
    Download(120.0,Process);

    printf("download：\n");
    Download(11.8,Process);

    printf("download：\n");
    Download(78.9,Process);

    printf("download：\n");
    Download(900.0,Process);

    return 0;
}
