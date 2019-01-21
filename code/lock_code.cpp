#include<conio.h>
#include <iostream>
#include <fstream>
#include <windows.h>    // can learn about all function at microsoft windows docs
using namespace std;

void setColor(int color);
void lockFolder();
void unlockFolder();

int main()
{
    int ch=0;
    SetConsoleTitle("\n\nFolder Lock");
    system("CLS"); 
    label:
    setColor(11);
    cout<<"\t\tFolder Lock :";
    cout << "\n\n" << "Options:\t\t\t\n";
    cout << "\t======================\n";
    cout << "\t1. - Lock Folder.\n";
    cout << "\t2. - Unlock Folder.\n";
    cout << "\t3. - Exit.\n";
    cout << "\t======================  \n";

    setColor(4);
    cout << "\nEnter your choice: ";
    cin >> ch;
    int run;
    switch (ch)
    {
    case 1:
        lockFolder();
        goto label;
        break;
    case 2:
        unlockFolder();
        goto label;
        break;
    case 3:
        setColor(7);
        exit(0);
    default: 
        cout << "\nInvalid Entry.....\n";
        goto label;
    }
    cout<<"\nPress any key to exit\n";
    getch();
    setColor(7);
    return 0;
}

void setColor(int colour)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, colour);
}

void lockFolder()
{
    ofstream sfolder;
    char pass[200];
    char folder[200]; 
    char tempfolder[200];
    char attrib[200];
    setColor(10);
    
    fflush(stdin);
    cout << "\nEnter the complete path to the Folder: ";
    cin.getline(folder,200);

    cout<<"Enter password : ";
    cin>>pass;

   
    //system("attrib +s password.txt");

    strcpy(tempfolder,"\"");

    strcat(tempfolder, folder);

    strcat(tempfolder,"\"");

    strcat(folder, "\\Desktop.ini");
    
    sfolder.open(folder, ios::out);
    
    sfolder << "[.shellClassInfo]" << endl;
    sfolder << "CLSID = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;

    sfolder.close();
    strcpy(attrib, "attrib +h +s ");
    strcat(attrib, tempfolder);
    WinExec(attrib, 11); //can also use system() but using WinExec() just for information sake.

    system("if exist password.txt del password.txt");//deleting if any old files are present
    system("dir>password.txt");
    sfolder.open("password.txt",ios::out);
    sfolder<<pass;
    

    cout << "\n\n" << tempfolder << " has been locked successfully!\n";
}

void unlockFolder()
{
    ifstream sfolder;
    char folder[200];
    char pass[200];
    char passComp[200];
    char tempfolder[200];
    char attrib[200];
    char del[200];

    setColor(13);
    fflush(stdin);
    cout << "\nEnter the path of the Folder you want to unlock : ";
    cin.getline(folder,200);

    cout<<"Enter the password : \n";
    cin>>pass;

    sfolder.open("password.txt",ios::in);
    sfolder>>passComp;

    if(strcmp(passComp,pass))
    {
        cout<<"Password is incorrect\n";
        return;
    }

    strcpy(tempfolder,"\"");
    strcat(tempfolder, folder);
    strcat(tempfolder,"\"");

    strcat(folder, "\\Desktop.ini");

    strcpy(del, "if exist ");
    strcat(del, folder);
    strcat(del, "del ");
    strcat(del,folder);
    system(del);
    strcpy(attrib, "attrib -h -s ");
    strcat(attrib, tempfolder);
    
    system(attrib);  // same as above can use WinExec() but used this for simplicity
    cout << "\n\n" << tempfolder << " has been unlocked successfully!\n";
}
