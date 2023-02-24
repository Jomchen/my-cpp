#include<iostream>
#include<cstring>
using namespace std;


/**
 * 测试重载运算符，隐藏赋值
 * 
 */


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

class Complex {
    private:
        double real, virt;
    public:
        Complex(double r=0,double v=0) : real(r), virt(v) {
            cout << "有参构造函数：real=" << real << ", virt=" << virt << endl;
        }
        friend Complex operator +(Complex a, Complex b);
        friend ostream & operator << (ostream &out, Complex &a);
};
ostream & operator <<(ostream &out, Complex &a) {
    return out << a.real << " + " << a.virt << "\n";
}
Complex operator+(Complex a, Complex b) {
    return Complex(a.real + b.real, a.virt + b.virt);
}

class Something {
    private:
        int val;
    public:
        Something(int i) {
            val = i;
        }
        operator int();
};
Something::operator int() {
    return val;
}
class Certain : public Something {
    public:
        Certain(int i) : Something(i) {}
};

void test00();
void test01();
/**
 * 所有测试
 */
int main() {
    test00();
    return 0;
}

void test00() {
    Complex a(2,5),b(7,8),c(0,0);
    c = a+b;
    cout << c;
    c = 4.1 + a; // TODO 为什么可以这样相加
    cout << c;
    c = b + 5.6;
    cout << c;

    Certain n(100);
    int i = n; // TODO 隐式调用强转 (int)
    cout << i + n << endl;
}

void test01() {
    Kongfu kf("独孤九剑", 999, "独孤求败", 90);
    cout << kf.getUser().getName() << endl;
}