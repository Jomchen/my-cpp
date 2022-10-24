#include<iostream>

using namespace std;


class MyVirtual {
    public:
        MyVirtual() {}
        virtual void show() {
            cout << "MyVirtual" << endl;
        }
};
class MyActual : public MyVirtual {
    public:
        virtual void show() {
            cout << "MyActual" << endl; 
        }
};

 void printMv(MyVirtual &pp) {
     pp.show();
 }

/**
 * 虚函数一般不申明为内联函数
 * 静态成员函数和友元不能申明为虚函数
 * 声明时加 visual，虚函数在类体外不加 visual 关键字
 * 构造函数不能定义为虚函数
 * 不要在构造函数和析构函数中定义虚函数
*/
int main() {
    MyVirtual mv;
    MyActual ma;
    MyVirtual *mp;

    ma = MyActual();
    ma.show(); // MyActual

    cout << "------------------------------" << endl;

    mv = ma; // 这是把 ma 的成员数据拷贝给 mv，所以当下面一行执行 mv.show() 时显示的是 MyVirtual
    mv.show(); // MyVirtual  TODO 注意！！！

    cout << "------------------------------" << endl;

    mp = &ma;
    mp->show(); // MyActual
    (*mp).show(); // MyActual

    cout << "------------------------------" << endl;

    MyVirtual mv00;
    MyActual ma00;
    printMv(mv00); // MyVirtual
    printMv(ma00); // MyActual

    return 0;
}