#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

/**
 * 访问方式
 * ios::in 输入方式
 * ios::out 输出方式
 * ios::app 以输出方式打开，并且以追加的形式进行写入
 * ios::ate 打开一个已有的文件，文件指针指向文件末尾
 * ios::trunc 打开一个文件，如果文件已存在则删除全部数据，如文件不存在则建立
 * ios::binary 以二进制方式打开文件，如不指定此方式则默认以ASCII码方式打开
 * ios::in | ios:: out 以输入和输出方式打开文件，文件可读可写
 * ios::out | ios::binary 以二进制方式打开输出文件
 * ios::in | ios::binary 以二进制方式打开输入文件
 * 
 * 对二进制文件的读写主要用 istream 类的成员函数 read 和 write 函数实现
 * 例如：a.write(p, 40);    # 将p1指向的单元开始的40个字节内容写到与a关联的磁盘文件中
 * 例如： b.read(p2, 40);  # 将b所关联的文件中，读入40个字节内容存放到以p2指针指定的位置开始往后的40个字节的一段内容
 * 
 * 随机访问文件
 * 可以在文件的任意位置读取或写入内容
 * gcout() 得到最后一次输入所读入的字节数
 * tellg() 得到输入文件位置标记的当前位置
 * tellp() 得到输出文件位置标记的当前位置
 * seekg(文件中的位置
 * seekg(位移量, 参照位置)
 * seekp(文件中的位置) ???
 * seekp(位移量, 参照位置) ???
 * 
 * <文件中的位置> 是相对于文件头的流中的位置
 * <位移量> 也是long型字节数
 * <参照位置> 为枚举常量，具有下述含义：
 *     ios::beg    //=0，文件头的位置
 *     ios::cur     //=1，当前标记的位置
 *     ios::end    //=2，文件尾的位置
 * 
 * input.seekg(200);                      // 位置标记向前移动200字节
 * input.seekg(100, ios::beg);       // 位置标记移到文件头后100字节处
 * input.seekg(50, ios::cur);          // 位置标记移动到当前位置后50字节
 * input.seekg(-20, ios::end);       // 位置标记移动到文件尾前 20 字节
 * 
*/
void test();
int main() {
    test();
    return 0;
}

void test() {
    string readFile = "/opt/test/cpp-test/reader.txt";
    string wirteFile = "/opt/test/cpp-test/writer.txt";
}