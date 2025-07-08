package Code_PTIT.Array_Of_Objects.J05055;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Athlete> a = new ArrayList<>();
        ArrayList<Athlete> b = new ArrayList<>();
        int stt = 1;
        while(n-- > 0) {
            Athlete x = new Athlete(sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim(), stt++);
            a.add(x);
            b.add(x);
        }
        Collections.sort(b);
        for(Athlete x : a) {
            for(Athlete y : b) {
                if(x.getRes().equals(y.getRes())) {
                    System.out.println(x);
                    break;
                }
            }
        }
    }
}
//3
//Nguyen Van Thanh
//20/03/1990
//07:00:00
//07:10:01
//Nguyen Hoa Binh
//01/10/1993
//07:02:00
//07:11:20
//Le Thanh Van
//15/03/1998
//07:05:00
//07:15:30