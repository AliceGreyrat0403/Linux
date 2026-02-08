#include "my_stdio.h"
#include <string.h>
#include <unistd.h>

int main()
{
    My_FILE *fp = Myfopen("log.txt","a"); // 相当于把这个log.txt当显示器了
    if(!fp) // 打开文件失败或者底层malloc失败
        return 1;

    int cnt = 10;
    //const char *msg = "hello world \n";
    const char *msg = "hello world ";
    while(cnt--)
    {
        Myfwrite(msg,1,strlen(msg),fp); // 模拟缓存的行为
        Myfflush(fp);
        sleep(2);
    }

    Myfclose(fp);

    return 0;
}
