#include "worker.h"
#include <vector>
#include <mutex>

#ifndef QUEUE_
#define QUEUE_

template <typename F, typename A>
class queue : public std::vector<A>
{
    public:
        queue();
        explicit queue(F *function, std::vector<A> args);
        explicit queue(F *function, std::vector<A> args, uint workers);
        queue(const queue<F,A> &obj);
        ~queue();
        bool done();
        const std::vector<A>& start();
    protected:
    private:
        std::vector<A> finished;
        uint num_workers;
        std::mutex qlock;
        worker<F,A> *workers;

        static uint max_num_workers;
};

#include "queue.cpp"
#endif //QUEUE_
