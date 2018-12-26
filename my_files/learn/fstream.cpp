#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("test.txt",ios::out);
    file<<"namaste";
    void close();
    return 1;
}