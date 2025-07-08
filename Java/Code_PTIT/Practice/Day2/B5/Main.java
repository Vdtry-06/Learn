package Code_PTIT.Practice.Day2.B5;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        FileInputStream fi = new FileInputStream("DATA.in");
        ObjectInputStream os = new ObjectInputStream(fi);
        ArrayList<String> arr = (ArrayList<String>) os.readObject();
        TreeSet<Integer> set = new TreeSet<>();
        for(String s : arr) {
            String[] words = s.split("\\s+");
            for(String w: words) {
                try {
                    int x = Integer.parseInt(w);
                    set.add(x);
                } catch(NumberFormatException e) {}
            }
        }
        for(int x: set) {
            System.out.println(x);
        }
    }
}
