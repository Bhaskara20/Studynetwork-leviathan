#ifndef PROJECT02_H
#define PROJECT02_H

using namespace std;

void LoginScreen();

void writeUserInfo(ofstream & fout, string & first, string & last, string & year, string & screen);
void registerUser(ofstream & fout, string screen);
void listUsers();

class UserInfo
{
    public:
        string getFirstName();
        void setFirstName(string first);
        string getLastName();
        void setLastName(string last);
        string getBirthYear();
        void setBirthYear(string year);
        string getScreenName();
        void setScreenName(string sn);
        void signUp();
        void signIn();
        void displayProfile();
    private:
        string _firstName;
        string _lastName;
        string _birthYear;
        string _screenName;
};

#endif // PROJECT02_H