#include <iostream>
#include <vector>
using namespace std;

class Staff {
private:
    string code;
    string name;
    string designation;

public:
    Staff(string _code, string _name, string _designation)
        : code(_code), name(_name), designation(_designation) {}

    string get_code() const { return code; }
    string get_name() const { return name; }
    string get_designation() const { return designation; }

    virtual void displayInfo() const {
        cout << "Code: " << get_code() << "\nName: " << get_name() << "\nDesignation: " << get_designation() << endl;
    }
};

class Teacher : public Staff {
private:
    string subject;
    string publication;

public:
    Teacher(string _code, string _name, string _designation, string _subject, string _publication)
        : Staff(_code, _name, _designation), subject(_subject), publication(_publication) {}

    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Subject: " << subject << "\nPublication: " << publication << endl;
    }
};

class Typist : public Staff {
private:
    string speed;

public:
    Typist(string _code, string _name, string _designation, string _speed)
        : Staff(_code, _name, _designation), speed(_speed) {}

    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Typing Speed: " << speed << endl;
    }
};

class Officer : public Staff {
private:
    string grade;

public:
    Officer(string _code, string _name, string _designation, string _grade)
        : Staff(_code, _name, _designation), grade(_grade) {}

    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Grade: " << grade << endl;
    }
};

class Regular : public Typist {
private:
    int salary;

public:
    Regular(string _code, string _name, string _designation, string _speed, int _salary)
        : Typist(_code, _name, _designation, _speed), salary(_salary) {}

    void displayInfo() const override {
        Typist::displayInfo();
        cout << "Salary: " << salary << endl;
    }
};

class Casual : public Typist {
private:
    int dailyWages;

public:
    Casual(string _code, string _name, string _designation, string _speed, int _dailyWages)
        : Typist(_code, _name, _designation, _speed), dailyWages(_dailyWages) {}

    void displayInfo() const override {
        Typist::displayInfo();
        cout << "Daily Wages: " << dailyWages << endl;
    }
};

int main() {
    vector<Staff*> staffList;

    staffList.push_back(new Teacher("T001", "John Doe", "Professor", "Mathematics", "Advanced Algebra"));
    staffList.push_back(new Regular("R001", "Jane Smith", "Typist", "80 WPM", 30000));
    staffList.push_back(new Officer("O001", "Robert Johnson", "Accountant", "A"));
    staffList.push_back(new Casual("C001", "Ella Brown", "Typist", "60 WPM", 500));

    for (const auto& staff : staffList) {
        staff->displayInfo();
        cout << "--------------------" << endl;
    }

    // Clean up memory
    for (const auto& staff : staffList) {
        delete staff;
    }

    return 0;
}
