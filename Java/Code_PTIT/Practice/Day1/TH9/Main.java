package Code_PTIT.Practice.Day1.TH9;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "B21DCCN123\n" +
//                "Tran Van Toan\n" +
//                "D21CQCN01-B\n" +
//                "toantv@gmail.com\n" +
//                "987654321\n" +
//                "B21DCCN111\n" +
//                "Ly Van Binh\n" +
//                "D21CQCN01-B\n" +
//                "binhlv@gmail.com\n" +
//                "978652142\n" +
//                "B21DCAT661\n" +
//                "Hoang Tam Anh\n" +
//                "D21CQAT01-B\n" +
//                "anhht@gmail.com\n" +
//                "966554321";
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        ArrayList<Contact> arr = new ArrayList<>();
        while(sc.hasNext()) {
            Contact contact = new Contact(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            arr.add(contact);
        }
        Collections.sort(arr);
        for(Contact c : arr) {
            System.out.println(c);
        }
    }
}
