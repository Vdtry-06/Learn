package Exercise_Java.OOP.Vehicle2;

import Exercise_Java.OOP.Vehicle.Car;
import Exercise_Java.OOP.Vehicle.Motorbike;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B19 {
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
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("DANH SACH OTO :");
        for(Car x : cars){
            if(x.getPrice_buy() >= a && x.getPrice_buy() <= b) System.out.println(x);
        }
        System.out.println("DANH SACH XE MAY :");
        for(Motorbike x : motorbikes){
            if(x.getPrice_buy() >= a && x.getPrice_buy() <= b) System.out.println(x);
        }
    }
}
