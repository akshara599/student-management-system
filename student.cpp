#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }
};

vector<Student> students;

// 🔹 Add Student
void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student added successfully!\n";
}

// 🔹 View All Students
void viewStudents() {
    if (students.empty()) {
        cout << "No records found!\n";
        return;
    }

    for (auto &s : students) {
        s.display();
    }
}

// 🔹 Search Student
void searchStudent() {
    int roll;
    cout << "Enter roll to search: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.roll == roll) {
            cout << "Student found:\n";
            s.display();
            return;
        }
    }
    cout << "Student not found!\n";
}

// 🔹 Update Student
void updateStudent() {
    int roll;
    cout << "Enter roll to update: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.roll == roll) {
            cout << "Enter new details:\n";
            s.input();
            cout << "Updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// 🔹 Delete Student
void deleteStudent() {
    int roll;
    cout << "Enter roll to delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll == roll) {
            students.erase(students.begin() + i);
            cout << "Deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// 🔹 Main Menu
int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}