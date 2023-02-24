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
        void constMethod() const;
};

void Sample::getValue() { cout << "非常量函数 getValue" << endl; }
void Sample::getValue() const { cout << "常量函数 getValue" << endl; }
void Sample::priValue() { cout << "非常量函数 priValue" << endl; }
void Sample::priValue() const { cout << "常量函数 priValue" << endl; }
void Sample::constMethod() const { cout << "这是一个 const 函数" << endl; }

int main() 
{
    const Sample cono;
    Sample o;

    cono.getValue();
    //cono.priValue(); 常量对象不能访问非常量方法，编译会报错
    cono.priValue();

    cout << "-----------------------------" << endl;

    o.getValue();
    o.priValue();
    o.constMethod(); // 非常量对象可以调用常量方法

    return 0;
}