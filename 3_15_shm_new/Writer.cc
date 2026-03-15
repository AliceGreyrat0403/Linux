#include "Shm.hpp"

#include <iostream>
#include <string>
#include <string.h>

Shm shm;

class Init  // 定义结构体
{
public:
    Init()
    {
        shm.Get();
        addr = (char*)shm.Attach();
        std::cout << "addr: " << ToHex((long long)addr) << std::endl;
    }
    // 析构函数
    ~Init()
    {
        shm.Detach();
    }
    char *Addr()
    {
        return addr;
    }
public:
    char* addr;
};

Init init;

int main()
{
    std::cout << "test Begin..." << std::endl;

    buffer_t *shm = (buffer_t*)init.Addr();
    shm->count = 0;
    memset(shm->buffer,0,4096);

    char ch = 'A';
    for(int i = 0;i < 26*2;i += 2,ch++)
    {
        // ?
        shm->buffer[i] = ch;
        // ?
        usleep(2000000);
        shm->buffer[i + 1] = ch;
        usleep(7000000);
        // ?
        shm->count++;
        usleep(7000000);

        sleep(1);
    }

    return 0;
}