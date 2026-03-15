#include <iostream>
#include <cstdio>   // 混编
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "comm.h"

int main()
{
    std::cout << "open begin" << std::endl;

    // int wfd = open(fifoname.c_str(),O_WRONLY);
    int wfd = open("fifo", O_WRONLY);
    if(wfd < 0)
    {
        perror("open");
        return 1;
    }
    std::cout << "open end" << std::endl;

    std::string outstring;
    while(true)
    {
        std::cout << "Please Enter@ ";
        std::cin >> outstring;

        write(wfd,outstring.c_str(),outstring.size());  // 要不要写\0？不需要写！
    }

    close(wfd);

    return 0;
}
