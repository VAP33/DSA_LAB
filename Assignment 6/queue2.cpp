#include <iostream>
using namespace std;

class CircularQueue {
    int A[5];
    int front, rear;
    bool res, ret;
    int size = 5;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int a);
    void dequeue();
    bool isOverflow();
    bool isUnderflow();
    void disp();
};

bool CircularQueue::isOverflow() {
    if ((rear + 1) % size == front)
        return true;
    else
        return false;
}

bool CircularQueue::isUnderflow() {
    if (front == -1)
        return true;
    else
        return false;
}

void CircularQueue::enqueue(int a) {
    res = isOverflow();
    if (res == true) {
        cout << "Printer Spooler Full! Cannot add more print jobs.\n";
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        A[rear] = a;
        cout << "Print Job " << a << " added to the spooler.\n";
    }
}

void CircularQueue::dequeue() {
    ret = isUnderflow();
    if (ret == true) {
        cout << "No pending print jobs. Spooler is empty.\n";
    } else {
        cout << "Processing and removing Print Job " << A[front] << endl;
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % size;
        }
    }
}

void CircularQueue::disp() {
    if (isUnderflow()) {
        cout << "No print jobs in queue.\n";
        return;
    }

    cout << "Current print queue: ";
    int i = front;
    while (true) {
        cout << A[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    int x, choice;
    char ch;
    CircularQueue Q;

    cout << "---- Printer Spooler (Circular Queue) ----" << endl;

    do {
        cout << "\n1. Add Print Job (Enqueue)\n";
        cout << "2. Process Print Job (Dequeue)\n";
        cout << "3. Display Print Queue\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Print Job ID: ";
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
