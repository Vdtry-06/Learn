package ptit.practice_3.udp.data_type;

import java.io.Serializable;

public class Chracter implements Serializable, Comparable<Chracter> {
    private int id;
    private String text;

    public Chracter(int id, String text) {
        this.id = id;
        this.text = text;
    }

    public String getText() {
        return text;
    }

    @Override
    public int compareTo(Chracter o) {
        return this.id - o.id;
    }
}
