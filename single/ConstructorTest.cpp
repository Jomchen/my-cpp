#include<iostream>
#include <string>

using namespace std;

/**
 * 考查了 Fruit 的拷贝构造函数
 */
class Fruit {
    public:
        int price;
        Fruit(int priceData) { price = priceData; }
        Fruit(Fruit &f) { 
            price = f.price; 
            cout << "这是个拷贝函数" << endl;
        } // 拷贝构造函数是系统默认的，如果要重写则以 类名(类名 &引用名) {} 的方式重写
};

class Kongfu {
    public:
        string name;
        int level;
    public:
        ~Kongfu() { cout << "kongfu 的析构函数" << endl; }
        Kongfu(string n, int a) {name = n; level = a; }
};
class User {
    public:
        string name;
        int age;
        Kongfu kongfu;
    public:
        ~User() { cout << "user 的析构函数" << endl; }
        User(string n, int a, string kn, int kl) : name(n), age(a), kongfu(kn, kl) { }
};

/*
* 析构函数
*/
int main() {
    Fruit f = Fruit(2000); // 先构造一个对象
    Fruit &f2 = f; // 这不会触发拷贝构造函数
    Fruit f3 = f; // 这会触发拷贝构造函数
    return 0;
}