#include <iostream>
using namespace std;

int findlargest(int **matrix, int rows, int columns) {
    int largest = matrix[0][0];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (*(*(matrix + i) + j) > largest) {
                largest = *(*(matrix + i) + j);
            }
        }
    }
    
    return largest;
}

int main() {
    int rows, columns;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    int largest = findlargest(matrix, rows, columns);
    cout << "\nLargest element in the matrix: " << largest << endl;
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}