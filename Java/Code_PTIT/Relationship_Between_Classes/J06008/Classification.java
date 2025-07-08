package Code_PTIT.Relationship_Between_Classes.J06008;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

public class Classification implements Serializable {
    private Teacher teacher;
    private Subject subject;
    private float time;
    public Classification(String teacherId, String subjectId, float time,
                          ArrayList<Teacher> teachers, ArrayList<Subject> subjects, TreeMap<String, Float> totalTime) {
        this.teacher = findTeacherIdByTeachers(teacherId, teachers);
        this.subject = findSubjectIdBySubjects(subjectId, subjects);
        this.time = time;
        totalTime.put(teacherId, totalTime.getOrDefault(teacherId, 0f) + time);
    }

    public String getTeacherId() {
        return teacher.getId();
    }

    public Teacher getTeacherName() {
        return teacher;
    }

    private Teacher findTeacherIdByTeachers(String teacherId, ArrayList<Teacher> teachers) {
        for (Teacher teacher : teachers) {
            if(teacherId.equals(teacher.getId())) {
                return teacher;
            }
        }
        return null;
    }

    private Subject findSubjectIdBySubjects(String subjectId, ArrayList<Subject> subjects) {
        for (Subject subject : subjects) {
            if(subjectId.equals(subject.getId())) {
                return subject;
            }
        }
        return null;
    }

    public String toString() {
        return subject + " " + time;
    }
}
