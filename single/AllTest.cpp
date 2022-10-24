#include<iostream>

using namespace std;

class Father {
    public:
        void show() { cout << "Father show" << endl; }
        ~Father() { cout << "Father ~Father" << endl; }
};
class Son : public Father {
    public:
        void show() { cout << "Son show" << endl; }
        Son () { }
        Son (const Son &s) { cout << "Son 拷贝" << endl; }
};
int main() {
    Son son = Son();
    Father *fa = &son;
    son.show(); // Son show
    son.Father::show(); // Father show
    Father &ffaa = son;
    ffaa.show();
    (*fa).show(); // Father show ，如果想 输出为 Son show ，则Father的 show 应该声明为 virtual 方法

    cout << "**************************" << endl;
    return 0;
}