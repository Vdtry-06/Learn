package Code_PTIT.File_Input_And_Output.J07029;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.TreeMap;


public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream data = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA.in")));
        ArrayList<Integer> list = (ArrayList<Integer>) data.readObject();
        TreeMap<Integer, Integer> map = new TreeMap<>(Comparator.reverseOrder());
        for(Integer x : list) {
            if(Prime(x)) map.put(x, map.getOrDefault(x, 0) + 1);
        }
        int d = 0;
        for(Integer x : map.keySet()) {
            System.out.println(x + " " + map.get(x));
            d++;
            if(d == 10) break;
        }
        data.close();
    }
    public static boolean Prime(int n) {
        if(n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
}
