

#ifndef VERTEX_
#define VERTEX_

template<class T>
class Edge;

template<class T>
class Vertex
{
    public:
        Vertex();
        Vertex(const Vertex<T> &obj);
        ~Vertex();
        bool Connect(Vertex<T> &obj, bool direction=true);
        bool Conneced(Vertex<T> &obj) const;
    protected:
    private:
        T *data;
        Edge<T> *head;
};

#include "vertex.cpp"

#endif //VERTEX_
