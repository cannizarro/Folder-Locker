#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("haha",ios::out);
    file<<"hello";
    void close();
    return 1;
}