package Code_PTIT.Array_Of_Objects.J05054;

import java.io.Serializable;

public class Pair implements Comparable<Pair>, Serializable {
    private static int cnt = 1;
    private String des;
    private String id;
    private int stt;
    private int res;
    public Pair(String des, int stt, int res) {
        this.des = des;
        this.stt = stt;
        this.res = res;
    }
    public int compareTo(Pair o) {
        return stt - o.stt;
    }
    public String toString() {
        id = String.format("HS%02d", cnt++);
        return id + " " + des + " " + res;
    }
}
