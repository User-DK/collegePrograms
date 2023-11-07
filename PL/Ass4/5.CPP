#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    cout << left << setw(20) << "Name" << right << setw(10) << "Number" << endl;
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl; // Separator line

    string line;

    while (getline(inputFile, line)) {
        size_t spacePos = line.find_last_of(" ");
        if (spacePos != string::npos && spacePos > 0 && spacePos < line.length() - 1) {
            string name = line.substr(0, spacePos);
            string numberStr = line.substr(spacePos + 1);
            int number = stoi(numberStr); // Convert the number string to an integer
            cout << left << setw(20) << name << right << setw(10) << number << endl;
        }
    }

    inputFile.close();

    return 0;
}
