public class Edge <T,W>{
    private Vertex<T,W> self_ptr;
    private W weight;
    private Edge<T,W> next = null;

    /*
    Constructor. Requires a node to reference and a weight
     */
    public Edge(Vertex<T,W> _self_ptr, final W _weight){
        self_ptr = _self_ptr;
        weight = _weight;
    }

    public Edge(final Edge<T,W> obj){
        self_ptr = obj.self_ptr;
        weight = obj.weight;
    }

    public void append(final Edge new_edge){
        if (next == null)
            next = new_edge;
        else
            next.append(new_edge);
    }

    /*
    RETURNS
    null if the edge does not exist
    a copy of the weight class if it DOES exist
     */
    public final W findWeight(final Vertex<T,W> to_find){
        if (next == null)
            return null;
        else if (self_ptr.equals(to_find))
            return weight;
        else
            return next.findWeight(to_find);
    }

    /*
    RETURNS
    TRUE if this node is pointed to in this LLL of edges
    FALSE if it is not.
    This is faster than copying a new weight object
     */
    public boolean exists(final Vertex<T,W> to_find){
        if (next == null)
            return false;
        else if (self_ptr.equals(to_find))
            return true;
        else
            return next.exists(to_find);
    }


    /*
    Make a new copy of the LLL attached to new_edge and return it
     */
    public Edge<T,W> copy(){
        Edge<T,W> copy_LLL = new Edge<>(this);
        if (next == null)
            return copy_LLL;
        return next.copy(copy_LLL);
    }

    /*
    Copy the next node, if it exists into current
     */
    private Edge<T,W> copy(Edge<T,W> current){
        current.next = new Edge<>(this);
        if (next != null)
            next.copy(current.next);
        return current; //returns the head
    }

    /*
    Copy the edges in this LLL into an array
     */
    public Edge[] copyArray(Edge[] edges, int index){
        edges[index] = new Edge<T,W>(this);
        if (index >= edges.length || next == null)
            return edges;
        return next.copyArray(edges, ++index);
    }

    /*
    Clear all edges in this LLL
     */
    public void clear(){
        if (next != null) {
            next.clear();
            next = null;
        }

        weight = null;
        self_ptr = null;
    }

    public String toString(){
        StringBuilder ret = new StringBuilder("Edge: ");
        ret.append(self_ptr.toString());
        ret.append("\tWeight: ");
        ret.append(weight.toString());
        return ret.toString();
    }

}
