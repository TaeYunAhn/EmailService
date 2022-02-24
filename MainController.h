#pragma once
#include <string>
#include <iostream>
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

    //void ShowMail();
    //void SendMail();

private:
    AccController *accController;
    EmailController *emailController;
};