package Code_PTIT.File_Input_And_Output.J07005;

import java.io.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        DataInputStream DataInputStream = new DataInputStream(new BufferedInputStream(new FileInputStream("DATA.IN")));
        int [] f = new int[1000];
        for (int i = 0; i < 100000; ++i) {
            f[DataInputStream.readInt()]++;
        }
        for (int i = 0; i < 1000; ++i) {
            if(f[i] > 0) {
                System.out.println(i + " " + f[i]);
            }
        }
    }
}
