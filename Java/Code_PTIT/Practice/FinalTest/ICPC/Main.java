package Code_PTIT.Practice.FinalTest.ICPC;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("INSTITUTION.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<School> schools = new ArrayList<>();
        while(n-- > 0) {
            schools.add(new School(sc.next().trim(), sc.nextLine().trim()));
        }

        sc = new Scanner(new File("REGISTER.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Team> teams = new ArrayList<>();
        while(m-- > 0) {
            String schoolId = sc.next().trim();
            int q = Integer.parseInt(sc.nextLine().trim());
            while(q-- > 0) {
                teams.add(new Team(sc.nextLine(), schoolId, schools));
            }
        }
        Collections.sort(teams);
        for(Team t : teams) {
            System.out.println(t);
        }
    }
}
