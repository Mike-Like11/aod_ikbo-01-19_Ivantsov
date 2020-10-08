package spract_11;

import java.util.ArrayList;

public class HashTable<V,E> {
    int size=1000;
    ArrayList<E>[]a=new ArrayList[1000];
    int hash( V value){
        return (int)value%size;
    }
    void add( V value, E b) {
        if(a[hash(value)]==null) {
            a[hash(value)]=new ArrayList<E>();
        }
        a[hash(value)].add(b);
    }
    void search(V value){
        System.out.println(a[hash(value)]);
    }
    void delete(V value){
        a[hash(value)]=null;
    }
    void printik(){
        for(int i=0;i<1000;i++){
            if(a[i]!=null) {
                System.out.println(i+" : ");
                for (int j = 0; j < a[i].size(); j++) {
                    System.out.println("\t"+a[i].get(j));
                }
            }
        }
    }
}
