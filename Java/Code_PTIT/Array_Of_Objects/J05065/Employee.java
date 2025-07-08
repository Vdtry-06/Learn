package Code_PTIT.Array_Of_Objects.J05065;

import java.io.Serializable;
import java.util.TreeMap;

public class Employee implements Comparable<Employee>, Serializable {
    private String id;
    private String name;
    private String pos;
    private String salary;
    private String apart;
    public Employee(String id, String name, TreeMap<String, Integer> treeMap) {
        this.id = id;
        this.pos = id.substring(0, 2);

        treeMap.putIfAbsent(this.pos, 0);
        treeMap.put(this.pos, treeMap.get(this.pos) + 1);

        if((this.pos.equals("GD") && treeMap.get(this.pos) > 1)
                || (this.pos.equals("TP") && treeMap.get(this.pos) > 3)
                || (this.pos.equals("PP") && treeMap.get(this.pos) > 3)
        ) this.pos = "NV";

        this.salary = id.substring(2, 4);
        this.apart = id.substring(4);
        this.name = name;
    }
    public String getPos() {
        return pos;
    }

    public int compareTo(Employee o) {
        if(o.salary.equals(this.salary)) {
            return this.apart.compareTo(o.apart);
        }
        return o.salary.compareTo(this.salary);
    }

    public String toString() {
        return name + " " + pos + " " + apart + " " + salary;
    }

}
