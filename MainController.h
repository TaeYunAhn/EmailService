#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include "AccController.h"
#include "EmailController.h"
using namespace std;

class AccController;
class EmailController;
class MainController
{
public:
    MainController();
    ~MainController();

    void start();
    void MailStart(string &ID);

    void SignUpID(string &ID, string &PW);
    //FILE *fopen(const char *acc, const char *w);

    //void ShowMail();
    //void SendMail();

private:
    AccController *accController;
    EmailController *emailController;
};