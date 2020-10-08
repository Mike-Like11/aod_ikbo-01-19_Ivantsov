package spract_11;

public class Main {

    public static void main(String[] args) {
	// write your code here
        HashTable<Integer,Polic> ht=new HashTable<>();
        ht.add(123,new Polic(123,"samsung","ivantsov"));
        ht.add(1005,new Polic(1005,"samsung","ivantsov2"));
        ht.add(5,new Polic(5,"samsung3","ivantsov3"));
        ht.printik();
        ht.search(1005);
        ht.delete(1005);
    }
}
