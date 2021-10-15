/* Abdulrazzak Jouhar 2020 */

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void reguser(string regname, string regpass);
void loguser(string logname, string logpass);

int main()
{
    string relog;
    string name;
    string pas;
    cout << "Login or Register ? ";
    cin >> relog;
    
    // handle terminal to virable h
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    

    if (relog == "register" || relog == "reg")
    {
        cout << "enter name: ";
        cin >> name;

        cout << "enter password: ";
        cin >> pas;

        reguser(name,pas);
    }
    else if (relog == "login" || relog == "log")
    {
        cout << "enter name: ";
        cin >> name;

        cout << "enter password: ";
        cin >> pas;

        loguser(name,pas);
    }
    else
    {
        // change color to red
        SetConsoleTextAttribute(h,12);
        cout << "Invalid syntax" << endl;
        // return color to white after exit
        SetConsoleTextAttribute(h, 15);
    }

    return 0;
    
}

void reguser(string regname, string regpass)
{
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    // creating and opening file in append mode
    fstream rfile ("logreg.txt", ios::app);
    rfile << regname << "," << regpass << endl;
    SetConsoleTextAttribute(h,10);
    cout << "Registerd" << endl;
    SetConsoleTextAttribute(h,15);
    rfile.close();
}

void loguser(string logname, string logpass)
{
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    // reading  file
    fstream lfile ("logreg.txt", ios::in);
    string line;
    string userinfo;
    bool done = false;

    userinfo = logname + "," + logpass;

    if (lfile.is_open())
    {
        while(getline(lfile,line))
        {
            if (line == userinfo)
            {
                done = true;
                break;
            }
            
        }
        if (done == true)
        {
            SetConsoleTextAttribute(h,10);
            cout << "Loggedin" << endl;
            SetConsoleTextAttribute(h,15);
        }
        else
        {
            SetConsoleTextAttribute(h,12);
            cout << "Wrong username or password";
            SetConsoleTextAttribute(h,15);
        }
        
        lfile.close();
    }
}

// some other colors... (there's numbers from 1 -> 255 whith different modes)

// 14 -> yellow
// 11 -> cyan
// 13 -> purple