package Code_PTIT.Practice.Day1.TH5;

import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream  data = new ObjectInputStream(new BufferedInputStream(new FileInputStream("DAYSO.DAT")));
        ArrayList<Integer> arr = (ArrayList<Integer>) data.readObject();
        data.close();
        int [] f = new int[1000001];
        for(int i = 0; i < arr.size(); i++){
            if(isPrime(arr.get(i)) && String.valueOf(arr.get(i)).length() >= 3){
                f[arr.get(i)]++;
            }
        }
        for(int i = 100; i < 1000000; i++){
            if(f[i] > 0) {
                System.out.println(i);
            }
        }
    }
    public static Boolean isPrime(int n) {
        if(n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
