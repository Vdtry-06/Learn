package Code_PTIT.File_Input_And_Output.J07032;

import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        try {
            ObjectInputStream data1 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA1.in")));
            ArrayList<Integer> arr1 = (ArrayList<Integer>) data1.readObject();
            data1.close();

            ObjectInputStream data2 = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DATA2.in")));
            ArrayList<Integer> arr2 = (ArrayList<Integer>) data2.readObject();
            data2.close();

            int [] f = new int [1000001];
            for(Integer x : arr1) {
                if(Reversible(x) && ordNum(x) && arr2.contains(x)) {
                    f[x]++;
                }
            }

            for(Integer x : arr2) {
                if(Reversible(x) && ordNum(x) && f[x] != 0) {
                    f[x]++;
                }
            }

            int cnt = 0;
            for(int i = 0; i <= 1000000; ++i) {
                if(f[i] > 0) {
                    System.out.println(i + " " + f[i]);
                    cnt++;
                }
                if(cnt == 10) break;
            }

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static boolean Reversible(int n) {
        String s = String.valueOf(n);
        int r = s.length() - 1,l = 0;
        while(l <= r) {
            if(s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    public static boolean ordNum(int n) {
        String s = String.valueOf(n);
        if(s.length() % 2 != 0 && s.length() > 1) {
            for(int i = 0; i < s.length(); i++) {
                if((s.charAt(i) - '0') % 2 == 0) return false;
            }
            return true;
        }
        return false;
    }
}
