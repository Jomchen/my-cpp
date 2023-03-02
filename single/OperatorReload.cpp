#include<iostream>

using namespace std;

// 以下的运算符不能重载
// . 成员访问运算符
// .*, ->* 成员指针访问运算符
// :: 域运算符
// sizeof 长度运算符
// ?: 条件运算符
// # 预处理符

// 运算符重载的实质是编写以运算符为名称的函数，使用运算符
// 的表达式就被解释为对重载函数的调用，运算符重载函数的格式

// 运算符可以被重载为全局函数（通常是类的友元），参数个数
// 为运算符的操作数个数

// 也可以重载为类的成员函数（一般倾向于重载为类的成员函数），
// 参数个数为运算符操作数个数减  1

// 重载 () , [] , -> 或者赋值运算符 = 时，只能将它们重载为成员函数，
// 不能重载为全局函数

// 1. 运算符重载
// 格式为：返回值类型 operator 运算符(形参表) {函数体}
// 其中可以视为 "operator 运算符" 被看成是一个函数名

// 2. 默认赋值运算符重载格式（没有自定义的符值运算符函数时）：
// 赋值运算符必须重载为成员函数，通常返回一个引用
// X&X :: operator=(const X &source) { 成员间赋值 }

// 3. 重载流
// 3_1 流插入运算符重载
// 重载使之自定义的类对象
// 重载流插入运算符，只能重载为类的友元函
// ostream &operator<<(ostream &output, 类名&对象名) { ... reutrn output; }
// 3_2 流读取运算符重载
// 重载提取运算符
// 可以重载为类的友元或成员函数
// istream &operator >>(istream &input, 类名&对象名) { ... return input }

// 4. 类型转换运算符的重载
// 只能重载为成员函数，重载后：(类型名)对象 等价于 ==============> 对象.operator 类型名()
// 重载强制类型转换运算符时，不需要指定返回值类型，因为返回类型是确定的
// 经过适当重载后，(类型名)对象 就等价于 对象operator 类型名()

// 5. 重载 ++ 和 -- 时，如果有参数则表示后缀重载，否则表示前缀

// 重载强制类型转换运算符
// 类型的名字（包括类型的名字）本身也是一种运算符，即强制类型转换运算符，是单目运算符，只能重载为成员函数
// 经过重载后，(类型名)对象 等价于 对象.operator 类型名()
// 重载强制类型转换运算符时，不需要指定返回值类型，因为返回值类型是确定的
// 经过行当重载后，(类型名)对象 这个对对象进行强制类型转换的表达式等价于 对象.operator 类型名()，即变成运行符函数的调用

class Mypp {
    private:
        int data;
    public:
        Mypp() { }
        Mypp(int d) { data = d; }
        Mypp operator++(); // 表示前缀++的重载
        Mypp operator ++(int); // 表示后缀++的重载
        void print() { cout << "data: " << data << endl; }
};
Mypp Mypp::operator++() {
    cout << "++Mypp" << endl;
    this->data++;
    return *this; 
}
Mypp Mypp::operator++(int c) {
    cout << "Mypp++" << endl;
    Mypp old = *this;
    data++;
    return old;
}

class MyType {
    private:
        int age;
    public:
        MyType() {}
        MyType(int data) { { age = data; }}
        operator int() { return age; }
};

class MyStream {
    private:
        string data;
    public:
        string getData() { return data; }
        friend ostream & operator<<(ostream &os, MyStream &c);
        friend istream & operator>>(istream &is, MyStream &c);
};

ostream &operator<<(ostream &os, MyStream &c1) {
    cout << "MyStream<<" << endl;
    return os;
}
istream &operator >>(istream &is, MyStream &c1) {
    cout << "MyStream>>" << endl;
    string sss;
    is >> sss;
    sss += sss + " Linux";
    c1.data = sss;
    return is;
}

