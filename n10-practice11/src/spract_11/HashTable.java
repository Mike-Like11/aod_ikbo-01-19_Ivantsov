package spract_11;

import java.util.*;

public class HashTable<V,E> {
    int size=10;
   ArrayList<LinkedList<E>>a;

    public HashTable(int size) {
        this.size = size;
        this.a=new ArrayList<LinkedList<E>>(this.size);
        for(int i=0;i<10;i++){
            a.add(new LinkedList<E>());
        }

    }

    int hash(int value){
        return (int)value%size;
    }
    int hash(E n) {
        Polic c= (Polic) n;
        return c.inn % size;
    }
   void add(  E b) {
       a.get(hash(b)).addLast(b);
       if (a.get(hash(b)).size() > 3) rehash();
    }
    void rehash(){
       ArrayDeque<E>t=new ArrayDeque<>();
        for (int i = 0; i < size; ++i) {
            for (E el : a.get(i)) {
                t.add(el);
            }
        }
        size = size * 2 + 1;
        a.clear();
        a=new ArrayList<LinkedList<E>>(size);
        for(int i=0;i<size;i++){
            a.add(new LinkedList<E>());
        }
        while (!t.isEmpty()) {
            add(t.getFirst());
            t.pop();
        }

    }
    void search(int value){
        for(E t:a.get(hash(value))){
            Polic c= (Polic) t;
            if(c.inn == value){
                System.out.println(c);
            }
        }
    }
    void delete(int value){
        for(E t:a.get(hash(value))){
            Polic c= (Polic) t;
            if(c.inn == value){
                a.get(hash(value)).remove(t);
            }
        }
    }
    void printik(){
        for(int i=0;i<size;i++){
            if(!a.get(i).isEmpty()) {
                System.out.println(i+" : ");
                for (int j = 0; j < a.get(i).size(); j++) {
                    System.out.println("\t"+a.get(i).get(j));
                }
            }
        }
    }
}
