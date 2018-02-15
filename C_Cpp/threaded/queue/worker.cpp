#include "worker.h"
template <typename F, typename A>
worker<F,A>::worker()
{
    func = nullptr;
    _running = false;
}

// CONSTRUCTOR
template <typename F, typename A>
worker<F,A>::worker(F *function)
{
    func = function;
    _running = false;
}

// COPY CONSTRUCTOR
template <typename F, typename A>
worker<F,A>::worker(const worker &obj)
{
    func = obj.func;
    _running = false;
}

// DESTRUCTOR
template <typename F, typename A>
worker<F,A>::~worker()
{
    if(t.joinable())
        t.join();
}

template <typename F, typename A>
worker<F,A>& worker<F,A>::operator=(const worker<F,A>& obj)
{
    func = obj.func;
    _running = false;
}

// Launch a thread for the target function and the given arguments
template <typename F, typename A>
void worker<F,A>::run(A *args)
{
    if(t.joinable())
        t.join();

    if( _running )
        throw queue_error(ERROR_RUNNING);

    _running = true;
    t = std::thread(&worker::_run, this, args);
}

// Private run function. It is run on it's own thread
template <typename F, typename A>
void worker<F,A>::_run(A *args)
{
    func(*args);
    _running = false;
}

// Return false if not running, true if it is running
template <typename F, typename A>
bool worker<F,A>::running()
{
    return _running;
}

// Set the function that is to be called by this worker 
template <typename F, typename A>
void worker<F,A>::set_func(F *_function)
{
    func = _function;
}

/* QUEUE ERROR FUNCTIONS */
queue_error::queue_error(int _code)
{
    code = _code;
}

// Output the error to an ostream
std::ostream& operator<<(std::ostream& out, const queue_error &obj)
{
    out << "ERROR: ";
    switch(obj.code)
    {
        case ERROR_RUNNING:
            out << "thread already running";
            break;
        case NO_ARGS:
            out << "no arguments to run";
            break;
        case NO_FUNC:
            out << "no function to run arguments";
            break;
        default:
            out << "unknown error";
            break;
    }
    return out;
}

