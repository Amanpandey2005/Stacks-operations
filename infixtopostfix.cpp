#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Main function to convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // 1. If the character is an operand (a-z, A-Z, 0-9), add it to output
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            res += c;
        }
        // 2. If the character is an '(', push it to the stack
        else if (c == '(') {
            st.push('(');
        }
        // 3. If the character is an ')', pop and output from the stack 
        // until an '(' is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // Pop the '('
            }
        }
        // 4. If an operator is scanned
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string expression = "(a-b/c)*(a/k-l)";
    cout << "Infix:   " << expression << endl;
    cout << "Postfix: " << infixToPostfix(expression) << endl;
    return 0;
}