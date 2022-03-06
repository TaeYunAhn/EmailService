#include "FileSaving.h"

bool FileSaving::readAcc(vector<EmailAcc> emailAccounts)
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

        //if (!id.empty() && !pw.empty())
        //emailAccounts = pw;
    }
    fclose(fd);
    return;
}
bool FileSaving::saveAcc(vector<EmailAcc> emailAccounts)
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
bool FileSaving::readMail(map<string, vector<s_mail> > mailList)
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
bool FileSaving::saveMail(map<string, vector<s_mail> > mailList)
{
    FILE *fd = fopen("Email.txt", "w");

    if (!fd)
        return false;
    for (sizeof(mailList.first))
    {
        for (mailList.second)
        {
            string mail = mailList.first + "," + mailList.from + "," + mailList.to + "," +
                          mailList.title + "," + mailList.contents + "\n";

            fputs(mail.c_str(), fd);
        }
        fclose(fd);
        return true;
    }
}
