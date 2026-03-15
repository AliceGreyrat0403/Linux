#include "Shm.hpp"

#include <iostream>
#include "string"

int main()
{
    Shm shm;
    // 这里不能创建共享内存，创建了就不能建立进程间通信的信道了
    shm.Get();
    shm.Debug();

    return 0;
}