#include "Book.hpp"
#include <iostream>
#include <sstream>
using namespace std;

Book::Book() : id(0), title(""), author(""), genre(""), isIssued(false) {}
Book::Book(int id, string t, string a, string g, bool i) : id(id), title(t), author(a), genre(g), isIssued(i) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getGenre() const { return genre; }
bool Book::getStatus() const { return isIssued; }

void Book::issue() { isIssued = true; }
void Book::returnBook() { isIssued = false; }

void Book::display() const {
    cout << "ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Genre: " << genre
         << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
}

string Book::toFileString() const {
    return to_string(id) + "|" + title + "|" + author + "|" + genre + "|" + to_string(isIssued);
}

Book Book::fromFileString(const string& line) {
    stringstream ss(line);
    string idStr, title, author, genre, statusStr;
    getline(ss, idStr, '|'); getline(ss, title, '|'); getline(ss, author, '|'); getline(ss, genre, '|'); getline(ss, statusStr, '|');
    return Book(stoi(idStr), title, author, genre, stoi(statusStr));
}
