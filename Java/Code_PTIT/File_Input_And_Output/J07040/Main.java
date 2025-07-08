package Code_PTIT.File_Input_And_Output.J07040;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("NHIPHAN.in")));
        ArrayList<String> arrayList = (ArrayList<String>) ois.readObject();
        Set<String> set = new TreeSet<>();
        for (String s : arrayList) {
            String [] words = s.trim().toLowerCase().split("\\s+");
            set.addAll(Arrays.asList(words));
        }

        Scanner sc = new Scanner(new File("VANBAN.in"));
        while(sc.hasNext()) {
            String word = sc.next().toLowerCase();
            if (set.contains(word)) {
                System.out.println(word);
                set.remove(word);
            }
        }
    }
}
