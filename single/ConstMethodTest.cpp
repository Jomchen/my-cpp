#include<iostream>

using namespace std;

/*
* 测试常量函数
*/
class Sample {
    public:
        Sample() {}
        void getValue() const;
        void getValue();
        void priValue();
        void priVcon() const;
        void constMethod() const;
};

void Sample::getValue() { cout << "非常量函数 getValue" << endl; }
void Sample::getValue() const { cout << "常量函数 getValue" << endl; }
void Sample::priValue() { cout << "非常量函数 priValue" << endl; }
void Sample::priVcon() const { cout << "常量函数 priValue" << endl; }
void Sample::constMethod() const { cout << "这是一个 const 函数" << endl; }

int main() 
{
    const Sample cono;
    Sample o;

    cono.getValue();
    //cono.priValue(); 常量对象不能访问非常量方法
    cono.priVcon();

    cout << "-----------------------------" << endl;

    o.getValue();
    o.priValue();
    o.priVcon();

    return 0;
}