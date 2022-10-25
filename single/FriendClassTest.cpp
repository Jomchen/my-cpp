#include<iostream>
using namespace std;

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
        friend void A::printX(const B &b); // A的printX 为 B 的友元函数，所以这个方法体可以访问 b 的属性
};
void A::printX(const B &b) {
    // 因为此方法是属于A所以 可以访问A的属性；因为此方法在B中声明为它的友元函数，所以可以访问B的属性
    cout << aname << "<<<>>>" << b.bname << endl;
}

/*
* 友元类，友元类在被访问的类中的声明格式：friend <类名>;
* 友元类的关系是单向的，不能传递
*/
int main() {
    B b = B();
    A a = A();
    a.printX(b);
    return 0;
}