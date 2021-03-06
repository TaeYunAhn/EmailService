
#include "FileSaving.h"



bool FileSaving::readAcc(vector<EmailAcc> &emailAccounts)
{
    FILE *fd = fopen("Acc.txt", "r");

    if (!fd)
        return false;

    char line[512];
    char *pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
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
            emailAccounts.push_back(a); // ??????ü
            //emailAccounts.push_back(EmailAcc(id, pw)); // ?ӽð?ü
        }
    }
    fclose(fd);
    return true;
}

bool FileSaving::saveAcc(const vector<EmailAcc> &emailAccounts)
{
    FILE *fd = fopen("Acc.txt", "w");

    if (!fd)
        return false;

    for (int i = 0; i < emailAccounts.size(); i++)
    {
        fputs((emailAccounts[i].ID + "," + emailAccounts[i].PW + "\n").c_str(), fd);
    }
    fclose(fd);
    return true;
}

bool FileSaving::readMail(map<string, vector<s_mail> > &mailList)
{
    FILE *fd = fopen("Email.txt", "r");

    if (!fd)
        return false;

    char line[512];
    char *pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
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
            continue;
        else
            to = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)
            continue;
        else
            title = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)
            continue;
        else
        {
            ptr[strlen(ptr) - 1] = '\0';
            contents = ptr;
        }
        mailList[to].push_back(s_mail(from, to, title, contents));
        fclose(fd);
        return true;
    }
}

bool FileSaving::saveMail(const map<string, vector<s_mail> > &mailList)
{
    FILE *fd = fopen("Email.txt", "w");

    if (!fd)
        return false;
    /*for (auto itr = mailList.begin(); itr != mailList.end(); itr++)
    {
        string id;
        itr->first;
        for (int i = 0; i < itr->second.size(); i++)
        {
            itr->second[i].To = mailList[id].To;
            itr->second[i].From = mailList[].From;
        }
    }*/

    for (const pair<string, vector<s_mail> > &a : mailList)
    {
        for (auto &m : a.second)
        {
            std::string tmp = m.From + "," + m.To + "," +
                              m.Title + "," + m.Contents + "\n";

            fputs(tmp.c_str(), fd);
        }
    }
    fclose(fd);
    return true;
}

// normal loop
/*for (auto itr = mailList.begin(); itr != mailList.end(); itr++)
    {
        string id;
        itr->first;
        for (int i = 0; i < itr->second.size(); i++)
        {
            itr->second[i].To = mailList[id].To;
            itr->second[i].From;
        }
    }*/

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
