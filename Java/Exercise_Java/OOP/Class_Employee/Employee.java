package Exercise_Java.OOP.Class_Employee;

import java.util.Locale;

public class Employee {
    private String name, sex, birth, address, id, contract, code;

    public Employee(String name, String sex, String birth, String address, String id, String contract) {
        this.name = name;
        this.sex = sex;
        this.birth = birth;
        this.address = address;
        this.id = id;
        this.contract = contract;
        this.code = "00001";
    }
    public static StringBuilder process(String s){
        String[] words = s.split("/");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            if(x.length() < 2){
                t.append("0");
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4){
                t.append("/");
            }
        }
        return t;
    }
    public static StringBuilder process2(String s){
        s = s.toLowerCase();
        String[] words = s.split(" ");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            x = x.substring(0, 1).toUpperCase() + x.substring(1);
            t.append(x);
            t.append(" ");

        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    @Override
    public String toString() {
        return code + " " + process2(name) + " " + sex + " " + process(birth) + " " + address + " " + id + " " + process(contract);
    }
}
