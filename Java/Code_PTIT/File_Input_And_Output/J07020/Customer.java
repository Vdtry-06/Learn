package Code_PTIT.File_Input_And_Output.J07020;

public class Customer {
    private static int cnt = 1;
    private String id;
    private String name;
    private String sex;
    private String birth;
    private String address;

    public Customer(String name, String sex, String birth, String address) {
        this.id = String.format("KH%03d", cnt++);
        this.name = name;
        this.sex = sex;
        this.birth = birth;
        this.address = address;
    }
    public String getId() {
        return id;
    }
    @Override
    public String toString() {
        return name + " " + address;
    }
}
