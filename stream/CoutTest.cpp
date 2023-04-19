#include<iostream>
using namespace std;

/**
 * cout 的成员函数
 * long flags(long IFlags)           设置和返回标志位，使用参数IFlags设置（替换），返回值为设置前的标志字
 * long flags() const                   返回当前标志字
 * long setf(long IFlags)             设置标志位，使用参数IFlags置位指定的标志字，返回值为置位前的标志字“添加”long setf(long IFlags, long IMask) 返回值为更新前的标志字
 * long unsetf(long IFlags)         清除标志位，清除参数IFlags指定的标志位，返回清除前的标志字
 * int width(int nw)                    设置和返回输出宽度
 * int width() const                     返回值为当前的输出宽度值
 * char fill(char cFill)                   设置填充字符，当设置宽度大于数据输出需要的宽度时，空白位置以字符参数cFill填充   char fill() const 返回当前使用的填充符
 * int precision(int np)                设置数据显示精度，参数np设置数据显示精度，如果浮点数以定点形式输出，则np表示整数位数和小数位数总共的字数
 *                                                 如果设置为科学计数法输出，则np为尾数精度位数（包含小数点）
 *                                                 int precision() const 系统默认的数据显示精度为6位 float类型最大数据显示精度为64位
 *                                                 double 类型最大数据显示精度为15位
 * ostream 提供了一些输出流的成员函数
 * put(char)                                输出一个字符，可以是字符变量，字符常量或ASCII码
 * wirte(const char *str, int n)    str用于存放字符串名，n用于指定字符个数
*/
int main() {
    return 0;
}