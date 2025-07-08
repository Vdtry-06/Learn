package Code_PTIT.File_Input_And_Output.J07038;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0) {
            students.add(new Student(sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim()));
        }

        sc = new Scanner(new File("DN.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Business> businesses = new ArrayList<>();
        while(m-- > 0) {
            businesses.add(new Business(sc.nextLine().trim(), sc.nextLine().trim(), Integer.parseInt(sc.nextLine().trim())));
        }

        sc = new Scanner(new File("THUCTAP.in"));
        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Intern> interns = new ArrayList<>();
        while(q-- > 0) {
            interns.add(new Intern(sc.next().trim(), sc.nextLine().trim(), students, businesses));
        }
        Collections.sort(interns);

        int t = Integer.parseInt(sc.nextLine());
        while(t -- > 0) {
            String id = sc.nextLine();
            String name = "";
            int cnt = 0;
            for(Business business : businesses) {
                if(business.getId().equals(id)) {
                    name = business.getName();
                    cnt = business.getAmount();
                    break;
                }
            }
            System.out.println("DANH SACH THUC TAP TAI " + name + ":");
            for(Intern intern : interns) {
                if (cnt == 0) break;
                if(intern.getBusinessId().equals(id)) {
                    cnt--;
                    System.out.println(intern);
                }
            }
        }
    }
}
