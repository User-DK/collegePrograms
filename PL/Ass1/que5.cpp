#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Student {
public:
    std::string name;
    int ID;
    std::string studentClass;
    char grade;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<std::string, char>>;
    std::vector<MyPair> studentInfo;

    void Add(int id, const std::string& name, const std::string& studentClass, char grade) {
        MyPair pair1 = std::make_pair(std::make_pair(name, id), std::make_pair(studentClass, grade));
        studentInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = studentInfo.begin(); it != studentInfo.end(); ++it) {
            if (it->first.second == id) {
                studentInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, const std::string& newClass, char newGrade) {
        for (auto& element : studentInfo) {
            if (element.first.second == id) {
                element.first.first = name;
                element.second.first = newClass;
                element.second.second = newGrade;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : studentInfo) {
            if (element.first.second == id) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tClass: " << element.second.first
                          << "\tGrade: " << element.second.second << std::endl;
                break;
            }
        }
    }
};

class Teacher {
    public:
    std::string name;
    int ID;
    std::string subject;
    double salary;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<std::string, double>>;
    std::vector<MyPair> teacherInfo;

    void Add(int id, const std::string& name, const std::string& subject, double salary) {
        MyPair pair1 = std::make_pair(std::make_pair(name, ID), std::make_pair(subject, salary));
        teacherInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = teacherInfo.begin(); it != teacherInfo.end(); ++it) {
            if (it->first.second == id) {
                teacherInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, const std::string& newSubject, double newSalary) {
        for (auto& element : teacherInfo) {
            if (element.first.second == id) {
                element.first.first = name;
                element.second.first = newSubject;
                element.second.second = newSalary;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : teacherInfo) {
            if (element.first.second == id) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tSubject: " << element.second.first
                          << "\tSalary: " << element.second.second << std::endl;
                break;
            }
        }
    }
};
    
class Course {
private:
    std::string name;
    int ID;
    int assignedTeacherID;
    std::vector<int> studentIDs;

    using MyPair = std::pair<std::pair<std::string, int>, std::pair<int, std::vector<int>>>;
    std::vector<MyPair> courseInfo;

public:
    void Add(const std::string& name, int id, int teacherID, const std::vector<int>& students) {
        MyPair pair1 = std::make_pair(std::make_pair(name, ID), std::make_pair(assignedTeacherID, studentIDs));
        courseInfo.push_back(pair1);
    }

    void Remove(int id) {
        for (auto it = courseInfo.begin(); it != courseInfo.end(); ++it) {
            if (it->first.second == ID) {
                courseInfo.erase(it);
                break;
            }
        }
    }

    void Update(int id, int teacherID, const std::vector<int>& students) {
        for (auto& element : courseInfo) {
            if (element.first.second == ID) {
                element.first.first = name;
                element.second.first = teacherID;
                element.second.second = students;
                break;
            }
        }
    }

