package Basic_java.Bai19_Method_string;

public class method_string {
    public static void main(String[] args) {
        String s = " toi di tim toi";

        // indexOf: Kiem tra vi tri xuat hien dau tien cua ki tu hoac chuoi
        // tra ve -1 neu khong tim thay
        System.out.println(s.indexOf("toi"));

        // lastIndexOf: Kiem tra vi tri xuat hien cuoi cung cua ki tu hoac chuoi
        // tra ve -1 neu khong tim thay
        System.out.println(s.lastIndexOf("toi"));

        // contains: ktra chuoi con
        String s1 = "Mp3";
        String s2 = "Tu_hoc.Mp3";
        boolean check = s2.contains(s1);
        System.out.println(check ? 1: 0);

        // Substring: trich loc chuoi con tu chuoi ban dau
        String s3 = "abcdegh";
        String s4 = s3.substring(4);
        System.out.println(s4);
        String s5 = s3.substring(3, 6);
        System.out.println(s5);

        // replace("str old", "str new"): thay chuoi cu thanh chuoi moi
        String s6 = "toi di tim toi";
        String s7 = s6.replace("toi", "ban");
        System.out.println(s7);

        // replaceFirst("str old", "str new"): thay chuoi cu thanh chuoi moi dau tien
        String s8 = "toi di tim toi";
        String s9 = s6.replaceFirst("toi", "ban");
        System.out.println(s9);

        // trim(): xoa toan bo khoang trang o dau va cuoi
        String s10 = "      ga lai lap trinh    ";
        String s11 = s10.trim();
        System.out.println(s11);

        // tach chuoi
        String s12 = "Hello world";
        String [] arr = s12.split(" ");
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }

        // toLowerCase() && toUpperCase()
        String s13 = "Toi hoc Lap TRINH tai tu hoc scc";
        String s14 = s13.toLowerCase();
        System.out.println(s14);
        System.out.println(s14.toUpperCase());

        // toCharArray(): tach chuoi thanh tung ki tu, cho vao mang
        String s15 = "abcsdgasdg123@";
        char [] arr2 = s15.toCharArray();
        for(int i = 0; i < arr2.length; i++){
            System.out.print(arr2[i] + " ");
        }

        // reverse(): dao nguoc chuoi
        String s16 = "123456789abc";
        // khai bao doi tuong thuoc class StringBuilder
        StringBuilder sb = new StringBuilder(s16);
        sb.reverse();
        String s17 = sb.toString(); // chuyen sang chuoi
        System.out.println(s17);
    }
}
