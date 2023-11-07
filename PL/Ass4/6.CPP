#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TelephoneEntry {
public:
    string name;
    int number;

    TelephoneEntry() : name(""), number(0) {}

    TelephoneEntry(string n, int num) : name(n), number(num) {}
};

int main() {
    string fileName;
    vector<TelephoneEntry> entries;

    cout << "Enter the name of the data file: ";
    cin >> fileName;

    cin.ignore(); // Consume the newline character left in the input buffer

    while (true) {
        string name;
        int number;

        cout << "Enter a name (or 'quit' to exit): ";
        getline(cin, name);

        if (name == "quit") {
            break;
        }

        cout << "Enter a number: ";
        cin >> number;
        cin.ignore(); // Consume the newline character left in the input buffer

        TelephoneEntry entry(name, number);
        entries.push_back(entry);
    }

    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    for (const TelephoneEntry& entry : entries) {
        outputFile << entry.name << " " << entry.number << endl;
    }

    outputFile.close();

    cout << "Data written to " << fileName << "." << endl;

    return 0;
}
