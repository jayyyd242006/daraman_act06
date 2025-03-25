#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

void displayMenu();
void addStudent(Student students[], int &studentCount);
void editStudent(Student students[], int studentCount);
void deleteStudent(Student students[], int &studentCount);
void viewStudents(Student students[], int studentCount);

int main() {
    Student students[100];
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                deleteStudent(students, studentCount);
                break;
            case 4:
                viewStudents(students, studentCount);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n Student Management Menu " << endl;
    cout << "  " << endl; // space
    cout << "[1] Add Student" << endl;
    cout << "[2] Edit Student" << endl;
    cout << "[3] Delete Student" << endl;
    cout << "[4] View Students" << endl;
    cout << "[5] Exit Program" << endl;
}

void addStudent(Student students[], int &studentCount) {
    if (studentCount >= 100) {
        cout << "Student list is full. " << endl;
        return;
    }

    int newID;
    cout << "Enter Student ID: ";
    cin >> newID;
    cin.ignore();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newID) {
            char choice;
            cout << "Student ID already exists. Do you want to use a duplicate ID? (y/n): ";
            cin >> choice;
            cin.ignore();
            if (choice != 'y' && choice != 'Y') {
                return;
            }
            break;
        }
    }

    students[studentCount].id = newID;
    cout << "Enter First Name: ";
    getline(cin, students[studentCount].firstName);
    cout << "Enter Last Name: ";
    getline(cin, students[studentCount].lastName);
    cout << "Enter Course: ";
    getline(cin, students[studentCount].course);
    cout << "Enter GPA: ";
    cin >> students[studentCount].gpa;

    studentCount++;
    cout << "Student added successfully!" << endl;
}

void editStudent(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available to edit. " << endl;
        return;
    }

    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
    cin.ignore();

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found. " << endl;
        return;
    }

    cout << "Enter New First Name: ";
    getline(cin, students[index].firstName);
    cout << "Enter New Last Name: ";
    getline(cin, students[index].lastName);
    cout << "Enter New Course: ";
    getline(cin, students[index].course);
    cout << "Enter New GPA: ";
    cin >> students[index].gpa;

    cout << "Student record updated successfully. " << endl;
}

void viewStudents(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students available. " << endl;
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].lastName > students[j].lastName) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    cout << "\nStudent List (Alphabetical Order): " << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << ": " << students[i].firstName << " " << students[i].lastName << " - " << students[i].course << " (GPA: " << students[i].gpa << ")" << endl;
    }
}

void deleteStudent(Student students[], int &studentCount) {
    if (studentCount == 0) {
        cout << "No students available to delete. " << endl;
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found. " << endl;
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    cout << "Student deleted successfully. " << endl;
}
