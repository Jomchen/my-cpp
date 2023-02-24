#include<iostream>

using namespace std;

/*
* 测试常量成员
*/
class ConstObj {
    public:
        //static int staticData = 4; 类的纯静态成员不能在类中初始化
        static int staticData2; // 纯静态成员只能在类外部初始化

        static const int staticConstData = 999; // 常量型静态成员可以在类的内部初始化
        const int constData = 3; // 纯常量可以在类内部初始化
        const int constData2;
        ConstObj() : constData2(3000) {} // 纯常量初始化除了一开始声明初始值，也可以按如此形式初始化
        ConstObj(int data) : constData2(data) { cout << "有参构造方法" << endl; }
};

// 类的静态成员不能在类中声明时初始化，可以在外部初始化
int ConstObj::staticData2 = 100;

int main() {
    ConstObj c;
    ConstObj c2(30);
    cout << c.constData2 << endl;
    cout << c.staticConstData << endl;
    return 0;
}