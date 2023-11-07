#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main(){
    string email;
    cout << "\nEnter the email Address: ";
    cin >> email;
    int atSymbolCount = 0;
    int dotCount = 0;

    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            atSymbolCount++;
        }
        if (email[i] == '.') {
            dotCount++;
        }
    }

    try {
        if (atSymbolCount == 0) {
            throw std::logic_error("\nEmail Address should contain '@'.");
        } else if (atSymbolCount > 1 || dotCount > 1) {
            throw std::logic_error("\nInvalid Email Address.");
        }
        cout << "\nThe valid Email Address provided is: " << email;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Runtime Error: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << endl;
    }

    return 0;
}
