package spract_11;

import java.util.*;

public class HashTable<E> {
    int size;
   ArrayList<LinkedList<E>>a;

    public HashTable(int size) {
        this.size = size;
        this.a=new ArrayList<>(this.size);
        for(int i=0;i<size;i++){
            a.add(new LinkedList<E>());
        }
    }

    int hash(int value){
        return value%size;
    }
    int hash(E n) {
        Polic c= (Polic) n;
        return c.number % size;
    }
   void add(  E b) {
       a.get(hash(b)).addLast(b);
       System.out.println("Index of added element : "+hash(b));
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
        a=new ArrayList<>(size);
        for(int i=0;i<size;i++){
            a.add(new LinkedList<E>());
        }
        System.out.println("New indexes after rehash:");
        while (!t.isEmpty()) {
            add(t.getFirst());
            t.pop();
        }


    }
    void search(int value){
        for(E t:a.get(hash(value))){
            Polic c= (Polic) t;
            if(c.number == value){
                System.out.println("Найденный элемент "+hash(value)+" : "+c);
            }
        }
    }
    void delete(int value){

        for(E t:a.get(hash(value))){
            Polic c= (Polic) t;
            if(c.number == value){
                a.get(hash(value)).remove(t);
            }
        }
    }
    void printik(){
        System.out.println();
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
