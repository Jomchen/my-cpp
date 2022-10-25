#include<iostream>
using namespace std;


class Sort {
    public:
        virtual int getIndex() = 0;
};
class MyData : public Sort {
    private:
        string name;
        int age;
    public:
        MyData(string na, int ag) { name = na; age = ag; }
        string getName() { return name; }
        int getAge() { return age; }
        int getIndex() { return age; }
};
template <typename Sort> inline Sort* getMax(Sort * const s1, Sort * const s2) {
    int result = s1 -> getIndex() - s2 -> getIndex();
    return result >= 0 ? s1 : s2;
}



int main() {
    MyData my = MyData("李寻欢", 40);
    MyData my2 = MyData("独孤求败", 90);
    Sort *s = getMax(&my, &my2);
    cout << s -> getIndex() << endl;

    return 0;
}