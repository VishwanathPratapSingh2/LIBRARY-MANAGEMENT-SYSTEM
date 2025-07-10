#ifndef USER_HPP
#define USER_HPP
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    User();
    User(string username, string password, string role);
    string getUsername() const;
    string getRole() const;
    bool authenticate(const string& inputUsername, const string& inputPassword) const;
};
#endif
