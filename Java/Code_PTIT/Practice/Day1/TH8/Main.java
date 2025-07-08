package Code_PTIT.Practice.Day1.TH8;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "2\n" +
//                "Nguyen Van Nam\n" +
//                "168 600\n" +
//                "Tran Thi Ngoc\n" +
//                "168 600";
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("LUYENTAP.in"));
        int n = Integer.parseInt(sc.nextLine().trim());
        ArrayList<Rank> arr = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            String name = sc.nextLine().trim();
            String [] scores = sc.nextLine().trim().split(" ");

            int correct = Integer.parseInt(scores[0]);
            int submit = Integer.parseInt(scores[1]);
            Rank rank = new Rank(name, correct, submit);
            arr.add(rank);
        }
        Collections.sort(arr);
        for(Rank rank : arr) {
            System.out.println(rank);
        }
    }
}
