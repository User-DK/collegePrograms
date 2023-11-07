#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

template <class T, class U, class V>
class Node
{
public:
    T data1;
    U data2;
    V data3;
    Node *next;

    Node(const T &value1, const U &value2, const V &value3) : data1(value1), data2(value2), data3(value3), next(nullptr) {}
};

template <class T, class U, class V>
class LinkedList
{
public:
    LinkedList() : head(nullptr) {}

    void insert(const T &value1, const U &value2, const V &value3)
    {
        Node<T, U, V> *newNode = new Node<T, U, V>(value1, value2, value3);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T, U, V> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display()
    {
        Node<T, U, V> *current = head;
        while (current != nullptr)
        {
            std::cout << "ID: " << current->data1 << ", Name: " << current->data2 << ", GPA: " << current->data3 << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList()
    {
        Node<T, U, V> *current = head;
        while (current != nullptr)
        {
            Node<T, U, V> *next = current->next;
            delete current;
            current = next;
        }
    }

private:
    Node<T, U, V> *head;
};

class Student
{
public:
    int Student_ID;
    std::string Student_name;
    float GPA;

    Student(int id, const std::string &name, float gpa)
        : Student_ID(id), Student_name(name), GPA(gpa) {}
};

class Course
{
public:
    std::string Course_code;
    std::string Course_name;
    std::string Instructor_name;

    Course(const std::string &code, const std::string &name, const std::string &instructor)
        : Course_code(code), Course_name(name), Instructor_name(instructor) {}
};

int main()
{
    LinkedList<int, std::string, float> studentList;
    LinkedList<std::string, std::string, std::string> courseList;

    std::cout << "Welcome to Student and Course Management System" << std::endl;
    while (true)
    {
        int choice;
        std::cout << "Menu:\n1. Add a student\n2. Add a course\n3. Display students\n4. Display courses\n5. Quit\nEnter your choice: ";
        try
        {
            std::cin >> choice;

            if (std::cin.fail())
            {
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                throw std::invalid_argument("Invalid input. Please enter a valid integer.");
            }
            switch (choice)
            {
            case 1:
            {
                int studentID;
                std::string studentName;
                float gpa;
                std::cout << "Enter Student ID: ";
                std::cin >> studentID;
                std::cout << "Enter Student Name: ";
                std::cin >> studentName;
                std::cout << "Enter GPA: ";
                std::cin >> gpa;
                studentList.insert(studentID, studentName, gpa);
                break;
            }
            case 2:
            {
                std::string courseCode;
                std::string courseName;
                std::string instructorName;
                std::cout << "Enter Course Code: ";
                std::cin >> courseCode;
                std::cout << "Enter Course Name: ";
                std::cin >> courseName;
                std::cout << "Enter Instructor Name: ";
                std::cin >> instructorName;
                courseList.insert(courseCode, courseName, instructorName);
                break;
            }
            case 3:
                std::cout << "Students:\n";
                studentList.display();
                break;
            case 4:
                std::cout << "Courses:\n";
                courseList.display();
                break;
            case 5:
                std::cout << "Quitting the program." << std::endl;
                return 0;
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
