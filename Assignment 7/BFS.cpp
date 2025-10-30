#include <iostream>
using namespace std;

const int MAXNODES = 10;
int adjacencymatrix[MAXNODES][MAXNODES];
bool visited[MAXNODES];

// Manual queue implementation
class Queue {
    int front, rear;
    int items[MAXNODES];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int value) {
        if (rear == MAXNODES - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        items[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return items[front++];
    }
};

// BFS Function
void BFS(int start, int n) {
    Queue q;
    visited[start] = true;
    q.enqueue(start);

    cout << "BFS Traversal: ";

    while (!q.isEmpty()) {
        int node = q.dequeue();
        cout << node << " ";

        // Visit all adjacent unvisited nodes
        for (int i = 0; i < n; i++) {
            if (adjacencymatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.enqueue(i);
            }
        }
    }
    cout << endl;
}

int main() {
    cout << "~~~~~~~~ BFS (Without STL) ~~~~~~~~" << endl;
    int n, start, end;
    char choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacencymatrix[i][j] = 0;
        }
        visited[i] = false;
    }

    // Input edges
    cout << "Enter the edges of the graph:\n";
    do {
        cout << "Enter Start Node: ";
        cin >> start;
        cout << "Enter End Node: ";
        cin >> end;

        // For undirected graph
        adjacencymatrix[start][end] = 1;
        adjacencymatrix[end][start] = 1;

        cout << "Do you wish to enter more edges? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Display adjacency matrix
    cout << "\nThe Final Adjacency Matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencymatrix[i][j] << " ";
        }
        cout << endl;
    }

    int startNode;
    cout << "\nEnter the starting node for BFS: ";
    cin >> startNode;

    // Perform BFS traversal
    BFS(startNode, n);

    cout << "Traversal complete.\n";
    return 0;
}

