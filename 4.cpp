#include <iostream>
using namespace std;

int diagonalSum(int** matrix, int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    
    for (int i = 0; i < size; i++) {
        sum += matrix[i][size - 1 - i];
    }
    
    if (size % 2 != 0) {
        int center = size / 2;
        sum -= matrix[center][center];
    }
    
    return sum;
}

int main() {
    int size;
    
    cout << "Enter size of square matrix: ";
    cin >> size;
    
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    int sum = diagonalSum(matrix, size);
    cout << "\nSum of diagonals: " << sum << endl;
    
    cout << "\nPrimary diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << matrix[i][i];
        if (i < size - 1) cout << " + ";
    }
    cout << endl;
    
    cout << "Secondary diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << matrix[i][size - 1 - i];
        if (i < size - 1) cout << " + ";
    }
    cout << endl;
    
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
