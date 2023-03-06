#include<iostream>
using namespace std;


// 纯虚方法，引申出抽象类
class Sort {
    public:
        virtual int getIndex() = 0;
};
// 抽象类实现
class MyData : public Sort {
    private:
        string name;
        int age;
    public:
        MyData(string na, int ag) { name = na; age = ag; }
        string getName() { return name; }
        int getAge() { return age; }
        int getIndex() { return age; }
        friend ostream & operator<<(ostream &os, const MyData &myd);
};

// 重写输出符号
ostream & operator<< (ostream & os, const MyData & myd) {
    // myd.getName(); myd.getName() 和 myd.getAge() 不能调用 是因为友元函数是只能访问其成员属性而非成员函数
    cout <<  myd.name << "--" << myd. age ;
    return os;
}

// 泛型方法（模板方法）获取最大对象（getIndex 较大的对象）
template <typename Sort> inline Sort* getMax(Sort * const s1, Sort * const s2) {
    int result = s1 -> getIndex() - s2 -> getIndex();
    return result >= 0 ? s1 : s2;
}

// TODO 这种写法不明白
template <class T> T myfun(T t1, T t2) {
    if (sizeof(T) == 8) {
        return t1 * t2;
    } else {
        return t1 + t2;
    }
}

// 泛型类（模板类）
template <class T> class Wrapper {
    private:
        string name;
        T data;
    public:
        Wrapper(string na, T da) : name(na), data(da) { cout << "Wrapper 有参构造器" << endl; }
        Wrapper() : name("unknown") { cout << "Wrapper 无参构造器" << endl; }
        T getData() { return data; }
        string getName() { return name; }
        void print() { cout << "name=(" << name << "), data=(" << data << ")" << endl; } // 这里的 data 具体的类型 T 如果没有对应的 << 重写则会引起报错
};


int main() {
    // 抽象类只能通过指针方式使用，不能通过引用方式使用
    MyData my = MyData("李寻欢", 40);
    MyData my2 = MyData("独孤求败", 90);
    Sort *s = getMax(&my, &my2);
    cout << s -> getIndex() << endl;

    //string strData = "Java";
    //Wrapper<string> wrapper01 = Wrapper("operating system", "Linux"); // TODO 为什么这个编译不通过，编译错误显示 Wrapper<const char*>
    //Wrapper<string> wrapper00 = Wrapper("operating system", strData); // TODO 为什么这里可以编译通过
    //Wrapper<string> wrapper02("operating system", "Linux");
    //wrapper00.print();

     cout << myfun(30.0, 10.0) << "--" << myfun(8, 2) << endl;;

    MyData md = MyData("杨过", 45);
    Wrapper<MyData> wrapper = Wrapper("personal name", md);
    wrapper.print();

    cout.operator<<(2.22).operator<<('A');
    return 0;
}