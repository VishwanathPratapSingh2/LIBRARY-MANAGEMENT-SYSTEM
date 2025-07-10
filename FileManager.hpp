#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <vector>
#include <string>
#include "Book.hpp"
#include "Student.hpp"
#include "User.hpp"

class FileManager {
public:
    static std::vector<Book> loadBooks(const std::string&);
    static void saveBooks(const std::string&, const std::vector<Book>&);
    static std::vector<User> loadUsers(const std::string&);
    static std::vector<Student> loadStudents(const std::string&);
    static void saveStudents(const std::string&, const std::vector<Student>&);
};
#endif
