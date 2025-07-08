package Code_PTIT.Practice.FinalTest.BinaryFile;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream data1 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA1.in")));
        ObjectInputStream data2 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA2.in")));
        ArrayList<Integer> list1 = (ArrayList<Integer>) data1.readObject();
        ArrayList<Integer> list2 = (ArrayList<Integer>) data2.readObject();
        TreeMap<Integer, Integer> map1 = new TreeMap<>();
        TreeMap<Integer, Integer> map2 = new TreeMap<>();
        HashSet<Integer> set1 = new HashSet<>(list1);
        HashSet<Integer> set2 = new HashSet<>(list2);
        for(int x : list1) {
            if(set2.contains(x) && Prime(x)) {
                map1.put(x, map1.getOrDefault(x, 0) + 1);
            }
        }
        for(int x : list2) {
            if(set1.contains(x) && Prime(x)) {
                map2.put(x, map2.getOrDefault(x, 0) + 1);
            }
        }
        for(int x: map1.keySet()) {
            if(map2.containsKey(x)) {
                System.out.println(x + " " + map1.get(x) + " " + map2.get(x));
            }
        }
    }
    public static boolean Prime(int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; ++i) {
            if(n % i == 0) return false;
        }
        return true;
    }
}
