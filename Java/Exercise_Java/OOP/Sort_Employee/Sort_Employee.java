package Exercise_Java.OOP.Sort_Employee;

public class Sort_Employee implements Comparable<Sort_Employee>{
    public static int count = 1;
    private String name, sex, birth, address, code_tax, contract, code;
    private int day, month, year;

    public Sort_Employee(String name, String sex, String birth, String address, String code_tax, String contract) {
        this.code = String.valueOf(count);
        while(this.code.length() < 5){
            this.code = "0" + this.code;
        }
        count++;
        this.name = name;
        this.sex = sex;
        this.birth = birth;
        this.address = address;
        this.code_tax = code_tax;
        this.contract = contract;

        String[] s = birth.split("/");
        this.day = Integer.parseInt(Integer.toString(Integer.parseInt(s[0])));
        this.month = Integer.parseInt(Integer.toString(Integer.parseInt(s[1])));
        this.year = Integer.parseInt(Integer.toString(Integer.parseInt(s[2])));

    }
    public StringBuilder stand(String s){
        String[] words = s.split("/");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            if(x.length() < 2){
                t.append("0");
                t.append(x);
            }
            else
                t.append(x);
            if(x.length() < 4)
                t.append("/");
        }
        return t;
    }
    @Override
    public int compareTo(Sort_Employee o) {
        if(this.year == o.year){
            if(this.month == o.month){
                if(this.day == o.day){
                    return this.code.compareTo(o.code);
                }
                return Integer.compare(this.day, o.day);
            }
            return Integer.compare(this.month, o.month);
        }
        return Integer.compare(this.year, o.year);
    }

    @Override
    public String toString() {
        return code + " " + name + " " + sex + " " + stand(birth) + " " + address + " " + code_tax + " " + stand(contract);
    }
}
