#include <iostream>
#include <string>
using namespace std;

class Team {
public:
    Team() {
        for (int j = 0; j < 10; j++) {
            names[j] = "";
        }
        i = 0;
    }

    int counter() {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (!names[j].empty()) {
                count++;
            }
        }
        return count;
    }

    void addMember(string name) {
        if (i < 10) {
            names[i] = name;
            i++;
        }
    }

    void addMember() {
        if (i < 10) {
            names[i] = "Unknown" + to_string(i + 1);
            i++;
        }
    }

    void displayTeam() {
        for (int j = 0; j < 10; j++) {
            if (!names[j].empty()) {
                cout << names[j] << endl;
            }
        }
    }

private:
    string names[10];
    int i; 
};

int main() {
    Team Member;
    Member.addMember("Daivik");
    Member.addMember("Liladhar");
    Member.addMember(); 
    Member.addMember("Karuna");
    Member.addMember(); 
    Member.addMember("pratima");
    Member.addMember("kunal");
    Member.addMember(); 
    Member.addMember("omkar");
    Member.addMember(); 
    cout << "Team Members:" << endl;
    Member.displayTeam();

    return 0;
}
