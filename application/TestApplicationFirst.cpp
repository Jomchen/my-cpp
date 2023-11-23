#include<iostream>
using namespace std;

/**
 * 虚函数
*/
class MyVirtual {
    public:
        MyVirtual() {}
        virtual void show() {
            cout << "MyVirtual函数" << endl;
        }
        void normal() {
            cout << "MyVirtual-normal" << endl;
        }

};
class MyActual : public MyVirtual {
    public:
        MyActual() {}
        void show() {
            cout << "MyActual函数" << endl;
        }
        void normal() {
            cout << "MyActual-normal" << endl;
        }
};

/**
 * 单继承链
*/
class Base {
    private:
        string baseName;
        int baseAge;
    public:
        Base() : baseName("默认baseName") { cout << "Base无参构造" << endl;}
        Base(string bn, int ba) {
            this->baseName = bn;
            this->baseAge = ba;
        }
        ~Base() { cout << "Base 析构函数" << endl; }
};
class Father : public Base {
    private:
        string fatherName;
        int fatherAge;
    public:
        Father() : Base() { cout << "Father无参构造" << endl;}
        Father(string fu, int fa) : Base("基础name", 20) {
            this->fatherName = fu;
            this->fatherAge = fa;
        }
        ~Father() { cout << "Father 析构函数" << endl; }

};
class Son : public Father {
    private:
        string sonName;
        int sonAge;
    public:
        Son(string su, int sa) : Father() { cout << "Son无参构造" << endl; }
        ~Son() { cout << "Son 析构函数" << endl; }
        void print() {
            cout << "sonUsername: " << "-" << "sonAge: " << endl;;
        }
};


/** 
 * 多继承，虚基类，以及多继承和属性的构造函数，析构函数的顺序
*/
class NestedFirst {
    public:
        NestedFirst() { cout << "NestedFirst无参构造" << endl;}
        ~NestedFirst() { cout << "NestedFirst析构函数" << endl; }
};
class NestedSecond {
    public:
        NestedSecond() { cout << "NestedSecond无参构造" << endl;}
        ~NestedSecond() { cout << "NestedSecond析构函数" << endl; }
};
class Toplying {
    public:
        string data;
        Toplying() : data("Toplying-data") {
            cout << "Toplying无参构造" << endl;
        }
        ~Toplying() { cout << "Toplying析构函数" << endl; }

};
class FirstUpperlying : virtual public Toplying {
    public:
        string data;
        FirstUpperlying() : data("FirstUpperlying-data") { cout << "FirstUpperlying无参构造" << endl; }
        ~FirstUpperlying() { cout << "FirstUpperlying析构函数" << endl;}

};
class SecondUpperlying : virtual public Toplying {
    public:
        string data;
        SecondUpperlying() : data("SecondUpperlying-data") { cout << "SecondUpperlying无参构造" << endl; }
        ~SecondUpperlying() { cout << "SecondUpperlying析构函数" << endl; }

};
class Underlying : public FirstUpperlying, public SecondUpperlying {
    public:
        string data;
        NestedFirst nf;
        NestedSecond ns;
        Underlying() : data("Underlying-data") { cout << "Underlying无参构造" << endl; }
        ~Underlying() { cout << "Underlying析构函数" << endl;}
};

/**
 * 构造函数的几种写法
 * 析构函数的写法
 * 
 * 重载 int()
*/
class Simple {
    private:
        string username;
        int age;
        string address;
    public:
        Simple() {
            username = "UNKOWN";
            age = -1;
            address = "UNKOWN_ADDRESS";
        }
        // 这也是一种无参构造函数的方式
        // Simple() : username("mao_jomkie"), age(10), address("mao address") {
        // }
        Simple(string un, int ae) {
            username = un;
            age = ae;
            address = "two parameters address";
        }
        Simple(string un, int ae, string ad) {
            username = un;
            age = ae;
            address = ad;
        }
        ~Simple() {
            cout << "Simple 析构函数：" << endl;
            cout << "username: " << username << endl;
            cout << "age: " << age << endl;
            cout << "address: " << address << endl;
        }
        friend ostream & operator <<(ostream & o, Simple & s) {
            return o << s.username << "-" << s.age << "-" << s.address << endl;
        }
        friend Simple operator +(Simple& a, Simple& b) {
            return Simple(
                a.username + b.username,
                a.age + b.age,
                a.address + b.address
            );
        }
        Simple* getPoint() {
            return this;
        }

