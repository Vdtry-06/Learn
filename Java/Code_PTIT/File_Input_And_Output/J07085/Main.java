package Code_PTIT.File_Input_And_Output.J07085;

import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA.in")));
        ArrayList<String> arrayList = (ArrayList<String>) ois.readObject();
//        ArrayList<String> arrayList = new ArrayList<>();
//        arrayList.add("Jhsf00dklT12uhf780LPPZ598347859743875843509384058834574000000000855555557488888888888333333333338578457084n3885435H\n" +
//                "\n" +
//                "AAAAddd0000000000000000001T");
        for (String s : arrayList) {
            String [] words = s.trim().split("\\s+");
            for(String word : words) {
                long sum = 0;
                String res = "";
                for(char c : word.toCharArray()) {
                    if (Character.isDigit(c)) {
                        res += (c - '0');
                        sum = sum + (c - '0');
                    }
                }
                while(res.charAt(0) == '0' && res.length() > 1) res = res.substring(1);
                System.out.println(res + " " + sum);
            }
        }
    }
}
