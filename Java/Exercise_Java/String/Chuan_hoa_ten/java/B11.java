package Exercise_Java.String.Chuan_hoa_ten.java;

import Basic_java.Bai17_char.Char;

import java.util.Scanner;

public class B11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        String birth = sc.nextLine();
        String[] Name = name.toLowerCase().split("\\s+");
        for(int i = 0; i < Name.length; i++){
            Name[i] = Character.toUpperCase(Name[i].charAt(0)) + Name[i].substring(1);
            System.out.print(Name[i] + " ");
        }
        System.out.println();
        String[] Birth = birth.split("/");
        String t = "";
        for(int i = 0; i < Birth.length; i++){
            if(Birth[i].length() < 2){
                t += "0" + Birth[i];
            }
            else t += Birth[i];
            if(Birth[i].length() < 4){
                t += "/";
            }
        }
        System.out.println(t);
    }
}