        // 这种方案，执行后没有相关的析构函数情况？？？？
        // friend Simple& operator +(Simple& a, Simple& b) {
        //     Simple s = Simple(
        //         a.username + b.username,
        //         a.age + b.age,
        //         a.address + b.address
        //     );
        //     return s;
        // }

        // 这种写法错误，会提示：转换函数只能是非静态函数
        // friend int operator int();
        operator int();
};
Simple::operator int() {
    return age;
}

/**
 * 静态量
 * 常量
*/
class StaticAndConst {
    public:
        // 静态量不能在类的内部进行初始化
        // static int STATIC_DATA = 100;
        static int STATIC_DATA;

        // 常量可以直接定义值，也可以在构造函数进行初始化
        const string CONST_DATA_FIRST;
        const string CONST_DATA_SECOND = "999";

        // 静态常量可以直接定义赋值
        static const int STATIC_CONST_DATA = 1000 ;
        // 字符串类型的静态常量不能直接定义赋值（不知道为什么）
        // static const string STATIC_CONST_DATA2 = "STATIC_CONST_DATA2" ;
        StaticAndConst(string constDataFirst) : CONST_DATA_FIRST(constDataFirst) {
            cout << "静态量和常量类构造函数" << endl;
        }

};
int StaticAndConst::STATIC_DATA = 100;

/**
 * Copy函数
*/
class CopyClass {
    private:
        string name;
        int age;
    public:
        CopyClass() {
            name = "UNKOWN";
            age = -1;
            cout << "执行了copy的无参" << endl;
        }
        CopyClass(string n, int a) : name(n), age(a) {
            cout << "执行了copy有参，name: " << name << " age: " << age << endl;
        }
        CopyClass(CopyClass& cc) {
            cout << "执行了copy函数，name: " << cc.name << " age: " << cc.age << endl;
        }

};

/**
 * 友元函数，友元类
*/
class NormalClass;
class FriendClass;
class FriendSecond;
class FriendClass {
    private:
        string friendName;
    public:
        FriendClass() : friendName("FriendName") { cout << "FriendClass构造函数" << endl; }
        void printNormal(NormalClass& n);
};
class FriendSecond {
    friend NormalClass;  // 声明为友元类，即NormalClass是本类的朋友，可以访问本类的属性
    private:
        string secondName;
    public:
        FriendSecond() :  secondName("SecondName") { cout << "FriendSecond构造函数" << endl; }
};
class NormalClass {
    private:
        string normalName;
        FriendSecond fs;
    public:
        NormalClass() : normalName("NormalName"), fs() { cout << "NormalClass构造函数" << endl; }
        void printFriendSecond() {
            cout << "FriendSecond的secondName为：" << fs.secondName << endl;
        }

        // 声明为友元函数，则此函数可以访问本类属性
        friend void FriendClass::printNormal(NormalClass& n);
};
void FriendClass::printNormal(NormalClass& n) {
    cout << "NormalClass的normalName为：" << n.normalName << endl;
}


/**
 * 常量方法
*/
class ConstAboutClass {
    public:
        ConstAboutClass() {}
        void getValue();
        void getValue() const;

        void priValue();
        void priValue() const;

        void unConstMethod();
        void constMethod() const;
};

void ConstAboutClass::getValue() { cout << "非常量函数 getValue" << endl; }
void ConstAboutClass::getValue() const { cout << "常量函数 getValue" << endl; }

void ConstAboutClass::priValue() { cout << "非常量函数 priValue" << endl; }
void ConstAboutClass::priValue() const { cout << "常量函数 priValue" << endl; }

void ConstAboutClass::unConstMethod()  { cout << "非 const 函数" << endl; }
void ConstAboutClass::constMethod() const { cout << "const 函数" << endl; }

