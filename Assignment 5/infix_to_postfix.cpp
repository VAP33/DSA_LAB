#include <iostream>
#include <string>
#define N 10
using namespace std;

class Stack {
public:
    char arr[N];
    int top;

    Stack() { top = -1; }

    void push(char c) {
        if (top == N - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = c;
    }

    char pop() {
        if (top == -1)
            return ' '; // Underflow
        return arr[top--];
    }

    char peek() {
        if (top == -1)
            return ' ';
        return arr[top];
    }

    int precedence(char opr) {
        if (opr == '*' || opr == '/')
            return 2;
        else if (opr == '+' || opr == '-')
            return 1;
        else
            return 0;
    }

    string InfixToPostfixConversion(string ex);
};

// Function to convert Infix to Postfix
string Stack::InfixToPostfixConversion(string ex) {
    string postfix = "";
    for (int i = 0; i < ex.length(); i++) {
        char ch = ex[i];

        // Operand
        if (isalnum(ch)) {
            postfix += ch;
        }
        // Opening parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix += pop();
            }
            pop(); // Remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(ch) <= precedence(peek())) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix += pop();
    }

    return postfix;
}

int main() {
    Stack s;
    string ex;

    cout << "Enter an infix expression: ";
    cin >> ex;

    string postfix = s.InfixToPostfixConversion(ex);
    cout << "\nPostfix Expression: " << postfix << endl;

    return 0;
}
