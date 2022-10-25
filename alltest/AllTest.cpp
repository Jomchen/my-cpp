#include<iostream>
#include<cstring>
using namespace std;

class User {
    private:
        string name;
        int age;
    public:
        User() : name("unkown"), age(-999) { cout << "User 无参构造器： " << name << "--" << age << endl; }
        User(string na, int ag) { name = na; age = ag; cout << "User 有参构造器： " << name << "--" << age << endl; }
        ~User() { cout << "User 析构函数：" << name << "--" << age  << endl; }
        string getName() { return name; }
        int getAge() { return age; }
};
class Kongfu {
    private:
        string name;
        int level;
        User user;
    public:
        Kongfu() : name("无名功"), level(-1) { cout << "Kongfu 无参构造器：" << name << "**" << level << endl; }
        Kongfu(string na, int le) { name = na; level = le; cout << "Kongfu 有参构造器：" << name << "**" << level << endl; }
        Kongfu(string kfna, int kfle, string userna, int userag) : user(userna, userag) { name = kfna; level = kfle; cout << "Kongfu 有参构造器：" << name << "**" << level << endl; }
        ~Kongfu() { cout << "Kongfu 析构函数：" << name << "**" << level << endl; }
        string getName() { return name; }
        int getAge() { return level; }
        User getUser() { return user; }
};

/**
 * 所有测试
 */
int main() {
    Kongfu kf("独孤九剑", 999, "独孤求败", 90);
    cout << kf.getUser().getName() << endl;

    return 0;
}