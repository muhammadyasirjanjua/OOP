#include <iostream>
using namespace std;

int getLength(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to check if subseq is a subsequence of main string
int isSubsequence(char* mainStr, char* subseq) {
    int mainLen = getLength(mainStr);
    int subLen = getLength(subseq);
    
    int i = 0; 
    int j = 0; 
    
    // Traverse both strings
    while (i < mainLen && j < subLen) {
        if (mainStr[i] == subseq[j]) {
            j++;
        }
        i++;
    }
    
    // If all characters of subseq are found, return 1
    if (j == subLen) {
        return 1;
    }
    return 0;
}

int main() {
    int size1, size2;
    
    cout << "Enter the maximum size for main string: ";
    cin >> size1;
    cin.ignore(); // Clear newline
    
    // Dynamically allocate memory for main string
    char* mainStr = new char[size1];
    
    cout << "Enter the main string: ";
    cin.getline(mainStr, size1);
    
    cout << "Enter the maximum size for subsequence: ";
    cin >> size2;
    cin.ignore();
    
    // Dynamically allocate memory for subsequence
    char* subseq = new char[size2];
    
    cout << "Enter the subsequence: ";
    cin.getline(subseq, size2);
    
    // Check if subseq is a subsequence of mainStr
    int result = isSubsequence(mainStr, subseq);
    
    cout << "Output: " << result << endl;
    
    // Free memory
    delete[] mainStr;
    delete[] subseq;
    
    return 0;
}