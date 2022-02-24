#include "EmailController.h"

EmailController::EmailController()
{
}
EmailController::~EmailController()
{
}

void EmailController::ShowMailList(string &id)
{
    string &key = id;
    vector<s_mail> &value = mailList[key];
    for (int i = 0; i < value.size(); i++)
    {
        //cout << mailList[id][i];
        s_mail &mail = value[i];
        cout << mail.From;
        cout << mail.Title;
        cout << mail.Contents;
    }

    //for (const auto &a : mailList)
    //{
    //    a.first;
    //     for ( const auto& v :a.second )
    //     {

    //     }
    //}
}

void EmailController::sendMail(s_mail &m, string &to, string &from, string &title, string &contents)
{

    mailList[m.To].push_back(m);
    mailList[m.From].push_back(m);
    mailList[m.Title].push_back(m);
    mailList[m.Contents].push_back(m);
}

/*void EmailController::Show_All(string &ID)
{
    cout << "From : " << t_mail.From << endl;
    cout << "To : " << t_mail.To << endl;
    cout << "Title : " << t_mail.Title << endl;
    cout << "Contents : " << t_mail.Contents << endl;
}*/

/*EN_RESULT AccController::SignUP(const string &ID, const string &PW)
{
    for (int i = 0; i < emailAccounts.size(); i++)
    {
        if (emailAccounts[i].ID == ID)
        {
            LoginService(EN_EXIST_ALREADY);
        }
    }
    EmailAcc emailAcc(ID, PW);
    emailAccounts.push_back(emailAcc);
    LoginService(EN_SIGNUP_SUCCESS);
} */