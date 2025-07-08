package Code_PTIT.Practice.Day2.B13;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("C:\\Users\\ASUS\\Trong\\Java\\Code_PTIT\\Practice\\Day2\\B13\\SINHVIEN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0) {
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("C:\\Users\\ASUS\\Trong\\Java\\Code_PTIT\\Practice\\Day2\\B13\\DETAI.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Target> targets = new ArrayList<>();
        while(m-- > 0) {
            targets.add(new Target(sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("C:\\Users\\ASUS\\Trong\\Java\\Code_PTIT\\Practice\\Day2\\B13\\HOIDONG.in"));
        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Together> togethers = new ArrayList<>();
        while(q-- > 0) {
            togethers.add(new Together(sc.next(), students, sc.next(), targets, sc.next()));
        }
        Collections.sort(togethers);
        int cnt = 1;
        ArrayList<String> HD = new ArrayList<>();
        for(Together together : togethers) {
//            System.out.println(together);
            String nameHd = String.format("HD%01d", cnt++);
            HD.add(nameHd);
        }
        for(String x: HD) {
            System.out.println("DANH SACH HOI DONG " + x.charAt(2) + ": ");
            for(Together together : togethers) {
                if(x.equals(together.getId())) {
                    System.out.println(together);
                }
            }
        }
    }
}
