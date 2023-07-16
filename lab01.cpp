#include <fstream>
#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main()
{
    char name[10][20];
    char temp[20];
    char ifilename[15], ofilename[15];
    int num, i;
//    clrscr();
    cout << "Enter how many names you want to enter" << endl;
    cin >> num;
    cout << "Enter the names" << endl;
    for (i = 0; i < num; i++)
        cin >> name[i];
    cout << "Names in the reverse order" << endl;
    for (i = 0; i < num; i++)
        cout << strrev(name[i]) << endl;
    cout << "Enter the input file name which contains list of names" << endl;
    cin >> ifilename;
    cout << "Enter the output file name where reversed list of names has to be written" << endl;
    cin >> ofilename;
    ifstream infile(ifilename);
    ofstream outfile(ofilename);
    if (!infile)
    {
        cout << "Could not open the specified file" << endl;
        getch();
        exit(0);
    }
    while (!infile.eof())
    {
        infile.getline(temp, 20, '\n');
        outfile << strrev(temp) << endl;
    }
    outfile.close();
    infile.close();
    cout << "Output written to file " << ofilename << endl;
    getch();
    return 0;
}

