#include "User.hpp"

User::User() : username(""), password(""), role("student") {}
User::User(string username, string password, string role) : username(username), password(password), role(role) {}

string User::getUsername() const { return username; }
string User::getRole() const { return role; }

bool User::authenticate(const string& inputUsername, const string& inputPassword) const {
    return (username == inputUsername && password == inputPassword);
}
