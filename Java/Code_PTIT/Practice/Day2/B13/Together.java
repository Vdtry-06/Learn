package Code_PTIT.Practice.Day2.B13;

import java.util.ArrayList;

public class Together implements Comparable<Together>{
    private Student student;
    private Target target;
    private String id;
    public Together(String msv, ArrayList<Student> students, String mdt, ArrayList<Target> targets, String id) {
        this.student = findMsvByStudents(msv, students);
        this.target = findmdtByTargets(mdt, targets);
        this.id = id;
    }
    private Student findMsvByStudents(String msv, ArrayList<Student> students) {
        for (Student s : students) {
            if(s.getId().equals(msv)) {
                return s;
            }
        }
        return null;
    }
    private Target findmdtByTargets(String mdt, ArrayList<Target> targets) {
        for (Target t : targets) {
            if(t.getId().equals(mdt)) {
                return t;
            }
        }
        return null;
    }
    public String getId() {
        return id;
    }
    @Override
    public int compareTo(Together o) {
//        if(this.student != null && o.student != null) {
            return this.student.getId().compareTo(o.student.getId());
//        }
//        return 0;
    }
    @Override
    public String toString() {
        if(this.student != null && this.target != null) {
            return student.toString() + " " + target.toString();
        }
        return "";
    }
}
