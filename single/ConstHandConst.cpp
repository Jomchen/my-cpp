#include<iostream>

using namespace std;



/*
* 指针测试
const 位于 * 左侧，表示指针所指数据是常量，数据不能通过指针修改，但是指针本身是变量
const 位于 * 右侧，表示指针本身是常量，指针不能指向其它地址，指针指向的值可以修改
*/
int main() {

    int data = 3;
    int data2 = 100;

    const int *p2 = &data; // 指针指向的值为常量
    int * const p1 = &data; // 指针为常量

    return 0;
}