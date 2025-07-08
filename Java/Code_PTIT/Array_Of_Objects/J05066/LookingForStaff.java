package Code_PTIT.Array_Of_Objects.J05066;

public class LookingForStaff implements Comparable<LookingForStaff>{
    private String code, name;
    private String position, salary, id;

    public LookingForStaff(String code, String name) {
        this.code = code;
        this.name = name;
        position = code.substring(0, 2);
        salary = code.substring(2, 4);
        id = code.substring(4);
        checkPosition();
    }

    private void checkPosition() {
        if(position.equals("GD") && Integer.parseInt(id) > 1
                || position.equals("TP") && Integer.parseInt(id) > 3
                || position.equals("PP") && Integer.parseInt(id) > 3) {
            position = "NV";
        }
    }

    public boolean isContain(String tmp) {
        return name.toLowerCase().contains(tmp);
    }

    @Override
    public int compareTo(LookingForStaff a) {
        if (this.salary.compareTo(a.salary) == 0) {
            return this.id.compareTo(a.id);
        }
        return a.salary.compareTo(this.salary);
    }

    @Override
    public String toString() {
        return name + " " + position + " " + id + " " + salary;
    }
}
