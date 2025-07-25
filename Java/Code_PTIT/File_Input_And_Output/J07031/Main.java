package Code_PTIT.File_Input_And_Output.J07031;

import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args)  {
        try {
            ObjectInputStream data1 = new ObjectInputStream(new FileInputStream("DATA1.in"));
            ArrayList<Integer> arrayList1 = (ArrayList<Integer>) data1.readObject();
            data1.close();

            ObjectInputStream data2 = new ObjectInputStream(new FileInputStream("DATA2.in"));
            ArrayList<Integer> arrayList2 = (ArrayList<Integer>) data2.readObject();
            data2.close();

            TreeSet<Integer> treeSet1 = new TreeSet<>();
            for(int x : arrayList1) {
                if(Prime(x)) treeSet1.add(x);
            }
            for(Integer x : treeSet1) {
                int y = 1000000 - x;
                if(x >= y) break;
                if(treeSet1.contains(y) && !arrayList2.contains(x) && !arrayList2.contains(y)) {
                    System.out.println(x + " " + y);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static boolean Prime(int n) {
        for(int i = 2; i * i <= n; ++i) {
            if(n % i == 0) return false;
        }
        return n >= 2;
    }
}
