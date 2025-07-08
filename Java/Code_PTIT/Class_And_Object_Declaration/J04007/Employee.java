package Code_PTIT.Class_And_Object_Declaration.J04007;

public class Employee {
    private String name, sex, birth, address, mst, date_Agreement, mnv;

    public Employee(String name, String sex, String birth, String address, String mst, String date_Agreement) {
        this.name = name;
        this.sex = sex;
        this.birth = birth;
        this.address = address;
        this.mst = mst;
        this.date_Agreement = date_Agreement;
    }

    @Override
    public String toString() {
        mnv = "00001";
        return mnv + " " + name + " " + sex + " " + birth + " " + address + " " + mst + " " + date_Agreement;
    }
}
