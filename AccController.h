#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

enum EN_RESULT
{
    EN_SIGNUP_SUCCESS,
    EN_LOGIN_SUCCESS,
    EN_EXIST_ALREADY,
    EN_NOT_EXIST_ACC,
    EN_WRONG_PW,
};

struct EmailAcc
{
    EmailAcc() {}
    EmailAcc(string _ID, string _PW) : ID(_ID), PW(_PW) {}
    ~EmailAcc() {}
    string ID;
    string PW;
};

class AccController
{
public:
    AccController();
    ~AccController();

    EN_RESULT SignUP(const string &ID, const string &PW);
    EN_RESULT Login(const string &ID, const string &PW);
    void LoginService(EN_RESULT error); //PrintLoginResult 로 이름 변경
    vector<EmailAcc> GetTotalAcc();
    // int GetA() { return a; }
    // int SetA(int val) { a = val; }

private:
    vector<EmailAcc> emailAccounts;
    //vector<s_mail> mailContents;
    int a;
};