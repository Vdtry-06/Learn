package Code_PTIT.File_Input_And_Output.J07060;
import java.util.ArrayList;

public class Calendar implements Comparable<Calendar>{
    private Subject subject;
    private Exam exam;
    private String group;
    private int student;
    public Calendar(String examId, ArrayList<Exam> exams, String subjectId, ArrayList<Subject> subjects, String group, int student) {
        this.exam = findExamIdByExams(examId, exams);
        this.subject = findSubjectIdBySubjects(subjectId, subjects);
        this.group = group;
        this.student = student;
    }

    private Exam findExamIdByExams(String examId, ArrayList<Exam> exams) {
        for (Exam exam : exams) {
            if(examId.equals(exam.getId()))
                return exam;
        }
        return null;
    }
    private Subject findSubjectIdBySubjects(String subjectId, ArrayList<Subject> subjects) {
        for (Subject subject : subjects) {
            if(subjectId.equals(subject.getId()))
                return subject;
        }
        return null;
    }
    @Override
    public int compareTo(Calendar o) {
        if(this.exam.getTime().compareTo(o.exam.getTime()) == 0) {
            return this.exam.getId().compareTo(o.exam.getId());
        }
        return this.exam.getTime().compareTo(o.exam.getTime());

    }
    @Override
    public String toString() {
        return exam.toString() + " " + subject.toString() + " " + group + " " + student;
    }
}
