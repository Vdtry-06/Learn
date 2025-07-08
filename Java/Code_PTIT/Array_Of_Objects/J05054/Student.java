package Code_PTIT.Array_Of_Objects.J05054;

import java.io.Serializable;
import java.util.LinkedHashMap;

public class Student implements Comparable<Student>, Serializable {
    private static int cnt = 1;
    private String name;
    private float avg;
    private String type;
    private int stt;
    private int fre;
    public Student(String name, float avg, LinkedHashMap<Float, Integer> map) {
        this.name = name;
        this.avg = avg;
        this.type = processType(avg);
        this.stt = cnt++;
        this.fre = map.getOrDefault(avg, 0) + 1;
        map.put(avg, this.fre);
    }

    public int getFre() {
        return fre;
    }
    public int getStt() {
        return stt;
    }

    public int compareTo(Student o) {
        return Float.compare(o.avg, this.avg);
    }

    private String processType(float avg) {
        String res = "";
        if(avg < 5) res = "Yeu";
        else if(avg >= 5 && avg < 7) res = "Trung Binh";
        else if(avg >= 7 && avg < 9) res = "Kha";
        else res = "Gioi";
        return res;
    }

    public String toString() {
        return name + " " + avg + " " + type;
    }

}
