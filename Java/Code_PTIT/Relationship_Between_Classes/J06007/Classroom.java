package Code_PTIT.Relationship_Between_Classes.J06007;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Classroom implements Serializable {
    private Teacher teacher;
    private Subject subject;
    private float factTime;
    private String studentId, subjectId;
    private Float sumTime;
    public Classroom(String studentId, String subjectId, float factTime,
                     ArrayList<Teacher> teachers, ArrayList<Subject> subjects, LinkedHashMap<String, Float> map) {
        this.studentId = studentId;
        this.subjectId = subjectId;
        this.factTime = factTime;
        this.teacher = findStudentIdByStudents(studentId, teachers);
        this.subject = findSubjectIdBySubjects(subjectId, subjects);
        map.put(this.studentId, map.getOrDefault(this.studentId, 0f) + factTime);
    }
    private Teacher findStudentIdByStudents(String studentId, ArrayList<Teacher> teachers) {
        for (Teacher s : teachers) {
            if(s.getId().equals(studentId)) {
                return s;
            }
        }
        return null;
    }
    private Subject findSubjectIdBySubjects(String subjectId, ArrayList<Subject> subjects) {
        for (Subject s : subjects) {
            if(s.getId().equals(subjectId)) {
                return s;
            }
        }
        return null;
    }
    
}
