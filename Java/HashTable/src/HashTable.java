public class HashTable<KEY,DATA> {
    /* Array of nodes used for chaining */
    private Node[] node_array;
    private static int default_size = 256;

    HashTable(){
        node_array = new Node[default_size];
    }

    HashTable(int array_size){
        node_array = new Node[array_size];
    }

    HashTable(final HashTable<KEY,DATA> obj){
        node_array = new Node[obj.node_array.length];

        for(int i = 0; i < node_array.length; ++i) {
            node_array[i] = new Node<KEY,DATA>(obj.node_array[i]);
        }
    }

    public static void main(String[] args){
        HashTable<String, Integer> hashTable = new HashTable<String, Integer>(16);

        System.out.print(hashTable.insert("this!",100));
        System.out.print(hashTable.insert("this!",200));
        System.out.print(hashTable.insert("this!",300));
        System.out.print(hashTable.insert("that!",100));
        System.out.print(hashTable.toString());
    }

    public boolean insert(KEY k, DATA d){
        Node n = new Node<KEY,DATA>(k,d);
        int index = n.hashCode() % this.node_array.length;
        if (node_array[index] == null){
            node_array[index] = n;
            return true;
        }
        return node_array[index].insert(n);
    }

    @Override
    public String toString(){
        StringBuilder r = new StringBuilder("Array size: " + node_array.length + '\n');
        for (Node a_node : node_array) {
            if (a_node != null) {
                r.append(a_node.toString() + '\n');
            }
        }
        return r.toString();
    }

    public void clear(){
        for (Node a : node_array)
            a.clearLLL();
        node_array = null;
    }
}
