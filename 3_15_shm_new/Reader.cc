#include "Shm.hpp"
#include <iostream>
#include <string>
#include "unistd.h"
// 信号
#include<signal.h>

// Writer -> shm -> Reader
int main()
{
    // 1.在内核中创建共享内存
    Shm shm;    
    shm.Create();   // 这一步才是创建
    sleep(100);
    char* addr = (char*)shm.Attach();

    buffer_t *shm_addr = (buffer_t*)addr;
    int old = shm_addr->count;
    while(true)
    {
        if(old != shm_addr->count)
        {
            std::cout << "count : " << shm_addr->count << std::endl;
            std::cout << "data : " << shm_addr->buffer << std::endl;
            old = shm_addr->count;
        }

        usleep(50000);

        if(shm_addr->count >= 26)
            break; 
    }

    // sleep(3);

    // shm.Attach();

    // shm.Debug();
    // shm.GetShmAttr();

    // sleep(5);

    shm.Detach();
    shm.Delete();

    return 0;
}