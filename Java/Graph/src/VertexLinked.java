public class VertexLinked <T,W> extends Vertex<T,W>{
    VertexLinked<T,W> next = null;
    VertexLinked<T,W> prev = null;

    public VertexLinked(final T _t){
        super(_t);
    }

    public VertexLinked(final VertexLinked<T,W> obj){
        super(obj);
    }

}
