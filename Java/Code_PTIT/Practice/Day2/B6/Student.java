package Code_PTIT.Practice.Day2.B6;

public class Student implements Comparable<Student>{
    private String name;
    private int correct;
    private int submit;
    public Student(String name, int correct, int submit) {
        this.name = name;
        this.correct = correct;
        this.submit = submit;
    }
    @Override
    public int compareTo(Student o) {
        if(correct == o.correct) {
            if(submit == o.submit) {
                return name.compareTo(o.name);
            }
            return Integer.compare(submit, o.submit);
        }
        return Integer.compare(o.correct, correct);
    }
    @Override
    public String toString() {
        return name + " " + correct + " " + submit;
    }
}
