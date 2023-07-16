#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student
{
public:
    string name;
    string usn;
    string age;
    string sem;
    string branch;
};

fstream file;
Student s;

void writeRecord()
{
    file.open("program_3.txt", ios::app);
    if (!file)
    {
        cout << "Cannot open the file in append mode";
        exit(1);
    }

    cout << "\nEnter the student name: ";
    cin >> s.name;
    cout << "Enter the USN: ";
    cin >> s.usn;
    cout << "Enter the age: ";
    cin >> s.age;
    cout << "Enter the sem: ";
    cin >> s.sem;
    cout << "Enter the branch: ";
    cin >> s.branch;

    file << s.name << "|" << s.usn << "|" << s.age << "|" << s.sem << "|" << s.branch << endl;
    file.close();
}

void search()
{
    string usn;
    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\nUnable to open the file in read mode";
        exit(0);
    }

    cout << "\nEnter the record's USN you want to search: ";
    cin >> usn;

    while (getline(file, s.name, '|'))
    {
        getline(file, s.usn, '|');
        getline(file, s.age, '|');
        getline(file, s.sem, '|');
        getline(file, s.branch);

        if (s.usn == usn)
        {
            cout << "\nRecord found";
            cout << "\nname\tusn\tage\tsem\tbranch";
            cout << "\n" << s.name << "\t" << s.usn << "\t";
            cout << s.age << "\t" << s.sem << "\t" << s.branch;
            file.close();
            return;
        }
    }

    cout << "\nRecord not found";
    file.close();
}

void displayFile()
{
    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\ncannot open the file in read mode";
        exit(1);
    }

    cout << "\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH";
    cout << "\n----------------------------------------";

    while (getline(file, s.name, '|'))
    {
        getline(file, s.usn, '|');
        getline(file, s.age, '|');
        getline(file, s.sem, '|');
        getline(file, s.branch);

        cout << "\n" << s.name << "\t\t" << s.usn << "\t\t" << s.age << "\t\t" << s.sem << "\t\t" << s.branch;
    }

    file.close();
}

void modify()
{
    string usn;
    string newValues[4];
    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\nUnable to open the file in input mode";
        exit(1);
    }

    cout << "\nEnter the USN: ";
    cin >> usn;

    ofstream tempFile("temp.txt");

    while (getline(file, s.name, '|'))
    {
        getline(file, s.usn, '|');
        getline(file, s.age, '|');
        getline(file, s.sem, '|');
        getline(file, s.branch);

        if (s.usn == usn)
        {
            cout << "\nThe old values of the record with USN " << usn << " are:";
            cout << "\nName: " << s.name;
            cout << "\nUSN: " << s.usn;
            cout << "\nAge: " << s.age;
            cout << "\nSem: " << s.sem;
            cout << "\nBranch: " << s.branch;
            cout << "\nEnter the new values:\n";
            cout << "Name: ";
            cin >> newValues[0];
            cout << "Age: ";
            cin >> newValues[1];
            cout << "Sem: ";
            cin >> newValues[2];
            cout << "Branch: ";
            cin >> newValues[3];
            tempFile << newValues[0] << "|" << s.usn << "|" << newValues[1] << "|" << newValues[2] << "|" << newValues[3] << endl;
        }
        else
        {
            tempFile << s.name << "|" << s.usn << "|" << s.age << "|" << s.sem << "|" << s.branch << endl;
        }
    }

    tempFile.close();
    file.close();

    remove("program_3.txt");
    rename("temp.txt", "program_3.txt");
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n0: Exit";
        cout << "\n1: Write to file";
        cout << "\n2: Display the file";
        cout << "\n3: Modify the file";
        cout << "\n4: Search";
        cout << "\n\nEnter the choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                writeRecord();
                break;
            case 2:
                displayFile();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 0:
                exit(0);
            default:
                cout << "\nInvalid input...";
                break;
        }
    }

    return 0;
}

