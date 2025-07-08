package Code_PTIT.File_Input_And_Output.J07038;

import java.util.ArrayList;

public class Intern implements Comparable<Intern>{
    private Student student;
    private Business business;
    private String studentId, businessId;
    public Intern(String studentId, String businessId, ArrayList<Student> students, ArrayList<Business> businesses) {
        this.studentId = studentId;
        this.businessId = businessId;
        this.student = findStudentIdByStudents(studentId, students);
        this.business = findBusinessIdByBusinesses(businessId, businesses);
    }
    private Student findStudentIdByStudents(String studentId, ArrayList<Student> students) {
        for (Student student : students) {
            if(studentId.equals(student.getId())) {
                return student;
            }
        }
        return null;
    }
    private Business findBusinessIdByBusinesses(String businessId, ArrayList<Business> businesses) {
        for (Business business : businesses) {
            if(businessId.equals(business.getId())) {
                return business;
            }
        }
        return null;
    }

    public String getStudentId() {
        return studentId;
    }

    public String getBusinessId() {
        return businessId;
    }

    @Override
    public int compareTo(Intern o) {
        return this.studentId.compareTo(o.studentId);
    }

    @Override
    public String toString() {
        return student.toString();
    }
}
