package Code_PTIT.File_Input_And_Output.J07007;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "lap trinh Huong doi tuong\n" +
//                "lap trinh Huong thanh phan";
        Scanner sc = new Scanner(new File("VANBAN.in"));
        TreeMap<String, Integer> map = new TreeMap<>();
        while(sc.hasNext()) {
            String line = sc.next().toLowerCase();
            map.put(line, map.getOrDefault(line, 0) + 1);
        }
        for(String s : map.keySet()) {
            System.out.println(s);
        }
    }
}
