package Code_PTIT.File_Input_And_Output.J07036;

import java.util.ArrayList;

public class ScoreTable implements Comparable<ScoreTable>{
    private Student student;
    private Subject subject;
    private float score;
    public ScoreTable(String studentId, ArrayList<Student> students, String subjectId, ArrayList<Subject> subjects, float score) {
        this.student = findStudentIdByStudents(studentId, students);
        this.subject = findSubjectIdBySubjects(subjectId, subjects);
        this.score = score;
    }
    private Student findStudentIdByStudents(String studentId, ArrayList<Student> students) {
        for(Student student : students) {
            if(studentId.equals(student.getId())) {
                return student;
            }
        }
        return null;
    }
    private Subject findSubjectIdBySubjects(String subjectId, ArrayList<Subject> subjects) {
        for(Subject subject : subjects) {
            if(subjectId.equals(subject.getId())) {
                return subject;
            }
        }
        return null;
    }
    public String getClassId() {
        return this.student != null ? this.student.getClasss() : null;
    }
    @Override
    public int compareTo(ScoreTable o) {
        if (this.subject.getId().compareTo(o.subject.getId()) == 0) {
            return this.student.getId().compareTo(o.student.getId());
        }
        return this.subject.getId().compareTo(o.subject.getId());
    }
    @Override
    public String toString() {
        String formattedScore = (score % 1 == 0) ? String.format("%d", (int) score) : String.format("%.1f", score);
        return student.toString() + " " + subject.toString() + " " + formattedScore;
    }
}
