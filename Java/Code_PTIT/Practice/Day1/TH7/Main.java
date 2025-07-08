package Code_PTIT.Practice.Day1.TH7;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "PTIT duy tri hoc phi nam 2019 va khong tang hoc phi\n" +
//                "trong nam 2020, 2021 va 2021 den 2022.\n" +
//                "PTIT da trich 6 ty d0ong ho tro moi si1nh vien 500000!";
//
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("VANBAN.in"));
        ArrayList<String> list = new ArrayList<>();
        Set<String> set = new TreeSet<>();
        while(sc.hasNextLine()){
            String line = sc.nextLine();
            String [] arr = line.split("\\s+");
            for(String word : arr){
                if(Check(word)) {
                    set.add(word);
                }
            }
        }
        for(String word : set){
            System.out.println(word);
        }
    }
    public static boolean Check(String words) {
        Boolean checkNumber = false;
        Boolean checkEndLine = true;
        for(int i = 0; i < words.length(); i++){
            if(Character.isDigit(words.charAt(i))){
                checkNumber = true;
                break;
            }
        }
        if(!checkNumber) return false;
        for(int i = 0; i < words.length(); i++){
            char c = words.charAt(i);
            if(c == '.' || c == ',' || c == '!' || c == '?' || c == ':') {
                checkEndLine = false;
                break;
            }
        }
        return checkEndLine;
    }
}
