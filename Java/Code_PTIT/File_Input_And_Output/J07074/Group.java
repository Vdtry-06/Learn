package Code_PTIT.File_Input_And_Output.J07074;

import java.util.ArrayList;

public class Group implements Comparable<Group> {
    private static int cnt = 1;
    private String id;
    private Subject subject;
    private int teachingDay;
    private int lesson;
    private String teacherName;
    private String room;

    public Group(String subjectId, ArrayList<Subject> subject, int teachingDay, int lesson, String teacherName, String room) {
        this.id = String.format("HP%03d", cnt++);
        this.subject = findSubjectById(subjectId, subject);
        this.teachingDay = teachingDay;
        this.lesson = lesson;
        this.teacherName = teacherName;
        this.room = room;
    }
    // phuong thuc tim subject theo ma mon
    private Subject findSubjectById(String subjectId, ArrayList<Subject> subject) {
        for (Subject s : subject) {
            if (s.getId().equals(subjectId)) {
                return s;
            }
        }
        return null;
    }
    public String getSubjectId() {return this.subject != null ? this.subject.getId() : null;}
    // thứ = nhau, kíp = nhau => nameteacher
    // thứ = nhau, kíp < hơn xếp trc
    // thứ bé hơn xếp trc
    @Override
    public int compareTo(Group o) {
        if(this.teachingDay == o.teachingDay) {
            if(this.lesson == o.lesson) {
                return this.teacherName.compareTo(o.teacherName);
            }
            return this.lesson - o.lesson;
        }
        return this.teachingDay - o.teachingDay;
    }
    @Override
    public String toString() {
        return id + " " + teachingDay + " " + lesson + " " + teacherName + " " + room;
    }
}
