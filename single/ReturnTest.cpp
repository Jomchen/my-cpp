#include<iostream>

using namespace std;

/**
 * 测试赋值行为，这里的 getAge() 那里有问题没有解决 
*/
class ObjTest {
    private:
        int age = 30;
    public:
        ObjTest() {}
        ObjTest(int a) { age = a; }
        int getAge() { return age; }
        friend ObjTest *getByHand(ObjTest &ot);
        friend ObjTest &getByReference(ObjTest &ot);
        friend ObjTest getByObj(ObjTest &ot);
};
ObjTest *getByHand(ObjTest &ot) {
    ObjTest newObj;
    newObj = ot;
    ot.age++;
    return (&newObj);
}
ObjTest &getByReference(ObjTest &ot) {
    ObjTest newObj;
    newObj = ot;
    ot.age++;
    return newObj;
}
ObjTest getByObj(ObjTest &ot) {
    ObjTest newObj;
    newObj = ot;
    ot.age++;
    return newObj;
}

int main() {
    // TODO 不明白这里赋值给指针后，指针仍然没有指向对象
    ObjTest ot(100);
    ObjTest *newOt;
    newOt = getByHand(ot);
    cout << ot.getAge() << endl;
    cout << newOt->getAge() << endl;

    cout << "----------------------------------------" << endl;

    //ObjTest ot2(100);
    //ObjTest newOt2;
    //newOt2 = getByReference(ot2);
    //cout << ot2.getAge() << endl;
    //cout << newOt2.getAge() << endl;

    cout << "----------------------------------------" << endl;

    //ObjTest ot3(100);
    //ObjTest newOt3;
    //newOt3 = getByObj(ot3);
    //cout << ot3.getAge() << endl;
    //cout << newOt3.getAge() << endl;

    return 0;
}