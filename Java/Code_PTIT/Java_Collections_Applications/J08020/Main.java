package Code_PTIT.Java_Collections_Applications.J08020;


import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0) {
            String s = sc.nextLine();
            Stack<String> st = new Stack<>();
            boolean check = true;
            for(char c : s.toCharArray()) {
                if(c == '(' || c == '{' || c == '[') {
                    st.push(String.valueOf(c));
                }
                else if((c == ')' && !st.isEmpty() && st.peek().equals("(")) ||
                        (c == '}' && !st.isEmpty() && st.peek().equals("{")) ||
                        (c == ']' && !st.isEmpty() && st.peek().equals("["))) {
                    st.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            if(!st.isEmpty() || !check) {
                System.out.println("NO");
            }
            else {
                System.out.println("YES");
            }
        }
    }
}