/** 测试声明对象 */
void testDeclare() {
    // 这两种方式一直有争议，没有调用无参构造方法
    Simple sss();
    Simple& sssYin();

    Simple s0 = Simple();
    Simple* s1 = new Simple();
    Simple s2("ssss", 44, "ssss_address");
}

/** 测试重载 */
void testExtends() {
    Simple s1 = Simple("s1", 1, "s1_address");
    Simple s2 = Simple("s2", 2, "s2_address");
    Simple s3 = (s1+s2);
    int int3 = s3;

    // 测试 << 重载
    cout << "测试 << 重载：" << s1 << endl;

    // 测试 int() 重载
    cout << "测试 int() 重载：" << int(s1) << endl;

    // 测试 + 重载
    cout << "测试 + 重载 (s1+s2)：" << (s1+s2) << endl; // 输出数字
    cout << "测试 + 重载 s3：" << s3 << endl; // 输出整体信息

    cout << "---------------------------------------" << endl;
}


/** 测试虚函数 */
void testVirtual() {
    MyVirtual mv;
    MyActual ma;
    MyVirtual* mp;

    cout << "------------------------------1" << endl;
    mv.show(); // MyVirtual函数
    cout << "------------------------------2" << endl;
    ma.show(); // MyActual函数
    cout << "------------------------------3" << endl;
    mv = ma;
    mv.show(); // MyVirtual函数，因为 mv = ma 是将 ma数据复制给mv，实际上还是mv对象
    cout << "------------------------------4" << endl;
    mp = &ma;
    mp -> show(); // MyActual函数，因为 show 是虚函数
    mp -> normal(); // MyVirtual-normal，因为 normal 不是虚函数
    (*mp).show(); // MyActual函数，因为 show 是虚函数
    (*mp).normal(); // MyVirtual-normal，因为 normal 不是虚函数
}

/** 测试单继承链 */
void testSimpleExtends() {
    Son s("儿子", 10);

}

/** 测试多继承，虚基类，以及多继承和属性的构造函数，析构函数的顺序 */
void testMultiExtends() {
    Underlying kk = Underlying();
}

/** 测试常量指针和指针常量*/
void testPoint() {
    int data = 3;
    int data2 = 100;

    const int *p1 = &data; // 指针指向的值为常量
    // *p1 = 2; // 不允许

    int * const p2 = &data; // 指针为常量
    // p2 = &data2; // 不允许
}

/** 测试copy函数 */
void testCopy() {
    // 这两种使用方式一直有争议，并没有调用无参构造
    CopyClass& ccc();
    CopyClass ccYin();

    CopyClass c0 = CopyClass();
    CopyClass c1 = CopyClass("Jane", 3);
    CopyClass* c2 = new CopyClass("Maria", 4);
    CopyClass c3("lemonwind", 6);
    CopyClass cf = c3;
}

/** 测试友元函数，友元类 */
void testFriend() {
    FriendClass fc = FriendClass();
    NormalClass nc = NormalClass();

    // 友元函数
    fc.printNormal(nc);

    // 友元类
    nc.printFriendSecond();
}

/** 测试常量方法 */
void testConstMethod() {
    const ConstAboutClass cono;
    ConstAboutClass o;

    // 常量对象调用同名方法
    cono.getValue(); // 常量函数 getValue
    cono.priValue(); // 常量函数 priValue

    cout << "-----------------------------" << endl;

    // 非常量对象调用同名方法
    o.getValue(); // 非常量函数 getValue
    o.priValue(); // 非常量函数 priValue

    cout << "-----------------------------" << endl;
    o.constMethod(); // 非常量对象可以调用常量方法
    o.unConstMethod(); // 非常量对象可以调用非常量方法

    // cono.unConstMethod(); // 常量对象不能调用非常量方法，会引起编译错误
}

int main() {
    // testDeclare();
    // testExtends();
    // testVirtual();
    // testSimpleExtends();
    // testMultiExtends();
    // testPoint();
    // testCopy();
    // testFriend();
    testConstMethod();
}

