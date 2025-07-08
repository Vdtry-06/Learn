package Code_PTIT.Practice.Day2.B2;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        FileInputStream f1 = new FileInputStream("DATA1.in");
        FileInputStream f2 = new FileInputStream("DATA2.in");
        ObjectInputStream os1 = new ObjectInputStream(f1);
        ObjectInputStream os2 = new ObjectInputStream(f2);
        ArrayList<String> arr1 = (ArrayList<String>) os1.readObject();
        ArrayList<Integer> arr2 = (ArrayList<Integer>) os2.readObject();
        TreeSet<String> set1 = new TreeSet<>(arr1);
        TreeSet<Integer> set2 = new TreeSet<>(arr2);
        for(String s : set1) {
            for(int s2 : set2) {
                System.out.println(s + s2 + "");
            }
        }
    }
}
