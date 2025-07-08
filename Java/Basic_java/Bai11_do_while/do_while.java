package Basic_java.Bai11_do_while;

public class do_while {
    public static void main(String[] args) {
        int s = 0, i = 0;
        do{
            s += i;
            i++;
        } while(i <= 5);
        System.out.println(s);
    }
}
