#include "Library.hpp"
#include "FileManager.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

Library::Library(string b, string s, string c) : bookFile(b), studentFile(s), credentialsFile(c) {}
void Library::loadData() {
    books = FileManager::loadBooks(bookFile);
    students = FileManager::loadStudents(studentFile);
    users = FileManager::loadUsers(credentialsFile);
}
void Library::saveData() {
    FileManager::saveBooks(bookFile, books);
    FileManager::saveStudents(studentFile, students);
}
User* Library::login(const string& u, const string& p) {
    for (auto& user : users) if (user.authenticate(u, p)) return new User(user);
    return nullptr;
}
void Library::addBook() {
    int id;
    string t, a, g;
    cout << "Enter Book ID: "; cin >> id; cin.ignore();
    cout << "Enter Title: "; getline(cin, t);
    cout << "Enter Author: "; getline(cin, a);
    cout << "Enter Genre: "; getline(cin, g);

    for (auto& b : books)
        if (b.getId() == id) {
            cout << "Book ID exists." << endl;
            return;
        }

    books.emplace_back(id, t, a, g, false);  // ✅ Fixed here
    cout << "Book added." << endl;
}
void Library::showAllBooks() const {
    if (books.empty()) cout << "No books."<<endl;
    for (const auto& b : books) b.display();
}
void Library::searchBook() const {
    string kw; cin.ignore(); cout << "Keyword: "; getline(cin, kw);
    string k = kw; transform(k.begin(), k.end(), k.begin(), ::tolower);
    for (const auto& b : books) {
        string t = b.getTitle(), a = b.getAuthor(), g = b.getGenre();
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(g.begin(), g.end(), g.begin(), ::tolower);
        if (t.find(k) != string::npos || a.find(k) != string::npos || g.find(k) != string::npos) b.display();
    }
}
void Library::issueBook(const string& u) {
    int id; cout << "Book ID: "; cin >> id;
    for (auto& b : books) {
        if (b.getId() == id && !b.getStatus()) {
            for (auto& s : students) {
                if (s.getUsername() == u) {
                    s.issueBook(id); b.issue(); 
                    cout << "Issued."<< endl; 
                    return;
                }
            }
            Student s(u); s.issueBook(id); students.push_back(s); b.issue(); 
            cout << "Issued."<< endl; return;
        }
    }
    cout << "Not available."<<endl;
}
void Library::returnBook(const string& u) {
    int id; cout << "Return Book ID: "; cin >> id;
    for (auto& s : students) {
        if (s.getUsername() == u && s.hasBook(id)) {
            s.returnBook(id);
            for (auto& b : books) if (b.getId() == id) b.returnBook();
            cout << "Returned."<<endl; return;
        }
    }
    cout << "You don’t have this book."<<endl;
}
void Library::showStudentBooks(const string& u) const {
    for (const auto& s : students) {
        if (s.getUsername() == u) {
            for (int id : s.getIssuedBooks())
                for (const auto& b : books) if (b.getId() == id) b.display();
            return;
        }
    }
}
void Library::showStatistics() const {
    int total = books.size(), issued = 0;
    for (const auto& b : books) if (b.getStatus()) issued++;
    cout << "Total: " << total << ", Issued: " << issued << ", Available: " << total - issued << endl;
}
void Library::exportAvailableBooks(const string& f) const {
    ofstream fout(f); for (const auto& b : books) if (!b.getStatus()) fout << b.toFileString() << endl;
    cout << "Exported to " << f << endl;
}
