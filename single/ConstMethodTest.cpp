#include<iostream>

using namespace std;

/*
* 测试常量函数
*/
class Sample {
    public:
        Sample() {}
        void getValue();
        void getValue() const;
        void priValue();
        void priValue() const;

        void unConstMethod();
        void constMethod() const;
};

void Sample::getValue() { cout << "非常量函数 getValue" << endl; }
void Sample::getValue() const { cout << "常量函数 getValue" << endl; }

void Sample::priValue() { cout << "非常量函数 priValue" << endl; }
void Sample::priValue() const { cout << "常量函数 priValue" << endl; }

void Sample::unConstMethod()  { cout << "非 const 函数" << endl; }
void Sample::constMethod() const { cout << "const 函数" << endl; }

int main() 
{
    const Sample cono;
    Sample o;

    // 常量对象调用同名方法
    cono.getValue();
    cono.priValue();

    cout << "-----------------------------" << endl;

    // 非常量对象调用同名方法
    o.getValue();
    o.priValue();

    cout << "-----------------------------" << endl;
    o.constMethod(); // 非常量对象可以调用常量方法
    o.unConstMethod();

    // cono.unConstMethod(); // 常量对象不能调用非常量方法，会引起编译错误

    return 0;
}