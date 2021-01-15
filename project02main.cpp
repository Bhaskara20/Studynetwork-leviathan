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
    cout << "Mangga pilih dulu mau ngapain disini :" << endl << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "3. User list" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Pakek angka opsionalnya ya milihnya, jangan ngaco (masukin 1, 2, 3, or 4): ";
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

    cout << "Nama depan nya apa nich: ";
    cin >> fName;
    setFirstName(fName);

    cout << "Nama belakang juga dong sekalian : ";
    cin >> lName;
    setLastName(lName);

    cout << "pingin tau tahun berapa lahirnya, kalik aja sama.. jodoh ntar : ";
    cin >> bYear;
    setBirthYear(bYear);

    cout << "Buat panggilan sayang km sendiri, biar aku bisa manggil km pke panggilan sayang (nickname mksdnya): ";
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
                cout << "Panggilan sayang nya " << screenName << " udah dipake org lain, ganti gih.. nnti salah panggil.. pada cemburu semua : ";
            }
        }
        fin.close();
    } while (isTaken = true && isTaken != false);

    setScreenName(screenName);

    cout << endl;
    cout << "Data yg km daftarin td, saya simpan seperti ini yaaa :" << endl;
    cout << endl;
    cout << "Nama Panjang : " << getFirstName() << " " << getLastName() << endl;
    cout << "Tahun lahir : " << getBirthYear() << endl;
    cout << "Panggilan sayang : " << getScreenName() << endl;
    cout << "Sekarang coba deh km login skrg." << endl;
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
    cout << "Ayang-ayang yang udah tersimpan dalam memori ku (aku gapunya gender, jd segala gender aku doyan): " << endl << endl;
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

    cout << "Masukin panggilan sayang mu tadi : ";
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
                    cout << "Seinget ku panggilan sayang mu bukan " << screenName << " deh :( " << endl << endl;
                    cout << "Ulang lagi deh : ";
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


int main()
{
    char input;
    UserInfo inputInfo;

    cout << "Welcome to MyFace, a social media network where you can post your thoughts and see what your friends are up to." << endl << endl;

    do
    {
        LoginScreen();
        cin >> input;
        cout << endl;
        if (input == '1' && input != '2' && input != '3')
        {
            inputInfo.signUp();
        }
        else if (input == '2' && input != '3')
        {
            inputInfo.signIn();
        }
        else if(input == '3')
        {
            listUsers();
            cout << endl;
            system("PAUSE");
            cout << endl;
            LoginScreen();
        }
        else if (input != '1' && input != '2' && input != '3' && input != '4')
        {
            cout << "Invalid choice! Redirecting to login page..." << endl << endl;
        }
        else if (input == '4')
        {
            cout << "Thank you for using MyFace." << endl;
        }
    } while (input != '4');

    return 0;
}
