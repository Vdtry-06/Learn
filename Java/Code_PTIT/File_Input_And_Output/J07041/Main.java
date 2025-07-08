package Code_PTIT.File_Input_And_Output.J07041;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA.in")));
        ArrayList<Pair> arrayList = (ArrayList<Pair>) ois.readObject();
        Collections.sort(arrayList);
        TreeSet<String> treeSet = new TreeSet<>();
        for(Pair p : arrayList) {
            if(p.getFirst() < p.getSecond() && !treeSet.contains(p.toString())) {
                System.out.println(p);
                treeSet.add(p.toString());
            }
        }
    }
}
