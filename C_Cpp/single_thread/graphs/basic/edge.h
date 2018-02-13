#include "vertex.h"

#ifndef EDGE_
#define EDGE_

template<class T>
class Edge
{
    public:
        Edge(Vertex<T>* base);
        Edge(const Edge<T> &obj);
        ~Edge();
    protected:
    private:
        Vertex<T> *base;
        Edge<T> *next;
};

#endif //EDGE_
