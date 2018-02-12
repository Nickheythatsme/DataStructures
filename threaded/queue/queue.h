#include <thread>
#include <mutex>
#include <vector>

#ifndef QUEUE_
#define QUEUE_

template <class T>
class queue
{
    public:
        queue();
        queue(const queue &obj);
        ~queue();
    protected:
    private:
        std::mutex qlock;
        std::vector<T> top;
};

#endif //QUEUE_
