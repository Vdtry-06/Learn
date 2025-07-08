package Code_PTIT.Practice.Day3.B4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("C:\\Users\\ASUS\\Trong\\Java\\Code_PTIT\\Practice\\Day3\\B4\\BAITAP.in"));
        ArrayList<Student> students = new ArrayList<>();
        while (sc.hasNextLine()) {
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("C:\\Users\\ASUS\\Trong\\Java\\Code_PTIT\\Practice\\Day3\\B4\\BAOCAO.in"));
        ArrayList<Post> posts = new ArrayList<>();
        while (sc.hasNextLine()) {
            posts.add(new Post(sc.nextLine(), students, sc.nextLine()));
        }
//        Collections.sort(posts);
        System.out.println("DANH SACH SINH VIEN BAO CAO CA SANG: 2");
        for(Post p: posts) {
            if(p.getPos() == 2) {
                System.out.println(p);
            }
        }
        System.out.println();
        System.out.println("DANH SACH SINH VIEN BAO CAO CA CHIEU: 1");
        for(Post p: posts) {
            if(p.getPos() == 1) {
                System.out.println(p);
            }
        }
//        for(Post post : posts) {
//            System.out.println(post.getTime());
//        }
    }
}
