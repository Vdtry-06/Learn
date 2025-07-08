package Code_PTIT.File_Input_And_Output.J07013;

import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("SV.in")));
        ArrayList<SinhVien> students = (ArrayList<SinhVien>) ois.readObject();
        for (SinhVien student : students) {
            System.out.println(student);
        }
    }
}
