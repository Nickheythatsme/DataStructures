import java.util.LinkedList;
import java.util.List;

public class Graph <T,W> {
    private List<Vertex<T,W>> vertices = new LinkedList<>();


    public Graph(){
    }

    public static void main(String [] args){
        Graph<String, Integer> graph = new Graph<>();
    }

    public int size() {
        return 0;
    }

    public boolean isEmpty() {
        return vertices.isEmpty();
    }

    public Vertex<T,W> get(T key) {
        for (Vertex<T, W> vertex : vertices)
            if (vertex.equals(key))
                return vertex;
        return null;
    }

    public Vertex<T,W> get(Vertex<T,W> key){
        for (Vertex<T, W> vertex : vertices)
            if (vertex.equals(key))
                return vertex;
        return null;
    }

    public boolean contains(T key){
        for (Vertex<T, W> vertex : vertices)
            if (vertex.equals(key))
                return true;
        return false;
    }

    public boolean addVertex(final Vertex<T,W> vertex) {
        return vertices.add(vertex);
    }

    public boolean addEdge(final T source, final T dest, W weight){
        Vertex<T,W> source_original = get(source);
        Vertex<T,W> dest_original = get(dest);

        if (source_original == null) {
            source_original = new Vertex<>(source);
            vertices.add(source_original);
        }

        if (dest_original == null) {
            dest_original = new Vertex<>(dest);
            vertices.add(dest_original);
        }

        source_original.addEdge(dest_original,weight);
        dest_original.addEdge(source_original,weight);
        return true;
    }

    public boolean remove(final Vertex<T,W> vertex) {
        return vertices.remove(vertex);
    }

    public void clear() {
        vertices.clear();
    }

}
