#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    ofstream fldr;
    char a[100];
    cin>>a;
    strcat(a,"\\Desktop.ini");
    fldr.open(a,ios::out);
    fldr << "[.shellClassInfo]" << endl;
    fldr<<"helllaaa"<<endl;
    return 0;
}