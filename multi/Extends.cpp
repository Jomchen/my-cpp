#include<iostream>

using namespace std;

class DataTest {
    public:
        int data;
        DataTest() { cout << "DataTest 无参构造函数" << endl;  }
        ~DataTest() { cout << "DataTest 析构造函数" << endl;  }
        DataTest(int a) { data = a; }
        void dataTestPrint() { cout << "the dataTest is: " << data << endl; }
};

class GrandFather {
    public:
        GrandFather() { cout << "grandFather 默认构造函数" << endl; }
        ~GrandFather() { cout << "grandFather 析构函数" << endl; }
        void print() { cout << "GrandFather print()" << endl; }
};

class Father {
    public:
        Father() { cout << "father 默认构造函数" << endl; }
        ~Father() { cout << "father 析构函数" << endl; }
        void print() { cout << "Father print()" << endl; }
};

class Son : public Father , public GrandFather{
    public:
        Son() : Father(), GrandFather() { cout<< "son 默认构造函数" << endl; }
        ~Son() { cout << "son 默认析构函数" << endl; }
        void print() { Father::print(); GrandFather::print(); cout << "Son print()" << endl; }
};

class MuchFree {
    public:
        MuchFree() {cout << "MuchFree 无参构造函数" << endl; }
        ~MuchFree() { cout << "MuchFree 析构函数" << endl; }
        void myPrint() { cout << "MuchFree" << endl; }   
};
class Free {
    public:
        int data;
        Free() { cout << "Free无参构造函数" << endl; }
        Free(int d) { data = d; }
        ~Free() { cout << "Free 析构函数" << endl; }
        void myPrint() { cout << "Free" << endl; }
};
class UnFree : public Free , public MuchFree {
    private:
        int data2;
        DataTest dataTest;
        GrandFather grandFather;
    public:
        UnFree() { cout << "UnFree 无参构造函数" << endl; } 
        UnFree(int data) : Free(data * 10) { data2 = data; }
        ~UnFree() { cout << "UnFree 析构函数" << endl; }
        GrandFather *getGrandFather() { 
            return &grandFather; 
        }
        void myPrint() { cout << "free's data is: " << Free::data << endl; }

};


/**
 * 派生类不能基类的友元函数，但基类的成员函数是其他类的友元函数时，是可以被继承的
 * 派生类中的成员可以访问基类中的公有 和 保护成员
*/
int main() {
    UnFree unfree;

    // Son s;
    // s = Son();
    // s.print();
    // Son ss();
    // // TODO 这里为什么编译不通过 ss.print();

    // UnFree uf(100);
    // uf.myPrint();
    // UnFree uf2 = UnFree(200);
    // uf2.myPrint();

    return 0;
}