package Code_PTIT.File_Input_And_Output.J07027;

import java.util.ArrayList;

public class Group implements Comparable<Group>{
    private Student student;
    private Exercise exercise;
    public Group(String studentId, ArrayList<Student> students, int exerciseId, ArrayList<Exercise> exercises) {
        this.student = findStudentIdByStudent(studentId, students);
        this.exercise = findExerciseIdByExercise(exerciseId, exercises);
    }
    private Student findStudentIdByStudent(String studentId, ArrayList<Student> students) {
        for (Student student : students) {
            if(studentId.equals(student.getId())) {
                return student;
            }
        }
        return null;
    }
    private Exercise findExerciseIdByExercise(int exerciseId, ArrayList<Exercise> exercises) {
        for (Exercise exercise : exercises) {
            if(exerciseId == exercise.getId()) {
                return exercise;
            }
        }
        return null;
    }
    @Override
    public int compareTo(Group o) {
        return this.student.getId().compareTo(o.student.getId());
    }
    @Override
    public String toString() {
        return student.toString() + " " + exercise.toString();
    }
}
