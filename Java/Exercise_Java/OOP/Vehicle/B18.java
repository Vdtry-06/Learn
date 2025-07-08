package Exercise_Java.OOP.Vehicle;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Motorbike> motorbikes = new ArrayList<>();
        ArrayList<Car> cars = new ArrayList<>();
        for(int i = 0; i < n; i++){
            String code = sc.nextLine();
            String name = sc.nextLine();
            String brand = sc.nextLine();
            String color = sc.nextLine();
            if(code.contains("XM")){
                motorbikes.add(new Motorbike(code, name, brand, color, Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
            }
            else{
                cars.add(new Car(code, name, brand, color, Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
            }
        }
        Collections.sort(cars);
        System.out.println("DANH SACH OTO :");
        for(Car x : cars){
            System.out.println(x);
        }
        Collections.sort(motorbikes);
        System.out.println("DANH SACH XE MAY :");
        for(Motorbike x : motorbikes){
            System.out.println(x);
        }
    }
}
