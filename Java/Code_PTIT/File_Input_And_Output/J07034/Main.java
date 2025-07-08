package Code_PTIT.File_Input_And_Output.J07034;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "2\n" +
//                "INT1155\n" +
//                "Tin hoc co so 2\n" +
//                "2\n" +
//                "SKD1103\n" +
//                "Ky nang tao lap Van ban\n" +
//                "1";
        Scanner sc = new Scanner(new File("MONHOC.in"));
//        Scanner sc = new Scanner(Text);
        ArrayList<Subject> arraySubject = new ArrayList<>();
        int n = Integer.parseInt(sc.nextLine());
        while(n > 0) {
            Subject subject = new Subject(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()));
            arraySubject.add(subject);
            n--;
        }
        arraySubject.sort(Subject::compareTo);
        for(Subject subject : arraySubject) {
            System.out.println(subject);
        }
    }
}
