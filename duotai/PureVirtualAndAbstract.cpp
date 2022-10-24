#include<iostream>

using namespace std;

class A {
     public:
        A() { cout << "A--" << endl; }
};
class B : virtual public A { // 声明B是类A的公用派生类，A是B的基类
     public:
        B() { cout << "B--" << endl; }
};
class C : virtual public A { // 声明类C是类A的公用派生类，A是C的虚基类
     public:
        C() { cout << "C--" << endl; }
};


/**
 * 纯虚函数和抽象类
 * 纯虚函数在声明时要在函数原型的后面赋0，其声明格式如下：
 * virtual <返回值类型> <函数名> (<参数表>) = 0;
 * 函数声明为纯虚函数后，就不用给出具体的定义。纯虚函数相当于一个统一的接口形式
 * 
 * 如果一个类中至少包含一个纯虚函数，这个类就被称为抽象类
 * 抽象类不能作为形参类型，返回类型，转换类型；但是可以作为相应类型的指针进行指向派生类对象进行使用
 * 
 * 虚基类 virtual base class 的方式使得在继承间接共同基类时在多个间接同名成员中只保留一份成员
 * 虚基类是在声明派生类时由继承方式决定的，并不是在声明基类时决定的，即 class 派生类 : virtual 继承方式 基类名
 *     经过这样的声明后，当基类通过多条派生路径被一个派生类继承后，该派生类只继承该基类一次
 *     需要注意：为了保证虚基类在派生类中只继承一次，应当在基类的所有直接派生类中声明为虚基
 *     类。否则仍然会出现对基类的多次继承
*/
int main() {

    return 0;
}
