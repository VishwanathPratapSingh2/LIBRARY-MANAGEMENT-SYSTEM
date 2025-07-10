#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <vector>
#include <string>
#include "Book.hpp"
#include "User.hpp"
#include "Student.hpp"

class Library {
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Student> students;
    std::string bookFile, studentFile, credentialsFile;

public:
    Library(std::string, std::string, std::string);
    void loadData();
    void saveData();
    User* login(const std::string&, const std::string&);
    void addBook();
    void showAllBooks() const;
    void searchBook() const;
    void issueBook(const std::string&);
    void returnBook(const std::string&);
    void showStudentBooks(const std::string&) const;
    void showStatistics() const;
    void exportAvailableBooks(const std::string&) const;
};
#endif
