package Code_PTIT.Practice.Day3.B4;

import java.io.Serializable;
import java.util.ArrayList;

public class Post implements Comparable<Post>, Serializable {
    private Student student;
    private String time;
    private int hh;
    private int pos;

    public Post(String studentId, ArrayList<Student> students, String time) {
        this.student = findStudentIdByStudents(studentId, students);
        this.time = time;
        this.hh = (time.charAt(0) - '0') * 10 + (time.charAt(1) - '0');
        if(hh < 12) this.pos = 2;
        else {
            this.pos = 1;
//            if(hh != 12) {
//                int newhour = hh - 12;
//                String tmp = "0" + newhour;
//                time = tmp + time.substring(2);
//            }
        }

//        this.time = time;
    }

    private Student findStudentIdByStudents(String studentId, ArrayList<Student> students) {
        for (Student student : students) {
            if(studentId.equals(student.getId())) {
                return student;
            }
        }
        return null;
    }
    public int getPos() {return pos;}

    public int compareTo(Post post) {
        return time.compareTo(post.time);
    }
    public String toString() {
        if(hh > 12) {
            int newhour = hh - 12;
            String tmp = "0" + newhour;
            time = tmp + time.substring(2);
        }
        return student + " " + time;
    }
}
