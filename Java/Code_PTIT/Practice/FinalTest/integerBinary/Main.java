package Code_PTIT.Practice.FinalTest.integerBinary;

import java.io.*;
import java.util.ArrayList;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA.in")));
        ArrayList<String> list = (ArrayList<String>) ois.readObject();
//        ArrayList<String> list = new ArrayList<>();
//        list.add("Java Programming 5 has 371 pages.\n" +
//                "\n" +
//                "More than 70 % …");
        TreeSet<Integer> set = new TreeSet<>();
        for(String s : list) {
            String [] words = s.trim().split("\\s+");
            for(String w : words) {
                try {
                    set.add(Integer.parseInt(w));
                } catch (NumberFormatException e) {}
            }
        }
        for(Integer n : set) {
            System.out.println(n);
        }
    }
}
