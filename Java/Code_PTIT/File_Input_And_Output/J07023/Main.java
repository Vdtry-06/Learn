package Code_PTIT.File_Input_And_Output.J07023;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream data1 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA1.in")));
        ArrayList<Integer> arrayList1 = (ArrayList<Integer>) data1.readObject();
        TreeMap<Integer, Integer> treeMap1 = new TreeMap<>();
        for(int n: arrayList1) {
            if(Prime(n) && Reversible(n)) treeMap1.put(n, treeMap1.getOrDefault(n, 0) + 1);
        }
        ObjectInputStream data2 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA2.in")));
        ArrayList<Integer> arrayList2 = (ArrayList<Integer>) data2.readObject();
        TreeMap<Integer, Integer> treeMap2 = new TreeMap<>();
        for(int n: arrayList2) {
            if(Prime(n) && Reversible(n)) treeMap2.put(n, treeMap2.getOrDefault(n, 0) + 1);
        }
        for(int n: treeMap1.keySet()) {
            if(treeMap2.containsKey(n)) {
                System.out.println(n + " " + treeMap1.get(n) + " " + treeMap2.get(n));
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
    public static boolean Reversible(int n) {
        String s = String.valueOf(n);
        int l = 0, r = s.length() - 1;
        while(l <= r) {
            if(s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
