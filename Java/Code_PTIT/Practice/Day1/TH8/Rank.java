package Code_PTIT.Practice.Day1.TH8;

public class Rank implements Comparable<Rank>{
    private String name;
    private int correct, submit;

    public Rank(String name, int correct, int submit) {
        this.name = name;
        this.correct = correct;
        this.submit = submit;
    }
    @Override
    public int compareTo(Rank o) {
        if(this.correct == o.correct) {
            if(this.submit == o.submit) {
                return this.name.compareTo(o.name);
            }
            return Integer.compare(this.submit, o.submit);
        }
        return Integer.compare(o.correct, this.correct);
    }
    @Override
    public String toString() {
        return name + " " + correct + " " + submit;
    }
}
