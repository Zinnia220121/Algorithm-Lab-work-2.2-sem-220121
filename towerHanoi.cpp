#include <iostream>
using namespace std;

void towerHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    towerHanoi(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    towerHanoi(n - 1, B, A, C);
}

int main() {
    int n;  // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // Call the function with 'A' as source, 'B' as auxiliary, and 'C' as destination
    towerHanoi(n, 'A', 'B', 'C');

    return 0;
}
