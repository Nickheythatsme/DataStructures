public class Node<KEY, DATA>{
    /* Store the key which will be used for the hash code */
    private KEY  key   = null;
    private DATA data = null;

    /* Pointer to the next node in case we have to use chaining */
    private Node next = null;

    /* The hcode. Nodes in the chained LLL will be sorted based on the hcode */
    private int hcode = 0;

    // CONSTRUCTOR
    Node(KEY new_key, DATA new_data){
        key = new_key;
        data = new_data;
        hcode = new_key.hashCode();
    }

    // COPY CONSTRUCTOR
    Node(final Node<KEY,DATA> obj){
        hcode = obj.hcode;
        key = obj.key;
        data = obj.data;

        // We don't want to copy all the linear linked list.
        next = null;
    }

    @Override
    public String toString() {
        String r = '(' + key.toString() + ':' + data.toString() + ')';
        if(next != null)
            return r + ", " + next.toString();
        return r;
    }

    @Override
    public int hashCode(){
        return hcode;
    }

    /* Clear the LLL of nodes. This speeds up garbage collection */
    public void clearLLL(){
        if(next != null)
            next.clearLLL();
        next = null;
    }

    /*
    Insert a new node in sorted order into the LLL
    higher codes go from least to greatest
     */
    public boolean insert(Node<KEY,DATA> new_node){
        if(data == null) {
            data  = new_node.data;
            key   = new_node.key;
            hcode = new_node.hcode;
            return true;
        }
        if(next == null){
            next = new_node;
            return true;
        }
        if(next.hcode >= new_node.hcode){
            new_node.next = next;
            next = new_node;
            return true;
        }
        return next.insert(new_node);
    }

    public Node<KEY,DATA> Next(){
        return next;
    }
}
