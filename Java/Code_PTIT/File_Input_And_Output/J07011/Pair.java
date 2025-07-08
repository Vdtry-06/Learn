package Code_PTIT.File_Input_And_Output.J07011;

public class Pair implements Comparable<Pair> {
    private String s;
    private int cnt;
    public Pair(String s, int cnt) {
        this.s = s;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(Pair o) {
        if(this.cnt == o.cnt) {
            return this.s.compareTo(o.s);
        }
        return o.cnt - this.cnt;
    }

    @Override
    public String toString() {
        return s + " " + cnt;
    }
}
