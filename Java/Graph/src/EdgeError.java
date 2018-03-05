public class EdgeError extends Exception{
    private String message = null;
    private Vertex source = null;
    private Vertex dest = null;

    public EdgeError(){
        message = "Unknown EdgeError";
    }

    public EdgeError(String _message){
        message = _message;
    }

    public EdgeError(String _message, Vertex _source){
        message = _message;
        source = _source;
    }

    public EdgeError(String _message, Vertex _source, Vertex _dest){
        message = _message;
        source = _source;
        dest = _dest;
    }

    public String toString(){
        StringBuilder ret = new StringBuilder("EdgeError: ");
        if (message != null) {
            ret.append("\n\t\"");
            ret.append(message);
            ret.append("\"\n\t");
        }
        if (source != null){
            ret.append("\n\t\"");
            ret.append(source.toString());
            ret.append("\"\n\t");
        }
        if (dest != null){
            ret.append("\n\t\"");
            ret.append(dest.toString());
            ret.append("\"\n\t");
        }
        return ret.toString();
    }
}
