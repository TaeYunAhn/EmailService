#include "AccController.h"
#include <string>
#include <iostream>
#include "FileSaving.h"
using namespace std;

AccController::AccController()
{
    vector<EmailAcc> data;
    if (FileSaving::readAcc(data))
        emailAccounts = data;
}
AccController::~AccController()
{
}

EN_RESULT AccController::SignUP(const string &ID, const string &PW)
{
    for (int i = 0; i < emailAccounts.size(); i++)
    {
        if (emailAccounts[i].ID == ID)
        {
            LoginService(EN_EXIST_ALREADY);
            return EN_EXIST_ALREADY;
        }
    }
    EmailAcc emailAcc(ID, PW);
    emailAccounts.push_back(emailAcc);
    FileSaving::saveAcc(emailAccounts);
    LoginService(EN_SIGNUP_SUCCESS);
}

void AccController::LoginService(EN_RESULT error)
{
    if (error == EN_NOT_EXIST_ACC)
    {
        cout << "NOT_EXIST_ACC" << endl
             << endl;
    }
    else if (error == EN_LOGIN_SUCCESS)
    {
        cout << "LOGIN_SUCCESS" << endl
             << endl;
    }

    else if (error == EN_WRONG_PW)
    {
        cout << "WRONG_PW" << endl
             << endl;
    }
    else if (error == EN_EXIST_ALREADY)
    {
        cout << "EXIST_ALREADY" << endl
             << endl;
    }
    else if (error == EN_SIGNUP_SUCCESS)
    {
        cout << "SIGNUP_SUCCESS" << endl
             << endl;
    }
    else
    {
        cout << "error" << endl
             << endl;
    }
}

EN_RESULT AccController::Login(const string &ID, const string &PW)
{
    int i = 0;
    while (i < emailAccounts.size())
    {

        if (emailAccounts[i].ID == ID && emailAccounts[i].PW == PW)
        {
            LoginService(EN_LOGIN_SUCCESS);
            return EN_LOGIN_SUCCESS;
        }

        else if (emailAccounts[i].ID == ID && emailAccounts[i].PW != PW)
        {
            LoginService(EN_WRONG_PW);
            return EN_WRONG_PW;
        }

        else if (emailAccounts[i].ID != ID)
        {
            i++;
            if (i == emailAccounts.size())
            {
                LoginService(EN_NOT_EXIST_ACC);
                return EN_NOT_EXIST_ACC;
            }
        }
    }
}

vector<EmailAcc> AccController::GetTotalAcc()
{
    return emailAccounts;
}