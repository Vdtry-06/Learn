package ptit.tcp._47u3NSOk;

import java.io.Serializable;

public class Characture implements Serializable, Comparable<Characture> {
    private int len;
    private int stt;
    private String val;

    public Characture(int len, int stt, String val) {
        this.len = len;
        this.stt = stt;
        this.val = val;
    }

    public String getVal() {
        return val;
    }

    @Override
    public int compareTo(Characture o) {
        if (this.len == o.len) {
            return this.stt - o.stt;
        }
        return this.len - o.len;
    }
}
