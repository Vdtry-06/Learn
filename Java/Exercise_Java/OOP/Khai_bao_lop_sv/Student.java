package Exercise_Java.OOP.Khai_bao_lop_sv;

import java.util.Scanner;

public class Student {
    private String name, depart, birth, code;
    private Double gpa;
    void nhap(){
        Scanner sc = new Scanner(System.in);
        this.name = sc.nextLine();
        this.depart = sc.nextLine();
        this.birth = sc.nextLine();
        this.gpa = sc.nextDouble();
        this.code = "B20DCCN001";
        String[] t = birth.split("/");
        String res = "";
        for(int i = 0; i < t.length; i++){
            if(t[i].length() < 2){
                res += "0" + t[i];
            }
            else res += t[i];
            if(t[i].length() < 4){
                res += "/";
            }
        }
        this.birth = res;
    }
    void xuat(){
        System.out.print(this.code + " " + this.name + " " + this.birth + " ");
        System.out.printf("%.2f", this.gpa);
    }
}
