package Code_PTIT.Array_Of_Objects.J05062;

public class Student {
    private String name;
    private float gpa;
    private int tp;
    private String type;
    private int idx;
    private String result;
    public Student(String name, float gpa, int tp, int idx) {
        this.name = name;
        this.gpa = gpa;
        this.tp = tp;
        this.idx = idx;
        this.type = "KHONG";
        this.result = "KHONG";
        if(gpa >= 3.6) {
            if(tp >= 90) this.type = "XUATSAC";
            else if(tp >= 80) this.type = "GIOI";
            else if(tp >= 70) this.type = "KHA";
            else if(tp >= 60) this.type = "KHONG";
        }
        else if(gpa >= 3.2) {
            if(tp >= 80) this.type = "GIOI";
            else if(tp >= 70) this.type = "KHA";
            else if(tp >= 60) this.type = "KHONG";
        }
        else if(gpa >= 2.5) {
            if(tp >= 70) this.type = "KHA";
            else if(tp >= 60) this.type = "KHONG";
        }
    }

    public Float getGpa() {return gpa;}

    public String getType() {return type;}

    public int getIdx() {return idx;}

    public String getResult() {return result;}

    public void setResult(String result) {this.result = result;}

    public String toString() {
        return name;
    }
}
