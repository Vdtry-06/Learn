package Code_PTIT.Java_Collections_Applications.JKT014;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int [] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Stack<Integer> st = new Stack<>();
            ArrayList<Integer> list = new ArrayList<>();
            list.add(1);
            st.push(0);
            for (int i = 1; i < n; i++) {
                if(a[st.peek()] > a[i]) {
                    list.add(i - st.peek());
                } else {
                    while(!st.empty() && a[st.peek()] <= a[i]) {
                        st.pop();
                    }
                    if(st.empty()) {
                        list.add(i + 1);
                    } else {
                        list.add(i - st.peek());
                    }
                }
                st.push(i);
            }
            for(Integer lst : list) {
                System.out.print(lst + " ");
            }
            System.out.println();
        }
    }
}
