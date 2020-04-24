#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include "signup.h"

using namespace std;

bool Validator::check_validity (string cardNumber)
{
    int lastDigit;
    vector <int> creditL;

    for (int i = 0; i < cardNumber.size(); i++)
    {
        char a=cardNumber[i];
        int r= a - '0';
        creditL.push_back(r);
    }

    lastDigit=creditL[((cardNumber.size())-1)];

    for (int i=(creditL.size())-2; i>= 0; i=i- 2)
    {
        int MultiplyOdd = creditL[i];
        MultiplyOdd = MultiplyOdd * 2;
        if (MultiplyOdd > 9) {
            MultiplyOdd = MultiplyOdd % 10 + 1;
        }
        creditL[i]=MultiplyOdd;
    }

    int sum = 0;
    for (int i = 0; i < (creditL.size())-1; i++) {
        sum += creditL[i];
    }

    int m=sum % 10;
    int x;
    if(m==0)
        x=0;
    else
        x=10-m;


    if (x == lastDigit)
    {
         return true;
    }

    else
    {
        return false;
    }



}

/*
int main( )
{
    Validator v1;
    string a="379812697382001";
    string b="49927398717";
    string c="1234567812345678";
    string d="1234567812345670";
    string e="4111111111111111";

    bool val1=v1.check_validity(a);
    cout<< "\nThe first credit card is valid."<<val1<<endl;
    bool val2=v1.check_validity(b);
    cout<< "\nThe second credit card is valid."<<val2<<endl;
    bool val3=v1.check_validity(c);
    cout<< "\nThe third credit card is valid."<<val3<<endl;
    bool val4=v1.check_validity(d);
    cout<< "\nThe fourth credit card is valid."<<val4<<endl;
    bool val5=v1.check_validity(e);
    cout<< "\nThe fifth credit card is valid."<<val5<<endl;
    return 0;
}
*/
