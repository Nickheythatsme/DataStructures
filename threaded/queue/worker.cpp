#include "worker.h"

// CONSTRUCTOR
template <typename F, typename A>
worker<F,A>::worker() 
{
}

template <typename F, typename A>
worker<F,A>::worker(F *function)
{
    func = function;
}

// COPY CONSTRUCTOR
template <typename F, typename A>
worker<F,A>::worker(const worker &obj)
{
    func = obj.func;
}

// DESTRUCTOR
template <typename F, typename A>
worker<F,A>::~worker()
{
    if(t.joinable())
        t.join();
}

// Launch a thread for the target function and the given arguments
template <typename F, typename A>
void worker<F,A>::run(A *args)
{
    if(t.joinable())
        throw err_running(ERROR_RUNNING);
    t = std::thread(func, args);
}

// Return false if not running, true if it is running
template <typename F, typename A>
bool worker<F,A>::running()
{
    return t.joinable();
}

/* ERROR STRUCT FUNCTIONS */
err_running::err_running(int _code)
{
    code = _code;
}

std::ostream& operator<<(std::ostream& out, const err_running &obj)
{
    out << "ERROR: ";
    switch(obj.code)
    {
        case ERROR_RUNNING:
            out << "thread already running";
            break;
        default:
            out << "unknown error";
            break;
    }
    return out;
}
