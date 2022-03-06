#include "FileSaving.h"

bool FileSaving::readAcc(vector<EmailAcc>& emailAccounts)
{
    FILE *fd = fopen("Acc.txt", "r");

    if (!fd)
        return false;

    char line[OPEN_MAX];
    char *pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, OPEN_MAX, fd);
        string id;
        string pw;

        char *ptr = strtok(pLine, ",");
        if (ptr)
            id = ptr;
        ptr = strtok(NULL, ",");
        if (ptr)
        {
            ptr[strlen(ptr) - 1] = '\0';
            pw = ptr;
        }

        if (!id.empty() && !pw.empty())
        {
            EmailAcc a(id, pw);
            emailAccounts.push_back(a); // 지역객체
            //emailAccounts.push_back(EmailAcc(id, pw)); // 임시객체
        }
        
    }
    fclose(fd);
    return;
}

bool FileSaving::saveAcc(const vector<EmailAcc>& emailAccounts)
{
    FILE *fd = fopen("Acc.txt", "w");

    if (!fd)
        return false;

    for (emailAccounts)
    {
        fputs((emailAccounts.id + "," + emailAccounts.pw + "\n").c_str(), fd);
    }
    fclose(fd);
    return true;
}

bool FileSaving::readMail(map<string, vector<s_mail>>& mailList)
{
    FILE *fd = fopen("Email.txt", "r");

    if (!fd)
        return false;

    char line[OPEN_MAX];
    char *pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, OPEN_MAX, fd);
        if (!pLine)
            continue;

        string from;
        string to;
        string title;
        string contents;

        char *ptr = strtok(pLine, ",");
        from = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)
            return -1;
        else
            to = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)
            return -1;
        else
            title = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)
            return -1;
        else
            contents = ptr;
    }
}

bool FileSaving::saveMail(const map<string, vector<s_mail>>& mailList)
{
    FILE *fd = fopen("Email.txt", "w");

    if (!fd)
        return false;

    // normal loop
    for ( map<string, vector<s_mail>>::iterator itr = mailList.begin(); itr != mailList.end(); itr++ )
    {
        itr->first;
        for ( int i = 0; i < itr->second.size(); i++ )
        {
            itr->second[i].To;
        };
    }

    // map<int, int> test_map;
    // test_map[0] = 0;
    // test_map[1] = 1;

    // for ( pair<int, int>& t : test_map )
    // {
    //     t.second = 100;
    // }

    // for ( pair<int, int> t : test_map )
    // {
    //     cout << t.second;
    // }


    // range-based loop
    for ( const pair<string, vector<s_mail>>& m : mailList )
    {
        m.first;
        for ( s_mail vElem : m.second )
        {

        }
    }


    
    // for (sizeof(mailList.first))
    // {
    //     for (mailList.second)
    //     {
    //         string mail = mailList.first + "," + mailList.from + "," + mailList.to + "," +
    //                       mailList.title + "," + mailList.contents + "\n";

    //         fputs(mail.c_str(), fd);
    //     }
    //     fclose(fd);
    //     return true;
    // }
}
