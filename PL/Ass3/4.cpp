#include <iostream>
#include <vector>
#include <string>

class Person {
private:
    std::string name;
    int age;
    int ID;

public:
    Person(std::string _name, int _age, int _ID)
        : name(_name), age(_age), ID(_ID) {}

    void displayDetails() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nID: " << ID << std::endl;
    }

    void modifyDetails(std::string newName, int newAge) {
        name = newName;
        age = newAge;
    }
};

class Student : public Person {
private:
    std::string major;
    float GPA;

public:
    Student(std::string _name, int _age, int _ID, std::string _major, float _GPA)
        : Person(_name, _age, _ID), major(_major), GPA(_GPA) {}

    void registerCourse(std::string courseName) {
        std::cout << "Registered for course: " << courseName << std::endl;
    }

    void viewRegisteredCourses() const {
        std::cout << "Viewing registered courses..." << std::endl;
    }

    void calculateAcademicStanding() const {
        std::cout << "Calculating academic standing..." << std::endl;
    }
};

class Professor : public Person {
private:
    std::string department;
    std::vector<std::string> coursesTaught;

public:
    Professor(std::string _name, int _age, int _ID, std::string _department)
        : Person(_name, _age, _ID), department(_department) {}

    void addCourseToTeach(std::string courseName) {
        coursesTaught.push_back(courseName);
    }

    void listCoursesBeingTaught() const {
        std::cout << "Courses being taught:" << std::endl;
        for (const auto& course : coursesTaught) {
            std::cout << "- " << course << std::endl;
        }
    }

    void adviseStudent(const Student& student) const {
        student.displayDetails();
        std::cout << "Hypothetical advice based on GPA..." << std::endl;
    }
};

class AdminStaff : public Person {
private:
    std::string jobTitle;

public:
    AdminStaff(std::string _name, int _age, int _ID, std::string _jobTitle)
        : Person(_name, _age, _ID), jobTitle(_jobTitle) {}

    void sendAnnouncement(std::string message) const {
        std::cout << "Announcement sent: " << message << std::endl;
    }

    void attendMeeting(std::string summary) const {
        std::cout << "Meeting attended. Summary: " << summary << std::endl;
    }
};

class University {
private:
    std::vector<Student> students;
    std::vector<Professor> professors;
    std::vector<AdminStaff> adminStaff;

public:
    void addStudent(Student student) {
        students.push_back(student);
    }

    void addProfessor(Professor professor) {
        professors.push_back(professor);
    }

    void addAdminStaff(AdminStaff staff) {
        adminStaff.push_back(staff);
    }

    // Add more methods to interact with university roles
};

int main() {
    // Create instances of different roles
    Student student("John Doe", 20, 1234, "Computer Science", 3.7);
    Professor professor("Dr. Smith", 45, 5678, "Physics");
    AdminStaff staff("Alice Brown", 35, 9876, "Registrar");

    // Create a university instance and add roles
    University university;
    university.addStudent(student);
    university.addProfessor(professor);
    university.addAdminStaff(staff);

    // Display information from the database
    std::cout << "University Database Information:" << std::endl;

    // Display student information
    std::cout << "\nStudent Information:" << std::endl;
    student.displayDetails();
    student.viewRegisteredCourses();
    student.calculateAcademicStanding();

    // Display professor information
    std::cout << "\nProfessor Information:" << std::endl;
    professor.displayDetails();
    professor.listCoursesBeingTaught();
    professor.adviseStudent(student);

    // Display admin staff information
    std::cout << "\nAdmin Staff Information:" << std::endl;
    staff.displayDetails();
    staff.sendAnnouncement("Welcome back to a new semester!");
    staff.attendMeeting("Meeting regarding upcoming events.");

    return 0;
}


