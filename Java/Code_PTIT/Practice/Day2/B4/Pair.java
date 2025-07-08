package Code_PTIT.Practice.Day2.B4;

public class Pair<fi, se> {
    private fi first;
    private se second;
    public Pair(fi first, se second) {
        this.first = first;
        this.second = second;
    }
    public fi getFirst() {
        return first;
    }
    public se getSecond() {
        return second;
    }
    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }
}
