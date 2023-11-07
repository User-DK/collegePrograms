#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFileName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Could not create output file." << endl;
        return 1;
    }

    char currentChar, prevChar = ' ';
    while (inputFile.get(currentChar)) {
        if (currentChar != ' ' || prevChar != ' ') {
            outputFile.put(currentChar);
        }
        prevChar = currentChar;
    }

    inputFile.close();
    outputFile.close();

    cout << "Consecutive spaces removed and saved to " << outputFileName << "." << endl;

    return 0;
}
