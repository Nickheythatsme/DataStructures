#include <iostream>
#include <thread>
#include <cstring>

#ifndef WORKER_
#define WORKER_

#define POOL_SIZE 10

#define ERROR_RUNNING 0x10
#define NO_ARGS       0x20
#define NO_FUNC       0x30

/* Queue error class. It is thrown everytime something bad happens */
struct queue_error
{
    queue_error() = delete;
    explicit queue_error(int code);
    queue_error(const queue_error &obj) = default;
    friend std::ostream& operator<<(std::ostream& out, const queue_error &obj);

    int code;
};

template <typename F, typename A>
class worker
{
    public:
        worker() = delete;
        explicit worker(F *function);
        worker(const worker &obj);
        ~worker();
        void run(A *args);
        bool running();
    protected:
    private:
        void _run(A *args);
        bool _running;
        F *func;
        std::thread t;
};

#include "worker.cpp"
#endif //WORKER_
