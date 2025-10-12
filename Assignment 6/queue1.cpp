#include <iostream>
using namespace std;

class Queue {
    int A[5];
    int front, rear;
    bool res, ret;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int a);
    void dequeue();
    bool isOverflow();
    bool isUnderflow();
    void disp();
};

bool Queue::isOverflow() {
    if (rear == 4)
        return true;
    else
        return false;
}

bool Queue::isUnderflow() {
    if (front > rear)
        return true;
    else
        return false;
}

void Queue::enqueue(int a) {
    res = isOverflow();
    if (res == true) {
        cout << "Queue Overflow! Customer cannot enter line.\n";
    } else {
        rear = rear + 1;
        A[rear] = a;
        cout << "Customer " << a << " has joined the coffee line.\n";
    }
}

void Queue::dequeue() {
    ret = isUnderflow();
    if (ret == false) {
        cout << "Customer " << A[front] << " has been served and left the line.\n";
        front = front + 1;
    } else {
        cout << "Underflow! No customer in line to serve.\n";
    }
}

void Queue::disp() {
    if (isUnderflow()) {
        cout << "No customers in line.\n";
        return;
    }

    cout << "Current queue: ";
    for (int i = front; i <= rear; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int x, choice;
    char ch;
    Queue Q;

    cout << "---- Coffee Shop Line (Simple Queue) ----" << endl;

    do {
        cout << "\n1. Enqueue (Customer Arrives)\n";
        cout << "2. Dequeue (Customer Served)\n";
        cout << "3. Display Queue\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer ID to Enqueue: ";
            cin >> x;
            Q.enqueue(x);
            break;

        case 2:
            Q.dequeue();
            break;

        case 3:
            Q.disp();
            break;

        default:
            cout << "Invalid choice.\n";
        }

        cout << "Do you wish to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
