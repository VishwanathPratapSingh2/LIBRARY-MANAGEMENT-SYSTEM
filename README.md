# 📚 Library Management System (C++)

A command-line based Library Management System built in C++ using Object-Oriented Programming. It supports book and student management with file-based data storage.

## 🚀 Features
- Admin & Student login (username/password)
- Add, view, search, issue, return books
- Case-insensitive partial search
- Track issued books per student
- Export available books to file
- Statistics: total, issued, available books
- Persistent data via text files

## 📁 Data Files
- `books.txt`: Book records  
- `students.txt`: Student issue records  
- `credentials.txt`: User login info  

## 🛠️ Compile & Run
g++ main.cpp Book.cpp Student.cpp User.cpp Library.cpp FileManager.cpp -o library.exe
./library.exe
