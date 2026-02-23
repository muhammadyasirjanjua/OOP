#include <iostream>
using namespace std;


char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}

// Function to check if character is a letter
bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int countRepeatedLetters(char* word) {
    int freq[26] = {0};
    
    // Count frequency of each letter
    int i = 0;
    while (word[i] != '\0') {
        if (isLetter(word[i])) {
            char ch = toLower(word[i]);
            freq[ch - 'a']++;
        }
        i++;
    }
    
    // Count total repeated letters
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            count += (freq[i] - 1);
        }
    }
    
    return count;
}

int main() {
    int size;
    
    cout << "Enter the maximum size of the string: ";
    cin >> size;
    
    // Dynamically allocate memory for the string
    char* str = new char[size];
    
    cout << "Enter a string: ";
    cin.getline(str, size);
    
    // Allocate memory for result word
    char* maxWord = new char[size];
    maxWord[0] = '\0';
    int maxRepeated = 0;
    
    int start = 0;
    for (int i = 0; i <= size; i++) {
        // Found end of word or end of string
        if (str[i] == ' ' || str[i] == '\0' || !isLetter(str[i])) {
            
            int wordLen = i - start;
            if (wordLen > 0) {
                char* word = new char[wordLen + 1];
                
                for (int j = 0; j < wordLen; j++) {
                    word[j] = str[start + j];
                }
                word[wordLen] = '\0';
                
                // Count repeated letters
                int repeated = countRepeatedLetters(word);
                if (repeated > maxRepeated) {
                    maxRepeated = repeated;
                    
                
                    for (int j = 0; j <= wordLen; j++) {
                        maxWord[j] = word[j];
                    }
                }
                
                delete[] word;
            }
            
            start = i + 1;
        }
        
        if (str[i] == '\0') break;
    }
    
    // Print result
    if (maxRepeated > 0) {
        cout << "Word which has the highest number of repeated letters: " << maxWord << endl;
    } else {
        cout << "No word with repeated letters found." << endl;
    }
    
 //free nemory
    delete[] str;
    delete[] maxWord;
    
    return 0;
}