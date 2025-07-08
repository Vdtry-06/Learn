package Basic_java.Bai13_Try_catch;

public class Try_catch {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;
        try {
            int c = a / b;
            System.out.println(c);
        }
        catch(Exception ex) {
            System.out.println("Co loi");
            ex.printStackTrace();
        }
    }
}
