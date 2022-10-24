#include<iostream>

using namespace std;


class VirtualBase {
    public:
        int data;
        VirtualBase() {}
        VirtualBase(int d) { data = d; }
        ~VirtualBase() { cout << "VirtualBase 析构函数" << endl; }
};
class MyVirtual : public VirtualBase {
    public:
        int mydata;
        MyVirtual() {}
        MyVirtual(int da) : VirtualBase(da * 100) { mydata = da; }
        ~MyVirtual(){ cout << "MyVirtual 析构函数" << endl; }
};

/**
 * 如果一个类的析构函数是虚函数，则由它派生的所有子类的析构函数也是虚析构函数，使用这个的目的是为了防止内存泄露
 * 如果一个类如果定义了虚函数，则最好将析构函数也定义为虚析构函数，不过切记构造函数不是析函数
*/
int main() {

    MyVirtual *mvp = new MyVirtual(); // 如果 VirtualBase 的析构函数没有定义为 virtual 则以下的回收工作不会执行 VirtualBase 的析构函数（旧版本中），新版本已经会进行回收执行操作
    delete mvp;
    return 0;
    return 0;
}