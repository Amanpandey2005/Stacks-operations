#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // For reverse()

using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '-' || c == '+') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPrefix(string s) {
    // 1. Reverse the infix expression
    reverse(s.begin(), s.end());

    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        // 2. If operand, add to result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        } 
        // 3. If closing bracket (originally opening), push to stack
        else if (s[i] == ')') {
            st.push(s[i]);
        } 
        // 4. If opening bracket (originally closing), pop until ')'
        else if (s[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } 
        // 5. If operator
        else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // 6. Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // 7. Reverse the final result to get Prefix
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string expression = "(a-b/c)*(a/k-l)";
    cout << "Infix:  " << expression << endl;
    cout << "Prefix: " << infixToPrefix(expression) << endl;
    return 0;
}