#include <iostream>
using namespace std;

/*
* 类的创建的三种方式
* 析构函数的测试（如果 A 对象包含有 B 对象，则析构函数的顺序是先是A的再是B的）
*/
class Test {
    private:
        string name;
        int age;
        static int kkkk;
    public:
        Test() { }
        //Test(string n, int a) { name = n; age = a; }
        Test(string n, int a) :name(n), age(a) {
            // do nothing
        }
        // 析构函数（在对象销毁前调用一次）
        ~Test() { cout << name << " obj is destroied age<" << age << ">" << endl; }
        void print()
        {
            cout << "name: " << name << " age: " << age << endl;
        }
        string getName() { return name; }
        void setName(string n) { name = n; }
        int getAge() { return age; }
        void setAge(int theAge) { age = theAge; }
        void staticPrint() {
            static int kk = 0;
            cout << "-------------->" << kk << endl;
            kk++;
        }

};


int main()
{
    Test t1("李寻欢1", 41);
    Test t2 = Test("李寻欢2", 42);
    Test *t3 = new Test("李寻欢3", 43);
    //cout << t3 -> getAge() << endl;

    t1.staticPrint();
    t2.staticPrint();
    t3->staticPrint();
    delete t3;
    
    
    return 0;
}