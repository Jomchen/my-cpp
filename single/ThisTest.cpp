#include<iostream>
using namespace std;

class User;
void fun(User u); 
void fun1(User &u);
class User {
    private:
        string username;
    public:
        User() { cout << "User 无参构造函数" << endl; }
        User(string u) : username(u) { cout << "User 有参构造函数" << endl; }
        User(const User &u) { username = u.username; cout << "拷贝方法" << endl; }
        ~User() { cout << "User 被销毁了" << endl; }
        User acquireUser();
        void setUsername(string u) { username = u; }
        string getUsername() { return username; }
        friend void fun(User u);
        friend void fun1(User &u);
};

User User::acquireUser() {
    return *this;
}
void fun(User u) {}
void fun1(User &u) {}

/*
* this 指针
*/
int main() {

    User u = User("Linux");
    User u2 = u.acquireUser(); // 会调用拷贝方法
    cout << "u.username: " << u.getUsername() << "-- u2.username: " << u2.getUsername() << endl;
    u2.setUsername("Java");
    cout << "u.username: " << u.getUsername() << "-- u2.username: " << u2.getUsername() << endl;
    cout << "the address of u: " << &u << "---- the address of u2: " << &u2 << endl;

    cout << "*******************************" << endl;
    fun(u); // 这会调用拷贝构造器，以拷贝给实参
    fun1(u); // 这个传的是引用，所以不会拷贝
    return 0;
}