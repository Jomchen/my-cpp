#include<iostream>

using namespace std;

/**
 * 改变默认的输入来源，或改变默认的输出目的地
 * 重定向函数 freopen 的原型如下：
 * FILE *freopen (const char *path, const char *mode, FILE *stream);
 * 函数 freopen() 的功能是将 stream 按 mode 指定的模式重定向到 path 指向的文件
 *     如果重定向时发生错误，则关闭原来的 stream，函数返回 NULL
 *     mode 可以是 w 或 r 方式
 * 
 * int eof() const; 函数返回 eofbit 的值
 * 使用 eof() 函数测试是否到达文件尾，当文件操作结束遇到结束符时，函数返回1，否则返回0
 * 
 * 返回流是否处于正常状态
 * int fail() const;
 * 返回 failbit 状态，以判断流操作是否失败，failbit 表示发生流格式错误，但缓冲区中的字符没有丢失
 * 这种错误通常是可以修复的
 * 
 * 判断是否正常
 * int good() const;
 * int operator void *();
 * 如果 eofbit, failbit 和 badbit 全部都没有被置位（即位均为0），则返回1(true)，否则返回0(false)
 * 
 * 返回流是否属于失败
 * int bad() const;
 * int operator void ! ();
 * 如果 eofbit, failbit 和 badbit 中有一位被置位（即均为1），则返回1(true),，否则返回0(false)
 * 
 * 返回状态字
 * int rdstate() const;
 * 该函数返回流的当前状态
 * 
 * 恢复状态字
 * void clear(int nState = 0);
 * 该函数恢复或设置状态字。默认值为0，即将流状态恢复为正常
 * 
 * 
*/
int main() {

    return 0;
}