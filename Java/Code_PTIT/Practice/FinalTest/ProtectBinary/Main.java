package Code_PTIT.Practice.FinalTest.ProtectBinary;

import java.io.*;
import java.util.ArrayList;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois1 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA1.in")));
        ObjectInputStream ois2 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA2.in")));
        ArrayList<String> list1 = (ArrayList<String>) ois1.readObject();
        ArrayList<Integer> list2 = (ArrayList<Integer>) ois2.readObject();
//        ArrayList<String> list1 = new ArrayList<>();
//        ArrayList<Integer> list2 = new ArrayList<>();
//        list1.add("AAAAA\n" +
//                "BBBBB");
//        list2.add(111);
//        list2.add(222);
        TreeSet<String> treeSet1 = new TreeSet<>();
        for(String s : list1) {
            String [] words = s.trim().split("\\s+");
            for(String w : words) {
                treeSet1.add(w);
            }
        }
        TreeSet<Integer> treeSet2 = new TreeSet<>(list2);
        for(String s : treeSet1) {
            for(Integer i : treeSet2) {
                System.out.println(s + i);
            }
        }
    }
}
