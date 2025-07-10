#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
using namespace std;

class Book {
    int id;
    string title, author, genre;
    bool isIssued;

public:
    Book();
    Book(int, string, string, string, bool);
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    string getGenre() const;
    bool getStatus() const;
    void issue();
    void returnBook();
    void display() const;
    string toFileString() const;
    static Book fromFileString(const string&);
};
#endif
