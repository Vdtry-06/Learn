package Code_PTIT.File_Input_And_Output.J07035;

import java.util.ArrayList;

public class ScoreTable implements Comparable<ScoreTable>{
    private Student student;
    private Subject subject;
    private float score;
    public ScoreTable(String studentId, ArrayList<Student> students,String subjectId, ArrayList<Subject> subjects, float score) {
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
    public String getSubjectId() {
        return this.subject != null ? this.subject.getId() : null;
    }
    @Override
    public int compareTo(ScoreTable o) {
        if (o.score == this.score) {
            return this.student.getId().compareTo(o.student.getId());
        }
        return Float.compare(o.score, this.score);
    }
    @Override
    public String toString() {
        String formattedScore = (score % 1 == 0) ? String.format("%d", (int) score) : String.format("%.1f", score);
        return student.toString() + " " + formattedScore;
    }
}
