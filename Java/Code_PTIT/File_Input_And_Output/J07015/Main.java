package Code_PTIT.File_Input_And_Output.J07015;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.ObjectInputStream;
import java.util.*;


public class Main {
    public static int [] f = new int[10000];
    public static void Sang() {
        Arrays.fill(f, 1);
        f[0] = f[1] = 0;
        for (int i = 2; i <= 100; ++i) {
            if(f[i] == 1) {
                for(int j = i * i; j < 10000; j += i) {
                    f[j] = 0;
                }
            }
        }
    }
    public static void main(String[] args) throws FileNotFoundException, Exception {
        try {
            Sang();
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(new File("SONGUYEN.in")));
            ArrayList<Integer> arrayList = (ArrayList<Integer>) ois.readObject();
            ois.close();
            TreeMap<Integer, Integer> map = new TreeMap<>();
            for (Integer num : arrayList) {
                if(f[num] == 1) {
                    map.put(num, map.getOrDefault(num, 0) + 1);
                }
            }
            for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
                System.out.println(entry.getKey() + " : " + entry.getValue());
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
