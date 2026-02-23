#include <iostream>
using namespace std;

int** construct2DArray(int* original, int originalSize, int m, int n) {
    if (originalSize != m * n) {
        return nullptr;
    }
    
    int** result = new int*[m];
    for (int i = 0; i < m; i++) {
        result[i] = new int[n];
    }
    
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[index];
            index++;
        }
    }
    
    return result;
}

int main() {
    int originalSize, m, n;
    
    cout << "Enter size of original array: ";
    cin >> originalSize;
    
    int* original = new int[originalSize];
    
    cout << "Enter " << originalSize << " elements:" << endl;
    for (int i = 0; i < originalSize; i++) {
        cout << "Element " << i << ": ";
        cin >> original[i];
    }
    
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    
    int** result = construct2DArray(original, originalSize, m, n);
    
    if (result == nullptr) {
        cout << "\nImpossible to create " << m << "x" << n << " array from " 
             << originalSize << " elements." << endl;
        cout << "Empty array returned (conversion not possible)." << endl;
    } else {
        cout << "\n2D Array (" << m << "x" << n << "):" << endl;
        for (int i = 0; i < m; i++) {
            cout << "[";
            for (int j = 0; j < n; j++) {
                cout << result[i][j];
                if (j < n - 1) cout << ",";
            }
            cout << "]";
            if (i < m - 1) cout << endl;
        }
        cout << endl;
        
        for (int i = 0; i < m; i++) {
            delete[] result[i];
        }
        delete[] result;
    }
    
    delete[] original;
    
    return 0;
}