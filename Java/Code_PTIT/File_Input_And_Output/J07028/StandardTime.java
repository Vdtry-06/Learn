package Code_PTIT.File_Input_And_Output.J07028;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class StandardTime implements Serializable {
    private Teacher teacher;
    private Subject subject;
    private float time;

    public StandardTime(String teacherId, ArrayList<Teacher> teachers, String subjectId, ArrayList<Subject> subjects, float time) {
        this.teacher = findTeacherIdByTeachers(teacherId, teachers);
        this.subject = findSubjectIdBySubjects(subjectId, subjects);
        this.time = time;
    }

    private Teacher findTeacherIdByTeachers(String teacherId, ArrayList<Teacher> teachers) {
        for (Teacher teacher : teachers) {
            if (teacherId.equals(teacher.getId())) {
                return teacher;
            }
        }
        return null;
    }

    private Subject findSubjectIdBySubjects(String subjectId, ArrayList<Subject> subjects) {
        for (Subject subject : subjects) {
            if (subjectId.equals(subject.getId())) {
                return subject;
            }
        }
        return null;
    }

    public static void calculateTotalTime(ArrayList<Teacher> teachers, ArrayList<StandardTime> standardTimes) {
        HashMap<Teacher, Float> totalTime = new HashMap<>();
        for (StandardTime standardTime : standardTimes) {
            Teacher teacher = standardTime.teacher;
            totalTime.put(teacher, totalTime.getOrDefault(teacher, 0.0f) + standardTime.time);
        }
        for (Teacher teacher : teachers) {
            float time = totalTime.getOrDefault(teacher, 0.0f);
            System.out.println(teacher + " " + String.format("%.2f", time));
        }
    }
}
