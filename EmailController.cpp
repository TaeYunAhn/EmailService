#include "EmailController.h"
#include "FileSaving.h"

EmailController::EmailController()
{
    map<string, vector<s_mail> > emailData;
    if (FileSaving::readMail(emailData))
        mailList = emailData;
}
EmailController::~EmailController()
{
}

void EmailController::ShowMailList(string &id)
{
    string &key = id;
    vector<s_mail> &value = mailList[key];
    if (mailList[id].empty())
    {
        cout << "no mail in (" << id << ")" << endl
             << endl;
        return;
    }

    for (int i = 0; i < value.size(); i++)
    {
        //cout << mailList[id][i];
        s_mail &mail = value[i];
        cout << "from : " << mail.From << endl;
        cout << "title : " << mail.Title << endl;
        cout << "contents : " << mail.Contents << endl
             << endl;
        ;
    }

    //for (const auto &a : mailList)
    //{
    //    a.first;
    //     for ( const auto& v :a.second )
    //     {

    //     }
    //}
}

void EmailController::sendMail(const string &to, const string &from, const string &title, const string &contents, const vector<EmailAcc> &totalAcc)
{

    s_mail t_mail(to, from, title, contents);
    mailList[to].push_back(t_mail);
    //to 의 대상이 있는지 없는지 확인
    /*bool find = false;
    for (int i = 0; i < totalAcc.size(); i++)
    {
        if (totalAcc[i].ID == to)
            find = true;
    }*/
    //if (totalAcc[i].ID != to)
    //    cout << "not available account" << endl;

    FileSaving::saveMail(mailList);
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