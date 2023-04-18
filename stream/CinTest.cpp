#include<iostream>
#include<cstring>
#include<string>
#include<climits>
using namespace std;

/**
 * cin 的成员函数
 * get()             获取一个字符，函数的返回值就是读入的字符；函数如果遇到输入流中的文件结束符，则函数返回值为EOF(-1)
 * getline(char *buf, int n, char deline = '\n')   读取一行字符串存放到指定的数组中（包括空格符）
 *                                                                           buf 是存放字符串的字符数组
 *                                                                           n 用来设置字符个数上限（注意实际读取了 n-1 个字符后，会再自动填充字符串结束符，如此刚好满足 n 的数量）
 *                                                                           deline 表示结束符，默认值为'\n'
 *                                                                           当录入的字符满足了 n个 或 遇到deline 其中一个条件时即结束
 * read(char *buf, int n)       读取若干个字符，并存放到指定的地方
 *                                                                           buf 存放字符的字符数组
 *                                                                           n 存取的字符个数
 * 
*/
int main() {

    char array[26];
    char *p = array;
    for (int i = 65; i < 91; i++) {
        *p = i;
        p++;
    }
    p -= 26;
    cin.getline(p, INT_MAX, ' \n');
    // cin.read(p, 3);
    for (int i = 0; i < 26; i++) {
        cout << "-->" << *p << "<--" << endl;
        p++;
    }
    p -= 10;
    return 0;
}