#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // Include the <iomanip> header for setw

using namespace std;

int main() {
    string inputText;
    int lineCount = 0, wordCount = 0, charCount = 0;

    cout << "Enter text (Press Ctrl+D/Ctrl+Z and Enter to end input):\n";

    while (getline(cin, inputText)) {
        lineCount++;

        // Count characters and words in the current line
        istringstream iss(inputText);
        string word;

        while (iss >> word) {
            wordCount++;
            charCount += word.length();
        }
    }

    // Display the results in two columns
    cout << left << "Lines: " << right << setw(5) << lineCount << endl;
    cout << left << "Words: " << right << setw(5) << wordCount << endl;
    cout << left << "Characters: " << right << setw(5) << charCount << endl;

    return 0;
}
