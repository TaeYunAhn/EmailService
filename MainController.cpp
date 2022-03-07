#include "MainController.h"

MainController::MainController()
{
    accController = new AccController();
    emailController = new EmailController();
}

MainController::~MainController()
{
    delete accController;
    delete emailController;
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
            cout << "PW : ";
            cin >> PW;
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
            {
                //cout << "LOGIN_SUCCESS" << endl;
                MainController::MailStart(ID);
            }
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
    //s_mail m;

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

            cout << "----Mail List----" << endl;
            emailController->ShowMailList(ID);
            //emailController->Show_All(ID);
        }
        break;
        case 2:
        {
            vector<EmailAcc> totalAcc;
            totalAcc = accController->GetTotalAcc();

            string to, from, title, contents;
            cout << "----Send Mail----" << endl;
            cout << "1. To : ";
            cin >> to;
            bool find = false;
            for (int i = 0; i < totalAcc.size(); i++)
            {
                if (to == totalAcc[i].ID)
                {
                    find = true;
                    break;
                }
            }

            if (find == false)
                return (accController->LoginService(EN_NOT_EXIST_ACC));

            // 1. 아예 여기서 gettotalAcc 가져와서 있는지 없는지 확인
            // 2. EmailController sendMail 에서 값이 있는지 없는지 확인

            cout << "2. From : ";
            cin >> from;

            cout << "3. Title : ";
            cin >> title;

            cout << "4. Contents : ";
            cin >> contents;
            cout << endl;

            emailController->sendMail(to, from, title, contents, totalAcc);
            cout << "Send Complete" << endl
                 << endl;
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