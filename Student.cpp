#include "Student.hpp"
#include <sstream>
#include <algorithm>

Student::Student() {}
Student::Student(string username) : username(username) {}

string Student::getUsername() const { return username; }

void Student::issueBook(int id) { if (!hasBook(id)) issuedBookIds.push_back(id); }

void Student::returnBook(int id) {
    issuedBookIds.erase(remove(issuedBookIds.begin(), issuedBookIds.end(), id), issuedBookIds.end());
}

vector<int> Student::getIssuedBooks() const { return issuedBookIds; }

bool Student::hasBook(int id) const {
    return find(issuedBookIds.begin(), issuedBookIds.end(), id) != issuedBookIds.end();
}

string Student::toFileString() const {
    string line = username;
    for (int id : issuedBookIds) line += "|" + to_string(id);
    return line;
}

Student Student::fromFileString(const string& line) {
    stringstream ss(line); string token;
    getline(ss, token, '|');
    Student s(token);
    while (getline(ss, token, '|')) s.issueBook(stoi(token));
    return s;
}
