#include<iostream>
#include <string>

using namespace std;

class Fruit {
    public:
        int price;
        Fruit(int priceData) { price = priceData; }
        Fruit(Fruit &f) { price = f.price; } // 拷贝构造函数是系统默认的，如果要重写则以 类名(类名 &引用名) {} 的方式重写
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
    User u = User("Kangkang", 22, "独孤九剑", 99);
    string username;
    int age;
    cin >> username >> age;
    cout << "username: " << username << " age: " << age <<endl;
    return 0;
}