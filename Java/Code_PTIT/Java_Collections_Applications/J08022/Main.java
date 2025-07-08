package Code_PTIT.Java_Collections_Applications.J08022;

import java.io.IOException;
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            Stack<Integer> st = new Stack<>();
            ArrayList<Integer> list = new ArrayList<>();
            ArrayList<Integer> res = new ArrayList<>();
            while (n-- > 0) list.add(sc.nextInt());

            st.push(list.get(list.size() - 1));
            res.add(-1);

            for(int i = list.size() - 2; i >= 0; i--) {
                if(list.get(i) < st.peek()) {
                    res.add(st.peek());
                } else {
                    while(!st.empty() && list.get(i) >= st.peek()) {
                        st.pop();
                    }
                    if(st.empty()) res.add(-1);
                    else res.add(st.peek());
                }
                st.push(list.get(i));
            }
            for(int i = res.size() - 1; i >= 0; i--) {
                System.out.print(res.get(i) + " ");
            }
            System.out.println();
        }
    }
}
