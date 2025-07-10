#include "Library.hpp"
#include <iostream>
using namespace std;

int main() {
    Library lib("books.txt", "students.txt", "credentials.txt");
    lib.loadData();

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User* user = lib.login(username, password);
    if (!user) {
        cout << "Invalid credentials. Exiting." << endl;
        return 0;
    }

    string role = user->getRole();
    if (role == "admin") {
        int choice;
        do {
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Book\n2. Show All Books\n3. Search Book\n4. Issue Book\n";
            cout << "5. Return Book\n6. View Student's Issued Books\n7. Show Statistics\n";
            cout << "8. Export Available Books\n9. Exit\nEnter choice: ";
            cin >> choice;
            string input;
            switch (choice) {
                case 1: lib.addBook(); break;
                case 2: lib.showAllBooks(); break;
                case 3: lib.searchBook(); break;
                case 4: cout << "Student username: "; cin >> input; lib.issueBook(input); break;
                case 5: cout << "Student username: "; cin >> input; lib.returnBook(input); break;
                case 6: cout << "Student username: "; cin >> input; lib.showStudentBooks(input); break;
                case 7: lib.showStatistics(); break;
                case 8: cout << "Export filename: "; cin >> input; lib.exportAvailableBooks(input); break;
                case 9: lib.saveData(); break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 9);
    } else {
        int choice;
        do {
            cout << "\nStudent Menu:\n";
            cout << "1. View Books\n2. Search Book\n3. Issue Book\n4. Return Book\n";
            cout << "5. My Issued Books\n6. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: lib.showAllBooks(); break;
                case 2: lib.searchBook(); break;
                case 3: lib.issueBook(user->getUsername()); break;
                case 4: lib.returnBook(user->getUsername()); break;
                case 5: lib.showStudentBooks(user->getUsername()); break;
                case 6: lib.saveData(); break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 6);
    }

    delete user;
    return 0;
}
