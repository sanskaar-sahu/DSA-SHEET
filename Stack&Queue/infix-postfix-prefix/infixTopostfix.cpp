class Solution {
  public:
   
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }
  
  
    string infixToPostfix(string& s) {
          stack<char> st;
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Operand → directly add to output
            if (isalnum(c)) {
                res += c;
            }

            // Opening bracket → push to stack
            else if (c == '(') {
                st.push(c);
            }

            // Closing bracket → pop till '('
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            }

            // Operator
            else if (isOperator(c)) {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    if (c == '^' && st.top() == '^') break; // handle right associativity
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all remaining operators
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
        
    }
};
