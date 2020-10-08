package spract_11;

public class Main {

    public static void main(String[] args) {
	// write your code here
        HashTable<Integer,Polic> ht=new HashTable<>(10);
        ht.add(new Polic(123,"samsung","ivantsov"));
        ht.add(new Polic(1005,"samsung","ivantsov2"));
        ht.add(new Polic(5,"samsung3","ivantsov3"));
        ht.add(new Polic(2005,"samsung3","ivantsov4"));
        ht.add(new Polic(3005,"samsung3","ivantsov5"));
        ht.printik();
        System.out.println("\n");
        ht.search(1005);
        System.out.println("\n");
        ht.delete(1005);
        System.out.println("\n");
        ht.printik();
    }
}
