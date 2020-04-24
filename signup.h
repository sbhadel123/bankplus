#ifndef SIGNUP_H
#define SIGNUP_H
#include <gtkmm.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class PersonInfo
{
    public:
      string first_name;
      string last_name;
      string date_of_birth;
      string password;
      string credit_card_info;
      string checkingAccount_bal;
      string savingAccount_bal;
      string account_number;

      void File_Read(string line);
};


class Person
{
public:
    std::string first_name;
    std::string last_name;
    std::string dateOfBirth;
    std::string newPassword;
    std::string creditCardNo;
    std::string exprationDate;
    std::string securityId;
    Gtk::Image image;
    Person();
};
class Info_box:public Gtk::Window
{
public:
    Info_box(std::string first_name, std::string last_name, std::string dateOfBirth,
    std::string newPassword, std::string creditCardNo,
    std::string exprationDate, std::string securityId);
    virtual ~Info_box();

    Gtk::Label label, label1, label2, label3, label5,label6,label7;
    Gtk::Button register_button;
    Gtk::Grid grid;
    Gtk::VBox vbox;
    Gtk::HBox hbox;
    Gtk::Image image;
    Gtk::Box box;

protected:
    void register_function();
};

class Validator {
public:
    bool check_validity (std::string cardNumber);
};
#endif
