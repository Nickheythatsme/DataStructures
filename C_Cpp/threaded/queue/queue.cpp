#include "queue.h"

template <typename F, typename A>
uint queue<F,A>::max_num_workers = std::thread::hardware_concurrency();

// CONSTRUCTOR
template <typename F, typename A>
queue<F,A>::queue() : 
    std::vector<A>(),
    finished()

{
    workers = nullptr;
    num_workers = 0;
}

// COPY CONSTRUCTOR
template <typename F, typename A>
queue<F,A>::queue(const queue &obj) : 
    std::vector<A>(obj),
    finished(obj.finished)
{
    num_workers = obj.num_workers;
    workers = new worker<F,A>[obj.num_workers];
    for(auto i = 0; i < num_workers; ++i)
        workers[i] = obj.workers[i];
}

// CONSTRUCTOR with arguments
template <typename F, typename A>
queue<F,A>::queue(F *function, std::vector<A> args) : 
    std::vector<A>(args),
    finished()
{
    num_workers = max_num_workers;
    workers = new worker<F,A>[num_workers];
    for(auto i = 0; i < num_workers; ++i)
        workers[i] = worker<F,A>(function);
}

// CONSTRUCTOR with arguments
template <typename F, typename A>
queue<F,A>::queue(F *function, std::vector<A> args, uint _num_workers) :
    std::vector<A>(args),
    finished()
{
    num_workers = _num_workers;
    workers = new worker<F,A>[num_workers];
    for(auto i = 0; i < num_workers; ++i)
        workers[i] = worker<F,A>(function);
}

// DESTRUCTOR
template <typename F, typename A>
queue<F,A>::~queue()
{
    if (workers)
        delete [] workers;
}

// Return TRUE if all the workers are NOT running
template <typename F, typename A>
bool queue<F,A>::done()
{
    int done = 0;
    for(uint i = 0; i < num_workers; ++i)
        done += workers[i].running() == false;
    return done == num_workers;
}

// Start processing every argument in the vector
template <typename F, typename A>
const std::vector<A>& queue<F,A>::start()
{
    std::lock_guard<std::mutex> g(qlock);

    // Used for indexing the workers
    uint i = 0;
    uint current = 0;

    // While there's still arguments to use, call the workers
    while(std::vector<A>::size() != 0)
    {
        i = current % num_workers;
        if( !workers[i].running() )
        {
            printf("calling worker: %d (%d items left)\n",i,std::vector<A>::size());
            auto element = std::vector<A>::back();
            finished.emplace_back(element);
            std::vector<A>::pop_back();
            workers[i].run(&element);
        }
        ++current;
    }

    // Wait until all threads are done
    while(!done())
        continue;
    printf("Returning\n");
    return finished;
}

template <typename F, typename A>
uint queue<F,A>::worker_count() const
{
    return num_workers;
}
