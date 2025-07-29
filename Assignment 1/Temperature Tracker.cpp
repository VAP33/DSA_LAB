#include<iostream>
using namespace std;

int main() {
    float temp[3][7];
    float total = 0.0, avg = 0;
    float daySum = 0, dayAvg[7];

    cout << "Enter Temperature Data for 3 Cities (7 Days each):\n";

    for (int i = 0; i < 3; i++) {
        cout << "City " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }

    // Pre-compute day-wise averages
    for (int j = 0; j < 7; j++) {
        daySum = 0;
        for (int i = 0; i < 3; i++) {
            daySum += temp[i][j];
        }
        dayAvg[j] = daySum / 3;
    }

    cout << "\nTemperature Tracking:\n";
    cout << "S.no.\tCity Name\tDay 1\tDay 2\tDay 3\tDay 4\tDay 5\tDay 6\tDay 7\tAverage Temp\n";

    for (int i = 0; i < 3; i++) {
        total = 0;
        cout << i + 1 << "\tCity" << i + 1 << "\t\t";
        for (int j = 0; j < 7; j++) {
            cout << temp[i][j] << "\t";
            total += temp[i][j];
        }
        avg = total / 7;
        cout << avg << " °C\n";
    }

    // Print day-wise averages as last row
    cout << "\nDay-wise Average:\t\t";
    for (int j = 0; j < 7; j++) {
        cout << dayAvg[j] << "\t";
    }
    cout << "\n";

    return 0;
}
