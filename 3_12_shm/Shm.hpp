#ifndef __SHM_HPP
#define __SHM_HPP

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/shm.h>
#include <string> 

const std::string proj_name = "/home";  // 工作路径，可以随机，最好是系统存在的路径
const int proj_id = 0x6666;    // 项目ID
const int g_size = 4096;    // g_size：global size

// 转成十六进制
static std::string ToHex(int data)  
{
    char hex[64];
    snprintf(hex,sizeof(hex),"0x%x",data);
    return hex;
}

class Shm
{
public:
    // 构造函数和析构函数
    Shm(int size = g_size)  : _shmid(-1),_size(size),_key(0)
    {}
    ~Shm()  {}

private:
    key_t GetKey()
    {
        _key = ftok(proj_name.c_str(),proj_id);
        if(_key < 0)
        {
            perror("ftok");
        }
        return _key;
    }

    bool CreateCoreHelper(int flags)
    {
        // 1.获取key值
        key_t k = GetKey();
        // 2.创建共享内存
        _shmid = shmget(k,_size,flags);
        if(_shmid < 0)
        {
            perror("shmget");
            return false;
        }
        return true;
    }

public:
    // 1.创建
    bool Create()
    {
        return CreateCoreHelper(IPC_CREAT | IPC_EXCL | 0666);
    }
    // 2.获取共享内存
    bool Get()
    {
        return CreateCoreHelper(IPC_CREAT);
        // return CreateCoreHelper(0);
    }
    // 3.删除共享内存
    bool Delete()
    {
        int n = shmctl(_shmid,IPC_RMID,NULL);
        return n < 0 ? false : true;
    }
    // 4.保存共享内存属性
    void GetShmAttr()
    {
        struct shmid_ds ds;
        int n = shmctl(_shmid,IPC_STAT,&ds);
        if(n < 0)
        {
            perror("shmctl");
            return;
        }
        std::cout << "pid: " << getpid() << std::endl;  // 当前进程的 PID - 显示调用此函数的进程 ID

        // 创建共享内存的进程 PID - shm_cpid 是创建该共享内存段的进程 ID
        std::cout << ds.shm_cpid << std::endl;
        
        // 共享内存段的大小（字节） - shm_segsz 表示共享内存的大小，单位是字节
        std::cout << ds.shm_segsz << std::endl;

        // 共享内存的 key 值（十六进制） 
        // - shm_perm.__key 是共享内存的键值，通过 ToHex 函数转换为十六进制显示
        std::cout << ToHex(ds.shm_perm.__key) << std::endl;
    }
    // 挂接
    void *Attach()
    {
        return shmat(_shmid,nullptr,0);
    }
    // Debug
    void Debug()
    {
        std::cout << "key: " << ToHex(_key) << std::endl;
        std::cout << "shmid: " << _shmid << std::endl;
    }

private:
    key_t _key;
    int _shmid;
    int _size;
};

#endif