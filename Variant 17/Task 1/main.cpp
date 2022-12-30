#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 30;

int n;
int originalArray[MAX_N];
int reversedArray[MAX_N];
int sortedArray[MAX_N];

void input() {
    cout << "Enter the number of elements in the array (N < " << MAX_N << "): ";
    cin >> n;

    if (n < 1 || n > MAX_N) {
        cout << "Invalid input! Please try again." << endl;
        return;
    }

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> originalArray[i];
    }
}

void reverse_array() {
    for (int i = 0; i < n; i++) {
        reversedArray[i] = originalArray[n - i - 1];
    }
}

void sort_array() {
    cout << "Enter 1 to sort in ascending order, or 2 to sort in descending order: ";
    int option;
    cin >> option;

    for (int i = 0; i < MAX_N; ++i) {
        sortedArray[i] = originalArray[i];
    }

    if (option == 1) {
        sort(sortedArray, sortedArray + n);
    } else if (option == 2) {
        sort(sortedArray, sortedArray + n, greater<int>());
    } else {
        cout << "Invalid input! Please try again." << endl;
        return;
    }
}

void print_arrays() {
    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << originalArray[i] << " ";
    }
    cout << endl;

    cout << "Array with elements in reverse order: " << endl;
    for (int i = 0; i < n; i++) {
        cout << reversedArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Input array" << endl;
        cout << "2. Reverse array" << endl;
        cout << "3. Sort array" << endl;
        cout << "4. Print arrays" << endl;
        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            input();
        } else if (choice == 2) {
            reverse_array();
        } else if (choice == 3) {
            sort_array();
        } else if (choice == 4) {
            print_arrays();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
    }
    return 0;
}
