#include<iostream>
#include<cmath>
using namespace std;

class Pixel;
class Test {
        public:
            void printX(Pixel p);
};
class Pixel {
    private:
        int x, y;
        public:
            Pixel(int x0, int y0) {
                x = x0; y = y0;
            }
            void printxy() {
                cout << "pixel: (" << x << ", " << y <<") " << endl;
            }
            friend double getDist(Pixel p1, Pixel p2); // 友元函数，全局函数
            friend void Test::printX(Pixel p); // 类Test 的成员函数为本类的友元函数
};

void Test::printX(Pixel p) {
    cout << "x=" << p.x << "\ty=" << p.y <<endl;
    return;
}

// 注意这里的声明没有写类的命名
double getDist(Pixel p1, Pixel p2) {
    double xd = double(p1.x - p2.x);
    double yd = double(p1.y - p2.y);
    return sqrt(xd*xd + yd*yd);
}

/*
* 友元函数，友元函数不属于成员函数
* 注意！！注意！！友元是可以访问其成员属性，而非成员函数
*/
int main() {
    Pixel p1(0,0), p2(10,10);
    p1.printxy();
    p2.printxy();
    cout << "(p1,p2)间距离 = " << getDist(p1, p2) << endl;
    Test t;
    cout << "从友元函数中输出 --" << endl;
    t.printX(p1); // 通过对象调用类的成员函数
    t.printX(p2);

    return 0;
}