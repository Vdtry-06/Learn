package Exercise_Java.String.Tao_email_va_mk;

import java.util.Scanner;

public class B12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        while(n != 0){
            String[] name = sc.nextLine().toLowerCase().split("\\s+");
            StringBuilder Name = new StringBuilder(name[name.length - 2]);
            for(int i = 0; i < name.length - 2; i++){
                Name.append(name[i].charAt(0));
            }
            Name.append("@xyz.edu.vn");
            String birth = name[name.length - 1];
            String[] Birth = birth.split("/");
            StringBuilder t = new StringBuilder();
            for(String x : Birth){
                if(x.length() == 2 && x.charAt(0) == '0'){
                    t.append(x.charAt(1));
                }
                else t.append(x);
            }
            System.out.println(Name);
            System.out.println(t);
            n--;
        }
    }
}
