package Code_PTIT.Practice.FinalTest.Report;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.TreeMap;

public class Report implements Comparable<Report>, Serializable {
    private Student student;
    private String time;
    private int hours;

    public Report(String studentId, String time, ArrayList<Student> students) {
        this.student = findStudentIdByStudents(studentId, students);
        this.time = time;
        this.hours = (time.charAt(0) - '0') * 10 + time.charAt(1) - '0';
    }

    private Student findStudentIdByStudents(String studentId, ArrayList<Student> students) {
        for(Student student : students) {
            if(studentId.equals(student.getId())) {
                return student;
            }
        }
        return null;
    }

    public int compareTo(Report o) {
        return this.time.compareTo(o.time);
    }

    public static void result(ArrayList<Student> students, ArrayList<Report> reports) {
        TreeMap<Boolean, Integer> treeMap1 = new TreeMap<>();
        TreeMap<Boolean, Integer> treeMap2 = new TreeMap<>();
        for(Report report : reports) {
            if(report.hours < 12) {
                treeMap1.put(true, treeMap1.getOrDefault(true, 0) + 1);
            } else {
                treeMap2.put(true, treeMap2.getOrDefault(true, 0) + 1);
            }
        }
        System.out.println("DANH SACH SINH VIEN BAO CAO CA SANG: " + ((treeMap1.get(true) == null) ? 0 : treeMap1.get(true)));
        for(Report report : reports) {
            if(report.hours < 12) {
                System.out.println(report);
            }
        }
        System.out.println();
        System.out.println("DANH SACH SINH VIEN BAO CAO CA CHIEU: " + ((treeMap2.get(true) == null) ? 0 : treeMap2.get(true)));
        for(Report report : reports) {
            if(report.hours >= 12) {
                System.out.println(report);
            }
        }
    }

    public String toString() {
        if(hours > 12) {
            hours -= 12;
            time = String.format("%02d", hours) + time.substring(2);
        }
        return student + " " + time;
    }
}
