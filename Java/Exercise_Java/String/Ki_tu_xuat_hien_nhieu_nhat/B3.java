package Exercise_Java.String.Ki_tu_xuat_hien_nhieu_nhat;

import java.util.HashMap;
import java.util.Scanner;

public class B3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        HashMap<Character, Integer> map = new HashMap<>();
        String s = sc.nextLine();
        int [] f = new int[256];
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            f[c]++;
        }
        for(int i = 0; i < 256; i++){
            if(f[i] != 0){
                map.put((char) i, f[i]);
                f[i] = 0;
            }
        }
        Character a = null, b = null;
        int mi = 1000000, mx = 0;
        for(char key : map.keySet()){
            // System.out.println(key + " " + map.get(key));
            if(mx <= map.get(key)){
                mx = map.get(key);
                a = key;
            }
            if(mi >= map.get(key)){
                mi = map.get(key);
                b = key;
            }
        }
        System.out.println(a + " " + mx + "\n" + b + " " + mi);
    }
}
