package Code_PTIT.Array_Of_Objects.J05014;

public class Teacher_Recruitment {
    private static int cnt = 1;
    private String name, code, id, subject, result;
    private Float it;
    private Float expertise;
    private double total;
    public Teacher_Recruitment(String name, String code, Float it, Float expertise) {
        this.id = String.format("GV%02d", cnt++);
        this.name = name;
        this.code = code;
        this.it = it;
        this.expertise = expertise;
        this.total = this.it * 2 + this.expertise;

        char s = code.charAt(0);
        if(s == 'A') this.subject = "TOAN";
        else if(s == 'B') this.subject = "LY";
        else if(s == 'C') this.subject = "HOA";

        char c = code.charAt(1);
        if (c == '1') this.total += 2.0;
        else if (c == '2') this.total += 1.5;
        else if (c == '3') this.total += 1.0;

        if (this.total >= 18) this.result = "TRUNG TUYEN";
        else this.result = "LOAI";
    }
    public double getTotal() {
        return total;
    }

    @Override
    public String toString() {
        return id + " " + name + " " + subject + " " + String.format("%.1f", total) + " " + result;
    }
}
