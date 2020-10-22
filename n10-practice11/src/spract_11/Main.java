package spract_11;

public class Main {

    public static void main(String[] args) {
	// write your code here
        HashTable<Polic> ht=new HashTable<>(10);
        ht.add(new Polic(123,"samsung","ivantsov"));
        ht.add(new Polic(1005,"apple","ivantsov2"));
        ht.add(new Polic(5,"yandex","ivantsov3"));
        ht.add(new Polic(2005,"google","ivantsov4"));
        ht.add(new Polic(3005,"sberbank","ivantsov5"));
        ht.printik();
        System.out.println("\n");
        ht.search(1005);
        System.out.println("\n");
        ht.delete(1005);
        System.out.println("\n");
        ht.printik();
    }
}
