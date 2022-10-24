#include<iostream>
#include<iomanip>
using namespace std;

/**
 * 常用的用于格式控制的流操纵符，使用时必须包含头文件 iomanip
 * dec                                   设置数值为十进制
 * hex                                   设置数值为十六进制
 * oct                                    设置数值为八进制
 * setfill(c)                            设置填充字符c，可以是字符常量或变量
 * setprecision(n)                 设置浮点数的精度为n位，在以一般十进制小数输出时，n代表有效数字
 *                                              在以 fixed 形式或 scientific 形式输出时，n为小数位数
 * setw(n)                              设置字段宽度为n位
 * setiosflags(ios::fixed)        设置浮点数以固定的小数位数显示
 * setiosflags(ios::scientific)  设置浮点数以指数形式显示
 * 
 * ------------------------------------------------------------------------------------
 * setiosflags(ios::left)               输出数据左对齐
 * setiosflags(ios::right)             输出数据右对齐
 * setiosflags(ios::skipws)         忽略前导的空格
 * setiosflags(ios::uppercase)         数据以十六进制形式输出时字母为大写
 * setiosflags(ios::lowercase)         数据以十六进制形式输出时字母为小写
 * setiosflags(ios::showpos)         输出正数时给出符号“+”
*/
int main() {
    double x = 1234567.89, y = 1.23456789;
    cout << "无格式：x=" << x << ", y=" << y << endl;
    cout << "保留5位有效数字：x=" << setprecision(5) << x << ", y=" << y << endl;
    cout << "保留小数点后5位：x=" << fixed << setprecision(5) << x << ", y=" << y << endl;
    cout << "保留科学计数法，且保留小数点后5位：x=" << scientific << setprecision(5) << x << ", y=" << y << endl;
    cout << "非负数显示正号，输出宽度为12字符，宽度不足时中间用'*'填充 x=" << showpos << fixed << setw(12) << setfill('*') << x << ", y=" << y << endl;
    cout << "非负数不显示正号，输出宽度为12字符，宽度不足时右边用填充字符填充 y=" << noshowpos <<  setw(12) << left << y  << endl;
    cout << "输出宽度为12字符，宽度不足时中间用左边用填充字符填充 y=" << setw(12) << right << y << endl;
    cout << "宽度不足时，负号和数值分列左右，中间用填充字符填充 -y= " << setw(12) << internal << -y << endl;
    return 0;
}