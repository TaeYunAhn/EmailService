#include "AccController.h"
#include "EmailController.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

class FileSaving
{
public:
    static bool readAcc(vector<EmailAcc>& emailAccounts);
    static bool saveAcc(const vector<EmailAcc>& emailAccounts);
    static bool readMail(map<string, vector<s_mail> >& mailList);
    static bool saveMail(const map<string, vector<s_mail> >& mailList);
};