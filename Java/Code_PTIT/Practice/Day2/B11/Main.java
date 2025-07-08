package Code_PTIT.Practice.Day2.B11;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("INSTITUTION.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<University> universities = new ArrayList<>();
        while(n-- > 0) {
            String line = sc.nextLine();
            String[] parts = line.split(" ", 2);
            universities.add(new University(parts[0], parts[1]));
        }
        sc = new Scanner(new File("REGISTER.in"));
        ArrayList<Team> teams = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        while(m-- > 0) {
            String line = sc.nextLine();
            String[] parts = line.split(" ", 2);
            String universityId = parts[0];
            int teamcnt = Integer.parseInt(parts[1]);
            for(int i = 0; i < teamcnt; i++) {
                String teamName = sc.nextLine().trim();
                teams.add(new Team(universityId, universities, teamName));
            }
        }
        Collections.sort(teams);
        for(Team t : teams) {
            System.out.println(t);
        }
    }
}
