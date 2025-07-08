package Basic_java.Bai4_data_type_coercion;

public class data_type_coercion {
    public static void main(String[] args) {
        int a = 5;
        int b = 10;
        double kq = (double) a / b;
        System.out.println(kq);

        int c = 128;
        byte d = (byte) c;
        System.out.println(c);
        System.out.println(d);

        int e = 15;
        byte f = (byte) e;
        System.out.println(e);
        System.out.println(f);
    }
}
