#include <ostream>
#include <thread>
#include <cstring>
#include <vector>

#ifndef WORKER_
#define WORKER_

#define POOL_SIZE 10
#define ERROR_RUNNING 0x10

struct err_running
{
    err_running() = delete;
    explicit err_running(int code);
    err_running(const err_running &obj) = default;
    friend std::ostream& operator<<(std::ostream& out, const err_running &obj);

    int code;
};

template <typename F, typename A>
class worker
{
    public:
        worker();
        explicit worker(F *function);
        worker(const worker &obj);
        ~worker();
        void run(A *args);
        bool running();
    protected:
    private:
        F *func;
        std::thread t;
};

#include "worker.cpp"
#endif //WORKER_
