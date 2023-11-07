#include <iostream>
using namespace std;

class PrintData {
public:
    int print(int a) {
        return a;
    }

    double print(double a) {
        return a;
    }

    string print(string a) {
        return a;
    }
};

int main() {
    PrintData data;
    
    while (true) {
        cout << "\nWelcome\nEnter the Option:\na.Print Integer\nb.Print Double\nc.Print String\nd.Exit";
        char a;
        cin >> a;

        switch (a) {
            case 'a': {
                int i;
                cout << "\nEnter an Integer: ";
                cin >> i;
                cout << data.print(i);
                break;
            }
            case 'b': {
                double d;
                cout << "\nEnter a Double: ";
                cin >> d;
                cout << data.print(d);
                break;
            }
            case 'c': {
                string s;
                cout << "\nEnter a String: ";
                cin >> s;
                cout << data.print(s);
                break;
            }
            case 'd': {
                cout << "\nExiting the program.";
                return 0;
            }
            default: {
                cout << "Invalid option. Please select a valid option.";
                break;
            }
        }
    }

    return 0;
}
