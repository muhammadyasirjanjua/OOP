#include <iostream>
using namespace std;


int* resizeArray(int* arr, int& capacity) {
    int newCapacity = capacity * 2;
    
    // Allocate new array with larger capacity
    int* newArr = new int[newCapacity];
    
for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }
    
    // Delete old array
    delete[] arr;
    
    // Update capacity
    capacity = newCapacity;
    
    cout << "Array resized! New capacity: " << capacity << endl;
    
    return newArr;
}

// Function to print array
void printArray(int* arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int initialCapacity;
    
    cout << "Enter initial capacity of the array: ";
    cin >> initialCapacity;
    
    // Dynamically allocate initial array
    int* arr = new int[initialCapacity];
    int capacity = initialCapacity;
    int size = 0; // Current number of elements
    
    cout << "Enter integers (enter -1 to stop):" << endl;
    
    int value;
    while (true) {
        cout << "Enter value: ";
        cin >> value;
        
        // Check for sentinel value
        if (value == -1) {
            break;
        }
        
        // Check if array is full
        if (size == capacity) {
            cout << "Array is full! Resizing..." << endl;
            arr = resizeArray(arr, capacity);
        }
        
        // Add element to array
        arr[size] = value;
        size++;
        
        cout << "Element added. Current size: " << size << "/" << capacity << endl;
    }
    
    // Display final array
    cout << "\n--- Final Array ---" << endl;
    cout << "Total elements: " << size << endl;
    cout << "Final capacity: " << capacity << endl;
    printArray(arr, size);
    
    // Free memory
    delete[] arr;
    
    return 0;
}

