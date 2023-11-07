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

void loadTelephoneData(vector<TelephoneEntry>& entries, const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    entries.clear(); // Clear existing data

    string line;
    while (getline(inputFile, line)) {
        size_t spacePos = line.find_last_of(" ");
        if (spacePos != string::npos && spacePos > 0 && spacePos < line.length() - 1) {
            string name = line.substr(0, spacePos);
            string numberStr = line.substr(spacePos + 1);
            int number = stoi(numberStr);
            TelephoneEntry entry(name, number);
            entries.push_back(entry);
        }
    }

    inputFile.close();
}

void saveTelephoneData(const vector<TelephoneEntry>& entries, const string& fileName) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return;
    }

    for (const TelephoneEntry& entry : entries) {
        outputFile << entry.name << " " << entry.number << endl;
    }

    outputFile.close();
}

int main() {
    vector<TelephoneEntry> entries;
    string fileName;
    loadTelephoneData(entries, "telephone_data.txt"); // Load data from file

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Find telephone number by name" << endl;
        cout << "2. Find name by telephone number" << endl;
        cout << "3. Update telephone number" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline character

        switch (choice) {
            case 1: {
                string nameToFind;
                cout << "Enter the name to find: ";
                getline(cin, nameToFind);
                bool found = false;
                for (const TelephoneEntry& entry : entries) {
                    if (entry.name == nameToFind) {
                        cout << "Telephone number for " << entry.name << ": " << entry.number << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Name not found." << endl;
                }
                break;
            }
            case 2: {
                int numberToFind;
                cout << "Enter the number to find: ";
                cin >> numberToFind;
                bool found = false;
                for (const TelephoneEntry& entry : entries) {
                    if (entry.number == numberToFind) {
                        cout << "Name for number " << entry.number << ": " << entry.name << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Number not found." << endl;
                }
                break;
            }
            case 3: {
                string nameToUpdate;
                int newNumber;
                cout << "Enter the name to update: ";
                cin.ignore(); // Consume newline character
                getline(cin, nameToUpdate);
                cout << "Enter the new number: ";
                cin >> newNumber;
                bool updated = false;
                for (TelephoneEntry& entry : entries) {
                    if (entry.name == nameToUpdate) {
                        entry.number = newNumber;
                        updated = true;
                        break;
                    }
                }
                if (updated) {
                    saveTelephoneData(entries, "telephone_data.txt"); // Save updated data to file
                    cout << "Number updated successfully." << endl;
                } else {
                    cout << "Name not found." << endl;
                }
                break;
            }
            case 4:
                saveTelephoneData(entries, "telephone_data.txt"); // Save data before exiting
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}
