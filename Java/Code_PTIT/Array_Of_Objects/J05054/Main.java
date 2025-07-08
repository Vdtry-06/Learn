package Code_PTIT.Array_Of_Objects.J05054;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        LinkedHashMap<Float, Integer> map = new LinkedHashMap<>();
        while(n-- > 0) {
            students.add(new Student(sc.nextLine(), Float.parseFloat(sc.nextLine()), map));
        }
        Collections.sort(students);
        int cnt = 1;
        ArrayList<Pair> pairs = new ArrayList<>();
        for(Student student : students) {
            pairs.add(new Pair(student.toString(), student.getStt(), (cnt - student.getFre() + 1)));
            cnt++;
        }
        Collections.sort(pairs);
        for(Pair pair : pairs) {
            System.out.println(pair);
        }
    }
}
//6
//Le Pham Duc
//9.2
//Tran Minh Hieu
//5.9
//Le Hong Ha
//9.2
//Nguyen Bao Trung
//8.6
//Nguyen Bao Hung
//8.6
//Le Hong Thai
//9.2