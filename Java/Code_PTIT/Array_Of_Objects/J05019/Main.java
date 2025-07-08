package Code_PTIT.Array_Of_Objects.J05019;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Station> stations = new ArrayList<>();
        int cnt = 0;
        while(n-- > 0) {
            stations.add(new Station(sc.nextLine(), sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), cnt++));
        }
        stations.sort(Comparator.comparing(Station::getName));
        LinkedHashMap<String, Integer> map1 = new LinkedHashMap<>();
        LinkedHashMap<String, Integer> map2 = new LinkedHashMap<>();
        for(Station s: stations) {
            map1.put(s.getName(), map1.getOrDefault(s.getName(), 0) + s.getAmount());
            map2.put(s.getName(), map2.getOrDefault(s.getName(), 0) + s.getTime());
        }
        stations.sort(Comparator.comparing(Station::getIdx));
        for(Station s: stations) {
            if(map1.containsKey(s.getName())) {
                float res = (float) map1.get(s.getName()) / map2.get(s.getName()) * 60;
                System.out.println(s + " " + String.format("%.2f", res));
                map1.remove(s.getName());
            }
        }
    }
}
//10
//Dong Anh
//07:30
//08:00
//60
//Cau Giay
//07:45
//08:12
//50
//Soc Son
//08:00
//09:15
//78
//Dong Anh
//18:50
//20:00
//88
//Cau Giay
//19:01
//20:00
//77
//Soc Son
//19:06
//20:21
//66
//Dong Anh
//21:00
//21:40
//49
//Cau Giay
//21:50
//22:20
//68
//Dong Anh
//22:15
//23:45
//30
//Cau Giay
//22:50
//23:45
//35