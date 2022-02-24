#include "MainController.h"

MainController::MainController()
{
    accController = new AccController();
}

MainController::~MainController()
{
    delete accController;
}

void MainController::start()
{
    while (1)
    {
        int sel = 0;
        cout << "-----Menu-----" << endl;
        cout << "1.회원가입" << endl;
        cout << "2.로그인" << endl;
        cout << "3.종료" << endl;
        cout << "선택: ";
        cin >> sel;
        cout << "\n";

        switch (sel)
        {
        case 1:
        {

            string ID;
            string PW;
            cout << "ID : ";
            cin >> ID;
            cout << endl;
            cout << "PW : ";
            cin >> PW;
            cout << endl;
            const EN_RESULT res = accController->SignUP(ID, PW);
        }
        break;
        case 2:
        {
            string ID;
            string PW;
            cout << "ID : ";
            cin >> ID;

            cout << "PW : ";
            cin >> PW;
            cout << endl;
            const EN_RESULT res = accController->Login(ID, PW);
            if (res == EN_LOGIN_SUCCESS)
                MainController::MailStart(ID);
        }
        break;
        case 3:
        {
            return;
        }
        break;
        }
    }
}

void MainController::MailStart(string &ID)
{
    s_mail m;

    while (1)
    {
        int sel = 0;
        cout << "-----" << ID << "'s Menu-----" << endl;
        cout << "1.보관함" << endl;
        cout << "2.메일 쓰기" << endl;
        cout << "3.로그아웃" << endl;
        cout << "4.종료" << endl;
        cout << "선택: ";
        cin >> sel;
        cout << "\n";

        switch (sel)
        {
        case 1:
        {
            emailController->ShowMailList(ID);
            cout << "----Mail List----" << endl;
            //emailController->Show_All(ID);
        }
        break;
        case 2:
        {
            string to, from, title, contents;
            cout << "----Send Mail----" << endl;
            cout << "1. To : ";
            cin >> to;
            cout << endl;

            cout << "2. From : ";
            cin >> from;
            cout << endl;

            cout << "3. Title : ";
            cin >> title;
            cout << endl;

            cout << "4. Contents : ";
            cin >> contents;
            cout << endl;

            emailController->sendMail(m, to, from, title, contents);
            cout << "Sending Complete";
        }
        break;
        case 3:
        {
            return;
        }
        break;
        }
    }
}
