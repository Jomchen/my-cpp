#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void testReadFile();
void testWriteFile();

/**
 * 文件流测试
 */
int main() {
    testReadFile();
    //testWriteFile();
    return 0;
}

/**
 * 测试读取文件
 */
void testReadFile() {
    string filePath = "/opt/test/reader.txt";
    ifstream infile;
    infile.open(filePath, ios::in);
    char data[30];
    //while (!infile.eof()) {
    //    infile.read(data, 30);
    //}
    infile.close();
}

/**
 * 测试写入文件
 */
void testWriteFile() {
    string outFilePath = "/opt/test/testWrite.txt";
    char data[100];
    ofstream outfile;
    outfile.open(outFilePath, ios::app);
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";

    cin.getline(data, 100, 'm');
    outfile << data << endl;
    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    outfile << data << endl;
    outfile.flush();
    outfile.close();
}