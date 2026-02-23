#include <iostream>
using namespace std;


int* sortArray(int *arr, int size) {
    int* result = new int[size];
    
    // Count odd and even numbers
    int oddCount = 0;
    int evenCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            oddCount++;
        } else {
            evenCount++;
        }
    }
    
    // Create temporary arrays for odd and even
    int* oddArr = new int[oddCount];
    int* evenArr = new int[evenCount];
    
    int oddIndex = 0;
    int evenIndex = 0;
    
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            *(oddArr + oddIndex) = *(arr + i);
            oddIndex++;
        } else {
            *(evenArr + evenIndex) = *(arr + i);
            evenIndex++;
        }
    }
    
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (*(oddArr + j) > *(oddArr + j + 1)) {
                int temp = *(oddArr + j);
                *(oddArr + j) = *(oddArr + j + 1);
                *(oddArr + j + 1) = temp;
            }
        }
    }
    
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = 0; j < evenCount - i - 1; j++) {
            if (*(evenArr + j) > *(evenArr + j + 1)) {
                int temp = *(evenArr + j);
                *(evenArr + j) = *(evenArr + j + 1);
                *(evenArr + j + 1) = temp;
            }
        }
    }
    
    int resultIndex = 0;
    for (int i = 0; i < oddCount; i++) {
        *(result + resultIndex) = *(oddArr + i);
        resultIndex++;
    }
    for (int i = 0; i < evenCount; i++) {
        *(result + resultIndex) = *(evenArr + i);
        resultIndex++;
    }
    
    // Free temporary arrays
    delete[] oddArr;
    delete[] evenArr;
    
    return result;
}

// Function to print array using pointer notation
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i);
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    // Dynamically allocate memory for the array
    int* arr = new int[size];
    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);  // Using pointer notation
    }
    
    cout << "\nOriginal array: ";
    printArray(arr, size);
    
    // Sort the array
    int* sortedArr = sortArray(arr, size);
    
    cout << "Sorted array: ";
    printArray(sortedArr, size);
    
    // Free memory
    delete[] arr;
    delete[] sortedArr;
    
    return 0;
}
