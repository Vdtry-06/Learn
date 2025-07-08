package Basic_java.School;

public class Student {
    private String name;
    private Double gpa;

    // contractor: 0 doi so
    public Student() {
        name = "No Name";
        gpa = 0.0;
    }

    // contractor: co doi so
    public Student(String name) {
        this.name = name;
    }

    public Student(String name, Double gpa) {
        this.name = name;
        this.gpa = gpa;
    }

    // phuong thuc ko co kieu tra ve
    public void information(){
        System.out.println(name + " " + gpa);
    }

    // phuong thuc co kieu tra ve
    public double counting_DTB(double d1, double d2){
        return (d1 + d2) / 2;
    }
    public double counting_DTB(double d1, double d2, double d3){
        return (d1 + d2 + d3) / 3;
    }
    public double counting_DTB(double d1, double d2, String abc){
        return (d1 + d2) / 2;
    }
    public double counting_DTB(String abc, double d1, double d2){
        return (d1 + d2) / 2;
    }
    public String getName() {
        return name;
    }

    public Double getGpa() {
        return gpa;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setGpa(Double gpa) {
        this.gpa = gpa;
    }

    // toString

    @Override
    public String toString() {
        return name + " " + gpa;
    }
    // support Method and service Method
    // ktra diem thi khi nhap ho so sinh vien
    // support Method
    private boolean checkGpa(){
        return this.gpa >= 24;
    }
    // service Method co the goi chuong trinh chinh
    public void checkGpa_hople(){
        if(checkGpa())
            System.out.println("Diem hop le");
        else
            System.out.println("Diem ko hop le");
    }

    // parametter list
    public double sumd_point(double ... arr){
        double sum = 0.0;
        for(double x: arr){
            sum += x;
        }
        return sum;
    }
}
