#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "project02.h"

using namespace std;

ofstream fout;
ifstream fin;

void LoginScreen()
{
    cout << "Please select from the following options by entering the corresponding number:" << endl << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "3. User list" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Please make your selection (enter 1, 2, 3, or 4): ";
}

void UserInfo::signUp()
{


    int offset;
    string line;
    bool isTaken;

    string fName;
    string lName;
    string bYear;
    string screenName;

    cout << "Enter your first name: ";
    cin >> fName;
    setFirstName(fName);

    cout << "Enter your last name: ";
    cin >> lName;
    setLastName(lName);

    cout << "Enter your birth year: ";
    cin >> bYear;
    setBirthYear(bYear);

    cout << "Create your screen name (no special characters or spaces): ";
    do
    {
        cin >> screenName;
        isTaken = false;
        fin.open("RegisteredUsers.txt");
        while (!fin.eof())
        {
            getline(fin, line);
            if ((offset = line.find(screenName, 0)) != string::npos)
            {
                isTaken = true;
                cout << "The username " << screenName << " is already taken, please choose a different username: ";
            }
        }
        fin.close();
    } while (isTaken = true && isTaken != false);

    setScreenName(screenName);

    cout << endl;
    cout << "Registered with the following information:" << endl;
    cout << endl;
    cout << "Full name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Birth year: " << getBirthYear() << endl;
    cout << "Screen name: " << getScreenName() << endl;
    cout << "You may now log in to your newly created account." << endl;
    cout << endl;

    string infoFileName = screenName + "_info.txt";
    string followerFileName = screenName + "_follow.txt";
    string activityFileName = screenName + "_activity.txt";

    registerUser(fout, screenName);

    fout.open(infoFileName.c_str());
    writeUserInfo(fout, fName, lName, bYear, screenName);
    fout.close();
}

void writeUserInfo(ofstream & fout, string & first, string & last, string & year, string & screen)
{
    fout << first + " " + last + " " + year + " " + screen + " ";
}

void registerUser(ofstream & fout, string screen)
{
    fout.open("RegisteredUsers.txt", ios::app);
    fout << " " + screen;
    fout.close();
}

void listUsers()
{
    ifstream fin;
    string screen;
    cout << "The following users are registered: " << endl << endl;
    fin.open("RegisteredUsers.txt");
    while(!fin.eof())
    {
        fin >> screen;
        cout << screen << endl;
    }
    fin.close();
}

void UserInfo::signIn()
{
    int offset;
    string line;
    bool exists;
    string screenName;

    cout << "Please enter your screen name to sign in: ";
    do
    {
        cin >> screenName;
        exists = true;
            fin.open("RegisteredUsers.txt");
            while (!fin.eof())
            {
                getline(fin, line);
                if ((offset = line.find(screenName, 0)) == string::npos)
                {
                    exists = false;
                    cout << endl;
                    cout << "User " << screenName << " does not exist!" << endl << endl;
                    cout << "Please enter an existing username to sign in: ";
                }
            }
            fin.close();
    } while (exists = false || exists != true);
    cout << "You are now logged in as " + screenName << endl;
}

void UserInfo::displayProfile()
{

}

void UserInfo::setFirstName(string fName)
{
    _firstName = fName;
}

string UserInfo::getFirstName()
{
    return _firstName;
}

void UserInfo::setLastName(string lName)
{
    _lastName = lName;
}

string UserInfo::getLastName()
{
    return _lastName;
}

void UserInfo::setBirthYear(string bYear)
{
    _birthYear = bYear;
}

string UserInfo::getBirthYear()
{
    return _birthYear;
}

void UserInfo::setScreenName(string screenName)
{
    _screenName = screenName;
}

string UserInfo::getScreenName()
{
    return _screenName;
}