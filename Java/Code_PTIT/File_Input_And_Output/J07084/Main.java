package Code_PTIT.File_Input_And_Output.J07084;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("ONLINE.in"));
        Integer n = Integer.parseInt(sc.nextLine());
        ArrayList<Person> people = new ArrayList<>();
        while (n-- > 0) {
            people.add(new Person(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(people);
        for (Person p : people) {
            System.out.println(p);
        }
    }
}
