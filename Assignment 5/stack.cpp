#include <iostream>
#include <string.h>
using namespace std;

class PC {
public:
    char stack[15], y;
    int top = -1;
    int N = 5;

    bool isfull();
    bool isempty();
    void push(char x);
    char pop();
    void display();
    char peek();
};

bool PC::isempty() {
    if (top == -1)
        return true;
    else
        return false;
}

bool PC::isfull() {
    if (top == N - 1)
        return true;
    else
        return false;
}

char PC::peek() {
    if (isempty()) {
        cout << "Empty Stack\n";
        return '\0';
    } else {
        return stack[top];
    }
}

void PC::display() {
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void PC::push(char x) {
    if (isfull()) {
        cout << "Stack is Full!\n";
    } else {
        top++;
        stack[top] = x;
    }
}

char PC::pop() {
    if (isempty()) {
        cout << "Stack is Empty!\n";
        return '\0';
    } else {
        y = stack[top];
        cout << "Popped " << y << endl;
        top--;
        return y;
    }
}

int main() {
    char x;
    string exp;
    PC s;

    cout << "Enter The Expression to be entered: ";
    cin >> exp;

    int l = exp.length();

    // Traversing
    for (int i = 0; i < l; i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            s.push(exp[i]);
            x = s.peek();
        } 
        else if ((exp[i] == '}' && x == '{') || 
                 (exp[i] == ']' && x == '[') || 
                 (exp[i] == ')' && x == '(')) {
            x = s.pop();
            x = s.peek(); // update top after popping
        }
    }

    cout << "Entered Expression is: " << exp << endl;

    if (s.isempty()) {
        cout << "Well Parenthesized!\n";
    } else {
        cout << "Not well parenthesized!\n";
    }

    return 0;
}

