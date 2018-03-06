
/*
T is for the data type
W is for the weight, which can represent different weights or classes of weights
*/
public class Vertex<T,W>{
    private T t;
    private Edge<T,W> edges = null;
    private int count = 0;

    public Vertex(final T _t) {
        t = _t;
    }

    public Vertex(final Vertex<T,W> vertex){
        if (vertex.edges != null)
            edges = vertex.edges.copy();
        count = vertex.count;
        t = vertex.t;
    }

    public static void main(String [] args){
        Vertex<String,Integer> vertex1 = new Vertex<>("One!");
        Vertex<String,Integer> vertex2 = new Vertex<>("Two");

        vertex1.addEdge(vertex2,2);
        vertex1.addEdge(new Vertex<String,Integer>("Three!"),3);

        Edge edges[] = vertex1.getEdges();
        for (Edge edge : edges)
            System.out.print(edge.toString() + '\n');

        Vertex<String, Integer> copy1 = new Vertex<>(vertex1);

        edges = copy1.getEdges();
        for (Edge edge : edges)
            System.out.print(edge.toString() + '\n');

        vertex2.clear();
        vertex1.clear();

    }

    /*
    Add an already made edge to this node
    */
    private void addEdge(Edge<T,W> new_edge){
        if (edges == null)
            edges = new_edge;
        else
            edges.append(new_edge);
        ++count;
    }

    /*
    Add an edge to this node with a weight
     */
    public void addEdge(final Vertex<T,W> new_vertex, final W weight){
        Edge<T,W> new_edge = new Edge<>(new_vertex, weight);
        this.addEdge(new_edge);
    }

    /*
    Returns
    weight of the edges between these two nodes
    THROWS
    edge does not exist error if these nodes are not connected
     */
    public final W findWeight(final Vertex<T,W> to_find) throws EdgeError{
        W weight = edges.findWeight(to_find);
        if (weight == null)
            throw new EdgeError("Edge does not exist",this,to_find);
        return weight;
    }

    /*
    Returns
    TRUE if these nodes are connected.
    FALSE if these nodes are NOT connected
     */
    public boolean connected(final Vertex<T,W> to_find) throws EdgeError{
        if (edges == null)
            throw new EdgeError("No edges connected to node: ", this);
        return edges.exists(to_find);
    }

    public final T getData(){
        return t;
    }

    /*
    Returns the edges attached to this node
    */
    public Edge[] getEdges(){
        if (edges == null)
            return null;
        Edge[] edges_array = new Edge[count];

        return edges.copyArray(edges_array, 0);
    }


    /*
    Return the count of edges attached to this node
     */
    public int getCount(){
        return count;
    }

    /*
    Standard Java methods
     */
    @Override
    public String toString(){
        return t.toString();
    }

    public boolean equalsData(final T obj){
        return obj.equals(t);
    }


    public boolean equals(final Vertex<T,W> obj){
        return obj.t.equals(this.t);
    }

    @Override
    public int hashCode(){
        return t.hashCode();
    }

    /*
    Clear all edges attached to this node
     */
    public void clear(){
        if (edges != null) {
            edges.clear();
            edges = null;
        }
    }
}
