#include <iostream>
#include <functional>

using namespace std;

#define __MAIN__

///////////////// 任务测试代码 ///////////////////


/////////////////// 进程池代码 ////////////////////


class ProcessPool
{
private:
    int Next()
    {}

public:
    ProcessPool(int number) : _number(number),+_next_choice(0)
    {
        cout << "number: " << _number << endl;
    }
    // 父进程
    void Start()
    {}
    // 1.什么任务？任务码决定
    // 2.任务给谁？属于进程池内部操作，负载均衡
    void PushTask(int taskcode)
    {}

    void Stop()
    {}

    void DebugPrint()
    {
        cout << "-----------------------------" << std::endl;
        for(auto &channel : _channels)
        {
            cout << channel.Fd() << endl;
            cout << channel.SubId() << endl;
            cout << channel.Name() << endl;
        }
        cout << "-----------------------------" << endl;
    }
    ~ProcessPool() {}

private:
    vector<Channel> _channels;
    int_number;
    int _next_choice;
};


// 父进程

#ifdef __MAIN__

static void Usage(const string &proc)
{
    cout << "Usage:\n\t" << proc << "process_number" << endl;
}

// ./process_pool 5
int main()
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }
    int number = stoi(argv[1]);
    // 0. 加载任务
    srand(time(nullptr) ^ getpid());
    LoadTask();
    vectror<int> task_codes;
    RandomTask(&task_codes);

    // 1。创建进程池对象
    unique_ptr<ProcessPool> pp = make_unique<ProcessPool>(number);
    // 2、启动进程池
    pp->Start();
    sleep(2);
    // for(auto task : task_codes)
    // {
    //     pp->PushTask(task);
    //     usleep(500000);
    // }

    // while(true)
    // {
    //     int code = 0;
    //     cout << "Please Enter Your Task# ";
    //     cin >> code;
    //     if(code < 0 || code > gtasks.size())
    //     {
    //         cout << "任务码错误，请重新输入" << endl;
    //         continue;
    //     }

    //     pp->PushTask(code);
    // }

    pp->Stop();
    return 0;
}

#endif