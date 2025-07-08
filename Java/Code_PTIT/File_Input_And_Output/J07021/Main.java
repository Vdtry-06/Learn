package Code_PTIT.File_Input_And_Output.J07021;

import java.io.File;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
//            String Text = "   nGuYEN    vAN    naM\n" +
//                    "tRan           TRUNG hiEU\n" +
//                    "      vO le         hOA bINh\n" +
//                    "\n" +
//                    "END";
            Scanner sc = new Scanner(new File("DATA.in"));
            while(sc.hasNextLine()) {
                String s = sc.nextLine().trim();
                if(s.equals("END")) break;
                if(s.isEmpty()) continue;
                String [] name = s.split("\\s+");
                StringBuilder res = new StringBuilder();
                for(String x: name) {
                    res.append(Character.toUpperCase(x.charAt(0)))
                            .append(x.substring(1).toLowerCase())
                            .append(" ");
                }
                res.deleteCharAt(res.length()-1);
                System.out.println(res.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
