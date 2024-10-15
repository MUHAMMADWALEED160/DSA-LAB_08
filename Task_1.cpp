//Task 1
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int registrationNumber; // Changed variable names for clarity
    string name;
    float cgpa;

public:
    // Default constructor to initialize member variables
    Student() : registrationNumber(0), name(""), cgpa(0.0f) {}

    // Method for inputting student information
    void enterDetails() {
        cout << "Please input Registration Number: ";
        cin >> registrationNumber;
        cout << "Please input Student Name: ";
        cin.ignore(); // Clear newline from the input buffer
        getline(cin, name);
        cout << "Please input CGPA: ";
        cin >> cgpa;
    }

    // Method to display student information
    void showDetails() const {
        cout << "Student Information:" << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Class representing a stack of Student objects
class StudentStack {
private:
    Student* stackArray; // Array to hold Student objects
    int topIndex; // Index of the top element in the stack
    int capacity; // Maximum size of the stack

public:
    // Constructor to allocate memory for the stack
    StudentStack(int size) {
        capacity = size;
        stackArray = new Student[capacity]; // Dynamic array for students
        topIndex = -1; // Stack starts empty
    }

    // Destructor to free allocated memory
    ~StudentStack() {
        delete[] stackArray;
    }

    // Method to add a Student object to the stack
    void push(const Student& student) {
        if (topIndex < capacity - 1) {
            stackArray[++topIndex] = student;
        } else {
            cout << "Stack is full. Unable to add more students!" << endl;
        }
    }

    // Method to remove and display the top Student object from the stack
    void pop() {
        if (topIndex >= 0) {
            cout << "Removing Student Information..." << endl;
            stackArray[topIndex--].showDetails();
        } else {
            cout << "Stack is empty. No student to remove!" << endl;
        }
    }

    // Method to check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }
};

int main() {
    int stackCapacity;

    // Prompt user for the stack size
    cout << "Enter the desired stack size: ";
    cin >> stackCapacity;

    // Create a stack with the specified size
    StudentStack studentStack(stackCapacity);

    int option;
    do {
        cout << "\nMenu Options:\n1. Add Student\n2. Remove Student\n3. Exit\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                // Add a student to the stack
                Student newStudent;
                newStudent.enterDetails();
                studentStack.push(newStudent);
                break;
            }
            case 2:
                // Remove a student from the stack
                studentStack.pop();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid selection. Please try again!" << endl;
        }
    } while (option != 3);

    return 0;
}
