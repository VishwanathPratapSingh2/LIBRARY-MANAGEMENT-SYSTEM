#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <vector>
using namespace std;

class Student {
    string username;
    vector<int> issuedBookIds;

public:
    Student();
    Student(string username);
    string getUsername() const;
    void issueBook(int);
    void returnBook(int);
    vector<int> getIssuedBooks() const;
    bool hasBook(int) const;
    string toFileString() const;
    static Student fromFileString(const string&);
};
#endif
