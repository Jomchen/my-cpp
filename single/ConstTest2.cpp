#include<iostream>

using namespace std;

/*
* 测试常量成员
*/
class ConstObj {
    public:
        const int constData = 3;
        const int constData2;
        //static int staticData = 4; 类的静态成员不能在类中初始化
        static int staticData2;
        ConstObj() : constData2(3000) {} // 如果要对常量初始化除了一开始声明初始值，否则只有按如此形式才可以初始化
};

// 类的静态成员不能在类中声明时初始化，可以在外部初始化
int ConstObj::staticData2 = 100;

int main() {
    ConstObj c;
    cout << c.constData2 << endl;
    return 0;
}