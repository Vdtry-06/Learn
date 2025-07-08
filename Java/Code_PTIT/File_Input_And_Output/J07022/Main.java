package Code_PTIT.File_Input_And_Output.J07022;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
//        String Text = "12 3 4 5 6 7\n" +
//                "Aaa 1 1 Bbb XXX yyy 5 5\n" +
//                "999999999999999999999999\n" +
//                "9";
        try {
            Scanner sc = new Scanner(new File("DATA.in"));
            ArrayList<String> list = new ArrayList<>();
            while (sc.hasNext()) {
                if (!sc.hasNextInt()) {
                    String s = sc.next();
                    list.add(s);
                }
                else {
                    sc.next();
                }
            }
            Collections.sort(list);
            for(String str : list) {
                System.out.print(str + " ");
            }
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
