#include<iostream>
#include<cstring>
#include<string>
using namespace std;

/**
 * cin 的成员函数
 * get()             获取一个字符，函数的返回值就是读入的字符；函数如果遇到输入流中的文件结束符，则函数返回值为EOF(-1)
 * getline(char *buf, int n, char deline = '\n')       读取一行字符串（包括空格符）
 *                                                                           buf是存放字符串的，n用来设置字符个数上限，最后一个参数用来给出终止符，默认值为'\n'
 *                                                                           当录入的字符数 满足了 n个 或 遇到deline 其中一个条件时即结束
 * read(char *buf, int n)       读取若干个字符，并存放到指定的地方，从输入流中读取n个字符到 buf 中
 * 
*/
int main() {

    char array[10];
    char *p = array;
    for (int i = 65; i < 75; i++) {
        *p = i;
        p++;
    }
    p -= 10;
    cin.getline(p, 3, ' ');
    for (int i = 0; i < 10; i++) {
        cout << "-->" << *p << "<--" << endl;
        p++;
    }
    p -= 10;
    return 0;
}