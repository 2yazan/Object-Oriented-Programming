// Create a class to work with a one-dimensional array of integers. Develop the following class elements:
    // a. Fields:
        // int *ptr; // Pointer to the array
        // int n; // Size of the array
    // b. Constructor:
        // A constructor that allows you to create an array of size n.
    // c. Methods:
        // A method to input array elements from the keyboard.
        // A method to output array elements to the screen.
        // A method to sort array elements in ascending order.
    // d. Overload (override):
        // Subtraction, combined with assignment.
        // Logical negation (NOT).


#include <iostream>
#include <windows.h>

using namespace std;

class Array {
private:
    int *ptr;
    int n;

public:
    Array(int size) : n(size) {
        ptr = new int[n];
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cin >> ptr[i];
        }
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    void sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ptr[j] > ptr[j + 1]) {
                    int temp = ptr[j];
                    ptr[j] = ptr[j + 1];
                    ptr[j + 1] = temp;
                }
            }
        }
    }

    Array& operator-=(int value) {
        for (int i = 0; i < n; i++) {
            ptr[i] -= value;
        }
        return *this;
    }

    friend Array operator!(const Array& arr) {
        Array result(arr.n);
        for (int i = 0; i < arr.n; i++) {
            result.ptr[i] = !arr.ptr[i];
        }
        return result;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Array arr(size);
    arr.input();

    cout << "Array: ";
    arr.output();

    arr.sort();

    cout << "After sorting: ";
    arr.output();

    int subtractValue;
    cout << "Enter the number to subtract from each element: ";
    cin >> subtractValue;

    arr -= subtractValue;

    cout << "After subtraction: ";
    arr.output();

    Array negatedArray = !arr;

    cout << "Negated array: ";
    negatedArray.output();

    return 0;
}