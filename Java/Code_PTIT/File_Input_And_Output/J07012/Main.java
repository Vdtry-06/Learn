package Code_PTIT.File_Input_And_Output.J07012;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA.in")));
        ArrayList<String> arrayList = (ArrayList<String>) ois.readObject();
//        ArrayList<String> arrayList = new ArrayList<>();
//        arrayList.add("lap trinh huong doi tuong"
//                + "\n"
//                + "lap"
//                + "\n"
//                + "lap trinh lap trinh lap trinh doi tuong"
//                + "\n"
//                + "doi tuong lap trinh"
//        );
        HashMap<String, Integer> map = new HashMap<>();
        for(String s : arrayList) {
            String [] words = s.trim().toLowerCase().split("[^a-z0-9]+");
            for(String w : words) {
                if (!w.isEmpty()) {
                    map.put(w, map.getOrDefault(w, 0) + 1);
                }
            }
        }
        ArrayList<Pair> list = new ArrayList<>();
        for(String w : map.keySet()) {
            list.add(new Pair(w, map.get(w)));
        }
        Collections.sort(list);
        for(Pair p : list) {
            System.out.println(p);
        }
    }
}
