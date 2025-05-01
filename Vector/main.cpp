#include <iostream>
using namespace std;

class Vector {
private:
    int size;
    int capacity;
    int* arr;

public:
    // Parameterized constructor
    Vector(int size)
        : size(size > 0 ? size : 0),
        capacity(size > 0 ? 2 * size : 1),
        arr(new int[capacity]) {
    }

    // Default constructor
    Vector() : size(0), capacity(1), arr(new int[1]) {}

    // Destructor to free memory
    ~Vector() {
        delete[] arr;
    }

    // Function to add elements to the vector
    void push_back(int num) {
        if (capacity == size) {
            capacity *= 2;
            int* arr2 = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr2[i] = arr[i];
            }
            delete[] arr;
            arr = arr2;
        }
        arr[size++] = num;
    }

    // Delete all elements (reset vector)
    void Delete() {
        delete[] arr;
        arr = new int[1]; // Reinitialize with capacity 1
        size = 0;
        capacity = 1;
    }

    int Size() const { return size; }
    int GetFirst() const { return size > 0 ? arr[0] : -1; }
    int GetLast() const { return size > 0 ? arr[size - 1] : -1; }

    void Print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector v1;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(8);
    v1.Print();           // Output: 2 4 6 8
    cout << v1.GetFirst() << endl; // Output: 2
    cout << v1.GetLast() << endl;  // Output: 8
    cout << v1.Size() << endl;     // Output: 4
    v1.Delete();
    cout << v1.Size() << endl;     // Output: 0
}
