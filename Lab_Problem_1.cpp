#include <iostream>
using namespace std;

void getMaxMin(int numbers[], int size, int &maxVal, int &minVal) {
    maxVal = numbers[0];
    minVal = numbers[0];
    for (int index = 1; index < size; index++) {
        if (numbers[index] > maxVal) {
            maxVal = numbers[index];
        }
        if (numbers[index] < minVal) {
            minVal = numbers[index];
        }
    }
}

int main() {
    int arraySize;
    cout << "Input the size of the array: ";
    cin >> arraySize;

    int elements[arraySize];
    cout << "Input the array elements: ";
    for (int counter = 0; counter < arraySize; counter++) {
        cin >> elements[counter];
    }

    int largest, smallest;
    getMaxMin(elements, arraySize, largest, smallest);

    cout << "Largest Value: " << largest << endl;
    cout << "Smallest Value: " << smallest << endl;

    return 0;
}