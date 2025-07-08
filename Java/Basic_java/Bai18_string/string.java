package Basic_java.Bai18_string;

import java.util.Scanner;

public class string {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(s);

        StringBuilder chuoi = new StringBuilder();

        // append: them vao cuoi chuoi
        chuoi.append(s);
        System.out.println(chuoi);

        // insert(vi tri index, chuoi can chen)
        chuoi.insert(5, "IT");
        System.out.println(chuoi);

        // delete(start, end)
        // xoa tat ca cac ki tu vi tri start den vi tri end
        chuoi.delete(5, 7);
        System.out.println(chuoi);

        // chuoi.length(): do dai chuoi
        System.out.println(chuoi.length());
    }
}
