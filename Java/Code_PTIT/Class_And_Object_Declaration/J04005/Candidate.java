package Code_PTIT.Class_And_Object_Declaration.J04005;

public class Candidate {
    private String name, birth;
    private float total1, total2, total3, sum;

    public Candidate(String name, String birth, float total1, float total2, float total3) {
        this.name = name;
        this.birth = birth;
        this.total1 = total1;
        this.total2 = total2;
        this.total3 = total3;
    }

    @Override
    public String toString() {
        sum = total1 + total2 + total3;
        return name + " " + birth + " " + sum;
    }
}
