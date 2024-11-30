#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

int performBinarySearch(int sortedArray[], int totalElements, int searchElement) {
    int start = 0, end = totalElements - 1;

    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (sortedArray[middle] == searchElement) {
            return middle;
        } else if (sortedArray[middle] > searchElement) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    return -1;
}

int main() {
    int sz;
    cout << "Enter the total number of elements: ";
    cin >> sz;

    int a[sz];
    cout << "Enter the elements of the array: ";
    for (int i= 0; i < sz; i++) {
        cin >> a[i];
    }

    sort(a, a + sz);

    int x;
    cout << "Enter the value to search: ";
    cin >> x;

    int searchResult = performBinarySearch(a,sz, x);

    if (searchResult != -1) {
        cout << "Value found at position: " << searchResult << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}