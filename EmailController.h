#include <iostream>
#include <vector>
#include "AccController.h"

using namespace std;

struct s_mail
{
    string To;
    string From;
    string Title;
    string Contents;
};

/*struct EmailList
{
    EmailList()
    ~EmailList() {}
};*/

class EmailController
{
public:
    EmailController();
    ~EmailController();

    void Show_All(string &ID);
    void ShowMailList(string &id);
    void sendMail(s_mail &m, string &to, string &from, string &title, string &contents);

    //private:
    static map<string, vector<s_mail> > mailList;
};

//파일을 할거면...
//세이빙, 로드 시점.. 중요
// 세이빙은 회원가입 할때마다 하는게 좋음
//로드는 프로그램 키면 ㅇㅇ
// 파일 저장
// 받은 메일만 저장
// 계정마다 메일 내용
//

//맵의 키는 어카운트
// 맵의 밸류는 백터
// 백터의 타입은 구조체
// 구조체 안에는
