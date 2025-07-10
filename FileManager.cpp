#include "FileManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Book> FileManager::loadBooks(const string& filename) {
    vector<Book> books;
    ifstream fin(filename);
    if (!fin) { cerr << "Error: Cannot open " << filename << endl; return books; }
    string line;
    while (getline(fin, line)) books.push_back(Book::fromFileString(line));
    return books;
}

void FileManager::saveBooks(const string& filename, const vector<Book>& books) {
    ofstream fout(filename);
    for (const auto& b : books) fout << b.toFileString() << "\n";
}

vector<User> FileManager::loadUsers(const string& filename) {
    vector<User> users;
    ifstream fin(filename); string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string u, p, r;
        getline(ss, u, ','); getline(ss, p, ','); getline(ss, r, ',');
        users.emplace_back(u, p, r);
    }
    return users;
}

vector<Student> FileManager::loadStudents(const string& filename) {
    vector<Student> s;
    ifstream fin(filename); string line;
    while (getline(fin, line)) s.push_back(Student::fromFileString(line));
    return s;
}

void FileManager::saveStudents(const string& filename, const vector<Student>& s) {
    ofstream fout(filename);
    for (const auto& st : s) fout << st.toFileString() << "\n";
}