class MyFriend {
    int a, b;
    public:
        MyFriend();
        MyFriend(int aa, int bb);
        void toString(string msg = "") { cout << msg << "a: " << a << " --- b: " << b << endl; }
        double operator()(double x, double y) const;
        MyFriend operator-(const MyFriend &c);
        friend MyFriend operator+(const MyFriend &c1, const MyFriend &c2);
        MyFriend & operator=(const MyFriend &c1);
};

double MyFriend::operator()(double x, double y) const {
    cout << "这里对MyFriend 的()进行了重载" << endl;
    return (x + y) * 2;
}
MyFriend MyFriend::operator-(const MyFriend &c) {
    cout << "这里对MyFriend 的-进行了重载" << endl;
    return MyFriend((*this).a - c.a ,  (*this).b - c.b);
}
MyFriend  operator+(const MyFriend &c1, const MyFriend &c2) {
    cout << "这里对MyFriend 的+进行了重载" << endl;
    return MyFriend(c1.a + c2.a, c2.b + c2.b);
 }
 MyFriend & MyFriend::operator=(const MyFriend &c1) {
    cout << "这里对MyFriend 的=进行了重载" << endl;
    this->a = (c1.a * c1.a);
    this->b = (c1.b * c1.b);
    return *this;
 }
MyFriend::MyFriend() {
    (*this).a = 888;
    (*this).b = 999;
}
MyFriend::MyFriend(int aa, int bb) {
    //this -> a = aa;
    //this -> b = bb;
    (*this).a = aa;
    (*this).b = bb;
}


class Complex {
    private:
        double real, virt;
    public:
        Complex(double r=0,double v=0) : real(r), virt(v) {}
        friend Complex operator +(Complex a, Complex b);
        friend ostream & operator << (ostream &out, Complex &a);
};
ostream & operator <<(ostream &out, Complex &a) {
    cout << "Complex<<" << endl;
    return out << a.real << " + " << a.virt << "i\n";
}
Complex operator+(Complex a, Complex b) {
    cout << "Complex+" << endl;
    return Complex(a.real + b.real, a.virt + b.virt);
}

int testProblem();

/*
* 运算符重载
*/
int main() {
    MyFriend mf1(10, 20);
    MyFriend mf2(30, 40);
    mf1.toString("mf1 ");
    mf2.toString("mf2 ");
    cout << mf1(1, 2) << endl;

    MyFriend mfMinute = mf1 - mf2;
    mfMinute.toString("mfMinute(mf1-mf2) ");
    // MyFriend mm = mf2; // 这里 mm.toString() 仍然输出 30 40（因为这里注意 Mfriend mm 会调用默认构造函数赋值给 mm，然后 mf2 的引用会赋值给 mm）

    MyFriend mm;
    mm.toString("mm(默认构造函数) ");
    mm = mf2; // 这里会输出 900 和 1600
    mf2.toString("mf2 ");
    mm.toString("mm ");


    MyType mytype(100);
    int newAge = (int)mytype;
    cout << newAge << endl;
    int newAge2 = 300 + mytype; // 这里mytype 会隐式调用 (int) mytype，因为强制转换已经重载为返回int了所以正常执行

    Mypp myppFirst(100);
    Mypp newMyppFirst;
    newMyppFirst = myppFirst++;
    myppFirst.print(); // 101
    newMyppFirst.print(); // 100

    Mypp myppSecond(100);
    Mypp newMyppSecond;
    newMyppSecond = ++myppSecond;
    myppSecond.print(); // 101
    newMyppSecond.print(); // 101

    testProblem(); // TODO 这个输出是为什么，为什么可以 数字加上对象

    return 0;
}

int testProblem() {
    //Kongfu kf("独孤九剑", 999, "独孤求败", 90);
    //cout << kf.getUser().getName() << endl;
    Complex a(2,5),b(7,8),c(0,0);
    c = a+b;
    cout << c;
    c = 4.1 + a;
    cout << c;
    c = b + 5.6;
    cout << c;

    return 0;
}
