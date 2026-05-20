/*

  Name    : Moiz Rizwan 
  Sap Id  :70173658
  Section :BSSE-V







*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  
using namespace std;

// all functions that are useing in this program are written here
bool teacherLogin();
void menu();
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();


// the main function 
int main() {
    system("cls");  // for clearning the screen 
    if (teacherLogin()) {
        menu(); // Only show menu after login
    } else {
        cout << "Access Denied now Program is closing.\n";
    }
    return 0;
}

// here teacher login to do activtes 
bool teacherLogin() {
    string username, password;
cout << "                        ================= Student Management System ==========================\n";
    cout << "                                   =========== Teacher Login ==========\n\n";
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    if (username == "teacher" && password == "12345") {  // here the usrname an password to acess
        cout << "Login successful!\n";
        system("pause");
        system("cls");  // hor Clear screen 
        return true;
    } else {
        cout << "Invalid username or password!\n";
        return false;
    }
}

void menu() {
    int choice;
    do {
        cout << "===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Delete Student by Roll No\n";
        cout << "5. Exit\n";
        cout << "Choose option (1-5): ";
        cin >> choice;
        system("cls");  // Clear before showing each section 

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewStudents();
        else if (choice == 3)
            searchStudent();
        else if (choice == 4)
            deleteStudent();
        else if (choice == 5)
            cout << "Exiting Program.\n";
        else
            cout << "Invalid choice! Try again.\n";

        if (choice != 5) {
            system("pause"); // Wait for user to press a key
            system("cls");   // Then clear again
        }

    } while (choice != 5);
}

// for adding students 
void addStudent() {
    ofstream file("students.txt", ios::app);
    string name;
    int roll;
    float marks;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Marks: ";
    cin >> marks;

    file << name << " " << roll << " " << marks << endl;
    file.close();

    cout << "Student record added successfully.\n";
}

// desplaying the students in this function
void viewStudents() {
    ifstream file("students.txt");
    string name;
    int roll;
    float marks;

    cout << "=== All Student Records ===\n";

    while (file >> name >> roll >> marks) {
        cout << "Name: " << name << ", Roll No: " << roll << ", Marks: " << marks << endl;
    }

    file.close();
}

// in this function  u can search student by roll number
void searchStudent() {
    ifstream file("students.txt");
    string name;
    int roll, searchRoll;
    float marks;
    bool found = false;

    cout << "Enter Roll No to Search: ";
    cin >> searchRoll;

    while (file >> name >> roll >> marks) {
        if (roll == searchRoll) {
            cout << "Record Found:\n";
            cout << "Name: " << name << ", Roll No: " << roll << ", Marks: " << marks << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found!\n";

    file.close();
}

// here u can delete the student details
void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string name;
    int roll, delRoll;
    float marks;
    bool found = false;

    cout << "Enter Roll No to Delete: ";
    cin >> delRoll;

    while (file >> name >> roll >> marks) {
        if (roll != delRoll) {
            temp << name << " " << roll << " " << marks << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student record deleted successfully.\n";
    else
        cout << "Student not found!\n";
}
