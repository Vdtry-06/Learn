package Code_PTIT.Practice.Day1.TH6;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "    nGUYEn    quaNG   vInH  \n" +
//                "   tRan   thi THU    huOnG\n" +
//                "   nGO   quoC  VINH\n" +
//                " lE            tuAn    aNH\n" +
//                "NGO QUOC VINH\n" +
//                "Tran THI THU huong";
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        Map<String, Integer> mName = new HashMap<>();
        Map<String, Integer> mMail = new HashMap<>();
        ArrayList<String> set = new ArrayList<>();
        while(sc.hasNextLine()) {
            String [] words = sc.nextLine().trim().toLowerCase().split("\\s+");
            String tmp = "";
            for(int i = 0; i < words.length; i++) {
                tmp += words[i];
                if(i < words.length - 1) tmp += " ";
            }
            if(!set.contains(tmp)) {
                set.add(tmp);
            }

        }
        for(String email : set) {
            String[] words = email.split("\\s+");
            String name = getName(words);
            String mail = getEmail(words);
            if (!mName.containsKey(name)) {
                mName.put(name, 1);
                int cnt = (mMail.containsKey(mail) ? mMail.get(mail) : 0) + 1;
                mMail.put(mail, cnt);
                System.out.println(mail + (cnt > 1 ? cnt : "") + "@ptit.edu.vn");
                //            }
            }
        }
    }
    public static String getEmail(String [] words) {
        String mail = words[words.length - 1];
        for(int i = 0; i < words.length - 1; i++) {
            mail += words[i].charAt(0);
        }
        return mail;
    }
    public static String getName(String [] words) {
        String name = "";
        for(String x: words) {
            name += words + " ";
        }
        return name;
    }
}

