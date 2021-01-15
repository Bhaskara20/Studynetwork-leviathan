#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include "project02.h"

using namespace std;

ofstream fout;
ifstream fin;

void LoginScreen()
{
    printf("Mangga pilih dulu mau ngapain disini :\n");
    printf("1. Register\n");
    printf("2. Log in\n");
    printf("3. User list\n");
    printf("4. Exit\n");
    printf("Pakek angka opsionalnya ya milihnya, jangan ngaco (masukin 1, 2, 3, or 4): \n");
}

void UserInfo::signUp()
{


    int offset;
    char line[100];
    bool isTaken;

    char fName[100];
    char lName[100];
    char bYear[100];
    char screenName[100];

    printf("Nama depan nya apa nich: ");
    scanf("[^\n]",fName); getchar();
    fflush(stdin);
    setFirstName(fName);

    printf("Nama belakang juga dong sekalian : ");
    scanf("%[^\n]",lName); getchar();
    fflush(stdin);
    setLastName(lName);

    printf("pingin tau tahun berapa lahirnya, kalik aja sama.. jodoh ntar : ");
    scanf("%[^\n]",bYear); getchar();
    fflush(stdin);
    setBirthYear(bYear);

    printf("Buat panggilan sayang km sendiri, biar aku bisa manggil km pke panggilan sayang (nickname mksdnya): \n)";
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
                printf("Panggilan sayang nya %s udah dipake org lain, ganti gih.. nnti salah panggil.. pada cemburu semua lagi : ",screenName);
            }
        }
        fin.close();
    } while (isTaken = true && isTaken != false);

    setScreenName(screenName);

    printf("\n");
    printf("Data yg km daftarin td, saya simpan seperti ini yaaa :\n");
    printf("\n");
    printf("Nama Panjang : %s %s\n",getFirstName(),getLastName());
    printf("Tahun lahir : %s\n",getBirthYear());
    printf("Panggilan sayang : %s\n",getScreenName());
    printf("Sekarang coba deh km login skrg.\n");
    printf("\n");

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
