#include<iostream>
using namespace std;

int main()
{
    float rain[3][4];
    float total = 0.0, avg = 0;

    cout << "Enter Rainfall Data for 3 cities in mm\n";

    for (int i = 0; i < 3; i++) {
        cout << "Enter Data for city " << i + 1 << "\n";
        for (int j = 0; j < 4; j++) {
            cout << "Month " << j + 1 << ": ";
            cin >> rain[i][j];
        }
        cout << "\n";
    }

    cout << "Rainfall Tracking\n";
    cout << "S.no.\tCity Name\tMonth 1\t\tMonth 2\t\tMonth 3\t\tMonth 4\t\tAverage Rainfall\n";

    for (int i = 0; i < 3; i++) {
        total = 0;  // Reset total for each city
        cout << i + 1 << "\tCity" << i + 1 << "\t\t";
        for (int j = 0; j < 4; j++) {
            cout << rain[i][j] << "mm\t\t";
            total += rain[i][j];
        }
        avg = total / 4;
        cout << avg << "mm\n";
    }

    return 0;
}
