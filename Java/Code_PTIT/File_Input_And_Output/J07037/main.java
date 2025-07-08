package Code_PTIT.File_Input_And_Output.J07037;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "4\n" +
//                "VIETTEL\n" +
//                "TAP DOAN VIEN THONG QUAN DOI VIETTEL\n" +
//                "40\n" +
//                "FSOFT\n" +
//                "CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE\n" +
//                "300\n" +
//                "VNPT\n" +
//                "TAP DOAN BUU CHINH VIEN THONG VIET NAM\n" +
//                "200\n" +
//                "SUN\n" +
//                "SUN*\n" +
//                "50";
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("DN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Industry> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Industry industry = new Industry(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()));
            arr.add(industry);
        }
        Collections.sort(arr);
        for(Industry industry : arr) {
            System.out.println(industry);
        }
    }
}
