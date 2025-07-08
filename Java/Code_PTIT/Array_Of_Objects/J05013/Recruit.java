package Code_PTIT.Array_Of_Objects.J05013;

public class Recruit {
    private static int cnt = 1;
    private String name, id, result;
    private float theory;
    private float practice;
    private float average;
    public Recruit(String name, float practice, float theory) {
        this.name = name;
        this.practice = practice > 10 ? practice / 10 : practice;
        this.theory = theory > 10 ? theory / 10 : theory;
        this.id = String.format("TS%02d", cnt++);
        this.average = (this.practice + this.theory) / 2;
        if (this.average >= 9.5) this.result = "XUAT SAC";
        else if (this.average >= 8) this.result = "DAT";
        else if (this.average >= 5) this.result = "CAN NHAC";
        else this.result = "TRUOT";
    }
    public float getAverage() {
        return this.average;
    }
    @Override
    public String toString() {
        return id + " " + name + " " + String.format("%.2f", average) + " " + result;
    }
}
