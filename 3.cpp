#include <iostream>
using namespace std;

int countNegatives(int** grid, int rows, int columns) {
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] < 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int rows, columns;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    
    int** grid = new int*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new int[columns];
    }
    
    cout << "Enter grid elements (sorted in non-increasing order):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> grid[i][j];
        }
    }
    
    cout << "\nGrid:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < columns; j++) {
            cout << grid[i][j];
            if (j < columns - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    int negativeCount = countNegatives(grid, rows, columns);
    cout << "\nNumber of negative numbers: " << negativeCount << endl;
    
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;
    
    return 0;
}
