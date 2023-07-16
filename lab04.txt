#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Student
{
public:
    string name;
    string usn;
    string age;
    string sem;
    string branch;
    string buffer;
};

void writeRecord()
{
    ofstream file;
    Student s;
    int k, rrn = 0, n;
    file.open("program_4.txt", ios::app);
    if (!file)
    {
        cout << "\nCannot open the file in append mode\n";
        exit(0);
    }
    cout << "How many records: ";
    cin >> n;
    for (k = 0; k < n; k++)
    {
        cout << "\nEnter the student name: ";
        cin >> s.name;
        cout << "Enter the usn: ";
        cin >> s.usn;
        cout << "Enter the age: ";
        cin >> s.age;
        cout << "Enter the sem: ";
        cin >> s.sem;
        cout << "Enter the branch: ";
        cin >> s.branch;
        file << rrn << "|" << s.name << "|" << s.usn << "|"
             << s.age << "|" << s.sem << "|" << s.branch << "\n";
        rrn++;
    }
    file.close();
}

void displayFile()
{
    ifstream file;
    Student s;
    string rrn;
    int rrnValue = 0;
    file.open("program_4.txt");
    if (!file)
    {
        cout << "\nCannot open the file in input mode\n";
        exit(1);
    }
    cout << "\nRRN\tName\t\tUSN\t\tAge\t\tSem\t\tBranch\n";
    while (getline(file, s.buffer))
    {
        stringstream ss(s.buffer);
        getline(ss, rrn, '|');
        getline(ss, s.name, '|');
        getline(ss, s.usn, '|');
        getline(ss, s.age, '|');
        getline(ss, s.sem, '|');
        getline(ss, s.branch);
        cout << rrnValue << "\t" << s.name << "\t\t" << s.usn << "\t\t" << s.age << "\t\t" << s.sem << "\t\t" << s.branch << endl;
        rrnValue++;
    }
    file.close();
}


void search()
{
    ifstream file;
    Student s;
    string rrn;
    int rrnValue = 0;
    int searchRRN;
    file.open("program_4.txt");
    if (!file)
    {
        cout << "\nCannot open the file in input mode";
        exit(0);
    }
    cout << "\nEnter the RRN to be searched: ";
    cin >> searchRRN;
    cout << "\nRRN\tName\t\tUSN\t\tAge\t\tSem\t\tBranch\n";
    while (getline(file, s.buffer, '|'))
    {
        rrn = s.buffer;
        getline(file, s.name, '|');
        getline(file, s.usn, '|');
        getline(file, s.age, '|');
        getline(file, s.sem, '|');
        getline(file, s.branch, '\n');
        if (rrnValue == searchRRN)
        {
            cout << rrnValue << "\t" << s.name << "\t\t" << s.usn << "\t\t" << s.age << "\t\t" << s.sem << "\t\t" << s.branch << endl;
            cout << "\nRecord found\n";
            file.close();
            return;
        }
        rrnValue++;
    }
    cout << "\nRecord not found\n";
    file.close();
}

int main()
{
    int choice;
    while (1)
    {
        cout << "\n0: Exit";
        cout << "\n1: Insert";
        cout << "\n2: Search";
        cout << "\n3: Display";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            writeRecord();
            break;
        case 2:
            search();
            break;
        case 3:
            displayFile();
            break;
        case 0:
            exit(0);
        default:
            cout << "\nInvalid option";
            break;
        }
    }
    return 0;
}