    void Fetch(int id) {
        for (const auto& element : courseInfo) {
            if (element.first.second == ID) {
                std::cout << "\nName: " << element.first.first
                          << "\tID: " << element.first.second
                          << "\tAssigned Teacher ID: " << element.second.first
                          << "\tEnrolled Student IDs: ";
                for (int studentID : element.second.second) {
                    std::cout << studentID << " ";
                }
                std::cout << std::endl;
            }
        }
    }


};



int main(){
    std::cout<<"Welcome to the School Management System\nSelect any one option\n";
    while (true) {
        std::cout << "1. Student Management System\n";
        std::cout << "2. Teacher Management System\n";
        std::cout << "3. Course Management\n";
        std::cout << "4. Exit\n";
        int choice1;
        std::cin >> choice1;

        switch (choice1) {
                case 1:
                
                while (true) {
                    Student studentManager;
                    std::cout << "Student Management:\n";
                    std::cout << "1. Add Student\n";
                    std::cout << "2. Remove Student\n";
                    std::cout << "3. Update Student\n";
                    std::cout << "4. Fetch Student Details\n";
                    std::cout << "5. Exit\n";
                    int choice;
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            int id;
                            std::string name;
                            std::string studentClass;
                            char grade;

                            std::cout << "Enter Student ID: ";
                            std::cin >> id;

                            std::cout << "Enter Student Name: ";
                            std::cin >> name;

                            std::cout << "Enter Class: ";
                            std::cin >> studentClass;

                            std::cout << "Enter Grade: ";
                            std::cin >> grade;

                            Student newStudent;
                            newStudent.ID = id;
                            newStudent.name = name;
                            newStudent.studentClass = studentClass;
                            newStudent.grade = grade;

                            studentManager.Add(id, name, studentClass, grade);
                            std::cout << "Student added successfully.\n";
                            break;
                        }
                        case 2: {
                            int id;
                            std::cout << "Enter Student ID to Remove: ";
                            std::cin >> id;

                            studentManager.Remove(id);
                            std::cout << "Student removed successfully.\n";
                            break;
                        }
                        case 3: {
                            int id;
                            std::string newClass;
                            char newGrade;

                            std::cout << "Enter Student ID to Update: ";
                            std::cin >> id;

                            std::cout << "Enter Updated Class: ";
                            std::cin >> newClass;

                            std::cout << "Enter Updated Grade: ";
                            std::cin >> newGrade;

                            studentManager.Update(id, newClass, newGrade);
                            std::cout << "Student updated successfully.\n";
                            break;
                        }
                        case 4: {
                            int id;
                            std::cout << "Enter Student ID to Fetch Details: ";
                            std::cin >> id;

                            studentManager.Fetch(id);
                            break;
                        }
                        case 5:
                            return false;
                        default:
                            std::cout << "Invalid choice\n";
                    }
                }
                

                break;
                
                
                case 2:
                        while (true) {
                            Teacher teacherManager;
                    std::cout << "Teacher Management:\n";
                    std::cout << "1. Add Teacher\n";
                    std::cout << "2. Remove Teacher\n";
                    std::cout << "3. Update Teacher\n";
                    std::cout << "4. Fetch Teacher Details\n";
                    std::cout << "5. Exit\n";
                    int choice;
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            int id;
                            std::string name;
                            std::string subject;
                            double salary;

                            std::cout << "Enter Teacher ID: ";
                            std::cin >> id;

                            std::cout << "Enter Teacher Name: ";
                            std::cin >> name;

                            std::cout << "Enter Subject: ";
                            std::cin >> subject;

                            std::cout << "Enter Salary: ";
                            std::cin >> salary;

                            Teacher newTeacher;
                            newTeacher.ID = id;
                            newTeacher.name = name;
                            newTeacher.subject = subject;
                            newTeacher.salary = salary;

                            teacherManager.Add(id, name, subject, salary);
                            std::cout << "Teacher added successfully.\n";
                            break;
                        }
                        case 2: {
                            int id;
                            std::cout << "Enter Teacher ID to Remove: ";
                            std::cin >> id;

                            teacherManager.Remove(id);
                            std::cout << "Teacher removed successfully.\n";
                            break;
                        }
                        case 3: {
                            int id;
                            std::string newSubject;
                            double newSalary;

                            std::cout << "Enter Teacher ID to Update: ";
                            std::cin >> id;

                            std::cout << "Enter Updated Subject: ";
                            std::cin >> newSubject;

                            std::cout << "Enter Updated Salary: ";
                            std::cin >> newSalary;

                            teacherManager.Update(id, newSubject, newSalary);
                            std::cout << "Teacher updated successfully.\n";
                            break;
                        }
                        case 4: {
                            int id;
                            std::cout << "Enter Teacher ID to Fetch Details: ";
                            std::cin >> id;

                            teacherManager.Fetch(id);
                            break;
                        }
                        case 5:
                            return 0;
                        default:
                            std::cout << "Invalid choice\n";
                    }
                }
                break;
                case 3:while (true) {
                    Course courseManager;
                    std::cout << "1. Add Course\n";
                    std::cout << "2. Remove Course\n";
                    std::cout << "3. Update Course\n";
                    std::cout << "4. Fetch Course Details\n";
                    std::cout << "5. Exit\n";
                    int choice;
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            std::string name;
                            int id, teacherID;
                            std::vector<int> studentIDs;

                            std::cout << "Enter Course Name: ";
                            std::cin >> name;

                            std::cout << "Enter Course ID: ";
                            std::cin >> id;

                            std::cout << "Enter Assigned Teacher ID: ";
                            std::cin >> teacherID;

                            int studentCount;
                            std::cout << "Enter number of enrolled students: ";
                            std::cin >> studentCount;
                            studentIDs.resize(studentCount);
                            std::cout << "Enter Student IDs: ";
                            for (int i = 0; i < studentCount; ++i) {
                                std::cin >> studentIDs[i];
                            }

                            courseManager.Add(name, id, teacherID, studentIDs);
                            break;
                        }
                        case 2: {
                            int id;
                            std::cout << "Enter Course ID to Remove: ";
                            std::cin >> id;
                            courseManager.Remove(id);
                            break;
                        }
                        case 3: {
                            int id, teacherID;
                            std::vector<int> studentIDs;

                            std::cout << "Enter Course ID to Update: ";
                            std::cin >> id;

                            std::cout << "Enter Updated Assigned Teacher ID: ";
                            std::cin >> teacherID;

                            int studentCount;
                            std::cout << "Enter updated number of enrolled students: ";
                            std::cin >> studentCount;
                            studentIDs.resize(studentCount);
                            std::cout << "Enter Updated Student IDs: ";
                            for (int i = 0; i < studentCount; ++i) {
                                std::cin >> studentIDs[i];
                            }

                            courseManager.Update(id, teacherID, studentIDs);
                            break;
                        }
                        case 4: {
                            int id;
                            std::cout << "Enter Course ID to Fetch Details: ";
                            std::cin >> id;
                            courseManager.Fetch(id);
                            break;
                        }
                        case 5:
                            return false;
                        default:
                            std::cout << "Invalid choice\n";
                    }
}
                break;
                case 4:return false;
                break;
                default:
                std::cout<<"Invalid choice";
                break;
        }}
        return 0;}

