#include<iostream>
using namespace std;

class C {
    private:
        int dataC;
    public:
        C(int data) : dataC(data) { cout << "C 有参构造函数<" << dataC << ">" << endl; }
        friend class B; // B 为 C 的友元类，所以 B 可以访问 C 的属性
};
class B;
class A {
    private:
        string aname;
        int aage;
    public:
        A() : aname("A无名"), aage(20) { cout << "A 无参构造" << aname << "--" << aage << endl; }
        void printX(const B &b);
};
class B {
    private:
        string bname;
        int bage;
    public:
        B() : bname("B无名"), bage(-20) { cout << "B 无参构造" << bname << "**" << bage << endl; }
        void showC(const C &c) {
            // 因为在 C 中声明了B 为 C 的友元，所以 B 类的方法可以访问 C 的属性
            cout << "我是 B，C 是我的友元类，所以我访问 C 的属性为：" << c.dataC << endl;
        }
        friend void A::printX(const B &b); // A的printX 为 B 的友元函数，所以这个方法体可以访问 b 的属性
};

void A::printX(const B &b) {
    cout << "我是 A，我的 printX 方法是B的友元函数，访问 B 的属性为：" << b.bname << endl;
}


/*
* 友元类，友元类在被访问的类中的声明格式：friend <类名>;
* 友元类的关系是单向的，不能传递
*/
int main() {
    C c = C(1000);
    B b = B();
    A a = A();
    a.printX(b);           // 实验友元函数
    b.showC(c);          // 实验友元类
    return 0;
}