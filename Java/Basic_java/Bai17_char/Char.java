package Basic_java.Bai17_char;

public class Char {
    public static void main(String[] args) {
        char a = '4';
        char b = 'A';
        char c = ' ';
        char d = 'a';
        char e = 'A';
        // ktra so
        System.out.println(Character.isDigit(a));
        // ktra chu cai
        System.out.println(Character.isLetter(b));
        // ktra chu thuong
        System.out.println(Character.isLowerCase(d));
        // ktra chu hoa
        System.out.println(Character.isUpperCase(e));
        // ktra dau cach
        System.out.println(Character.isWhitespace(c));
    }
}
