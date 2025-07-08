package Code_PTIT.Class_And_Object_Declaration.J04013;

import javax.swing.*;

public class Admission {
    private String id, name, state;
    private double totalMath, totalPhysics, totalChemistry, prioritize, totalSum;

    public Admission(String id, String name, double totalMath, double totalPhysics, double totalChemistry) {
        this.id = id;
        this.name = name;
        this.totalMath = totalMath;
        this.totalPhysics = totalPhysics;
        this.totalChemistry = totalChemistry;
    }
    @Override
    public String toString() {
        String area = id.substring(0, 3);
        if(area.equals("KV1")) prioritize = 0.5;
        else if(area.equals("KV2")) prioritize = 1.0;
        else if(area.equals("KV3")) prioritize = 2.5;
        else prioritize = 0.0;
        totalSum = totalMath * 2 + totalPhysics + totalChemistry;
        state = (totalSum + prioritize >= 24) ? "TRUNG TUYEN" : "TRUOT";
        String Prioritize = (prioritize % 1 == 0) ? String.valueOf((int)prioritize) : String.format("%.1f", prioritize);
        String TotalSum = (totalSum % 1 == 0) ? String.valueOf((int)totalSum) : String.format("%.1f", totalSum);
        return String.join(" ", id, name, Prioritize, TotalSum, state);
    }
}
