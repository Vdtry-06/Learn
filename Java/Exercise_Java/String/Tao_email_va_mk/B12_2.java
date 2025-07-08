package Exercise_Java.String.Tao_email_va_mk;

import java.util.*;

public class B12_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        Map<String, Integer> emailCount = new HashMap<>();
        while(n != 0){
            String[] name = sc.nextLine().toLowerCase().split("\\s+");
            StringBuilder Name = new StringBuilder(name[name.length - 2]);
            for(int i = 0; i < name.length - 2; i++){
                Name.append(name[i].charAt(0));
            }

            String emailBase = Name.toString();
            int count = emailCount.getOrDefault(emailBase, 0) + 1;
            emailCount.put(emailBase, count);
            if (count > 1) {
                Name.append(count);
            }
            Name.append("@xyz.edu.vn");
            System.out.println(Name);

            String birth = name[name.length - 1];
            String[] Birth = birth.split("/");
            StringBuilder t = new StringBuilder();
            for(String x : Birth){
                if(x.length() == 2 && x.charAt(0) == '0'){
                    t.append(x.charAt(1));
                }
                else t.append(x);
            }
            System.out.println(t);
            n--;
        }
    }
}
