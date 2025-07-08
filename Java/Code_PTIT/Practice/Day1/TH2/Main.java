package Code_PTIT.Practice.Day1.TH2;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int [] a = new int[m];
        for(int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
        }
        String errors = process(a, m);
        ArrayList<Integer> correct = new ArrayList<>();
        int idx = 1;
        for(int i = 0; i < m; ++i) {
            while(idx < a[i]) {
                correct.add(idx);
                idx++;
            }
            idx++;
        }
        while(idx <= n) {
            correct.add(idx);
            idx++;
        }
        int[] correctArray = new int[correct.size()];
        for(int i = 0; i < correct.size(); i++) {
            correctArray[i] = correct.get(i);
        }
        String Correct = process(correctArray, correctArray.length);
        System.out.println("Errors: " + errors);
        System.out.println("Correct: " + Correct);
    }

    public static void appendRange(StringBuilder res, int st, int en) {
        if(res.length() > 0) res.append(", ");
        if(st == en) res.append(st);
        else {
            res.append(st).append("-").append(en);
        }
    }

    public static String process(int [] a, int s) {
        StringBuilder res = new StringBuilder();
        int st = a[0];
        int en = a[0];
        for(int i = 1; i < s; i++) {
            if(a[i] == en + 1) {
                en = a[i];
            }
            else {
                appendRange(res, st, en);
                st = a[i];
                en = a[i];
            }
        }
        appendRange(res, st, en);
        int ls = res.lastIndexOf(",");
        if(ls != -1) res.replace(ls, ls + 1, " and");
        return res.toString();
    }
}
