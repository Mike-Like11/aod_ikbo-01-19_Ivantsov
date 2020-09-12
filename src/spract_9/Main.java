package spract_9;

import java.util.ArrayDeque;

public class Main {

    public static void main(String[] args) {
	// write your code here
        // write your code here
        int[] a = {54, 18, 84, 3, 617, 908, 100, 8,12321,543,993,4953,2349,34324};
        sortik(a);
        System.out.println();
        for (int n : a)
            System.out.print(n + " ");
    }
    public static void sortik(int[] a) {

        ArrayDeque<Integer>[] array = new ArrayDeque[10];
        for (int i = 0; i < array.length; i++) {
            array[i] = new ArrayDeque<>();
        }
        boolean flag = false;
        int  c = 1;
        while (!flag) {
            flag = true;
            for (Integer i : a) {
                array[i / c % 10].addLast(i);
                if (flag && i / c > 0) {
                    flag=false;
                }
            }
            if(!flag) {
                int d = 0;
                for (int b = 0; b < 10; b++) {
                    while(!array[b].isEmpty()) {
                        a[d++] = array[b].getFirst();
                        array[b].removeFirst();
                    }

                }
                System.out.println();
                for (int n : a)
                    System.out.print(n + " ");
                c = c * 10;
            }
        }
    }
}
