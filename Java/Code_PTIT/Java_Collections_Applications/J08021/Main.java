package Code_PTIT.Java_Collections_Applications.J08021;

import java.util.Scanner;
import java.util.Stack;

import static java.lang.Integer.max;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0) {
            String s = sc.nextLine();
            Stack<Integer> st = new Stack<>();
            st.push(-1);
            int mx = 0;
            for(int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if(c == '(') {
                    st.push(i);
                }
                else {
                    st.pop();
                    if(!st.isEmpty()) {
                        mx = max(mx, i - st.peek());
                    }
                    else {
                        st.push(i);
                    }
                }
            }
            System.out.println(mx);
        }
    }
}
