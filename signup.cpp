#include <gtkmm.h>
#include "signup.h"
//#include "main_window3.h"
#include <iostream>
#include <string>
//#include <vector>

using namespace std;

void PersonInfo::File_Read(string line)
{
        string intermidiate;
        stringstream ss(line);
        getline(ss,intermidiate,',');
        first_name = intermidiate;

        getline(ss,intermidiate,',');
        last_name = intermidiate;

        getline(ss,intermidiate,',');
        password = intermidiate;

        getline(ss,intermidiate,',');
        date_of_birth = intermidiate;

        getline(ss,intermidiate,',');
        credit_card_info = intermidiate;

        getline(ss,intermidiate,',');
        checkingAccount_bal = intermidiate;

        getline(ss,intermidiate,',');
        savingAccount_bal = intermidiate;

        getline(ss,intermidiate,'\n');
        account_number = intermidiate;
}
bool check_validity (string cardNumber)
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


Person::Person()
{
    Gtk::Window w;

    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_transient_for(w);
    dialog->set_size_request(400, 500);
    dialog->set_title("Sign Up Form");

    Gtk::Label *label = new Gtk::Label("Enter first name:");
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("Register",1);
    dialog->set_default_response(1);

    Gtk::Entry *entry_first = new Gtk::Entry();
    //entry_first->set_text("First Name");
    entry_first->set_max_length(50);
    entry_first->show();
    dialog->get_vbox()->pack_start(*entry_first);

    Gtk::Label *label1 = new Gtk::Label("Enter last name:");
    dialog->get_content_area()->pack_start(*label1);
    label1->show();

    Gtk::Entry *entry_last = new Gtk::Entry();
    //entry_last->set_text("Last Name");
    entry_last->set_max_length(50);
    entry_last->show();
    dialog->get_vbox()->pack_start(*entry_last);

    Gtk::Label *label2 = new Gtk::Label("Date of Birth:");
    dialog->get_content_area()->pack_start(*label2);
    label2->show();

    Gtk::Entry *entry_date = new Gtk::Entry();
    //entry_date->set_text("--/--/--");
    entry_date->set_max_length(50);
    entry_date->show();
    dialog->get_vbox()->pack_start(*entry_date);

    Gtk::Label *label3 = new Gtk::Label("New Password:");
    dialog->get_content_area()->pack_start(*label3);
    label3->show();

    Gtk::Entry *entry_password = new Gtk::Entry();
    //entry_password->set_text("New Password");
    entry_password->set_visibility(false);
    entry_password->set_max_length(50);
    entry_password->show();
    dialog->get_vbox()->pack_start(*entry_password);

    Gtk::Label *label5 = new Gtk::Label("Credit Card Number:");
    dialog->get_content_area()->pack_start(*label5);
    label5->show();

    Gtk::Entry *entry_creditCardNo = new Gtk::Entry();
   //entry_creditCardNo->set_text("################");
    entry_creditCardNo->set_max_length(50);
    entry_creditCardNo->show();
    dialog->get_vbox()->pack_start(*entry_creditCardNo);


    Gtk::Label *label6 = new Gtk::Label("Expiration date");
    dialog->get_content_area()->pack_start(*label6);
    label6->show();

    Gtk::Entry *entry_expDate = new Gtk::Entry();
    //entry_expDate->set_text("--/--");
    entry_expDate->set_max_length(50);
    entry_expDate->show();
    dialog->get_vbox()->pack_start(*entry_expDate);


    Gtk::Label *label7 = new Gtk::Label("Security ID");
    dialog->get_content_area()->pack_start(*label7);
    label7->show();

    Gtk::Entry *entry_securityId = new Gtk::Entry();
    //entry_securityId->set_text("###");
    entry_securityId->set_max_length(50);
    entry_securityId->show();
    dialog->get_vbox()->pack_start(*entry_securityId);
/*
    //I added this button here!
    auto _button = new Gtk::Button {"Register",false};
    _button->signal_pressed().connect([this]{Info_box box(this->first_name,this->last_name,this->dateOfBirth, this->newPassword, this->creditCardNo,this->exprationDate,this->securityId);Gtk::Main::run(box);});
    _button->show();

    dialog->get_vbox()->pack_start(*_button);
*/


/*
    Gtk::Button *_button = new Gtk::Button {"Register",false};
    _button->signal_pressed().connect([this]{Info_box box(entry_first->get_text(),entry_last->get_text(),entry_date->get_text(), entry_password->get_text(), entry_creditCardNo->get_text(),entry_expDate->get_text(),entry_securityId->get_text());Gtk::Main::run(box);});
    _button->show();

    dialog->get_vbox()->pack_start(*_button);
*/
    dialog->close();
    int result = dialog->run(); //running the dialog window

    first_name = entry_first->get_text(); //setting the first and last name of the Person object
    last_name=entry_last->get_text();
    dateOfBirth=entry_date->get_text();
    newPassword=entry_password->get_text();
    creditCardNo=entry_creditCardNo->get_text();
    bool val= check_validity(creditCardNo);
    exprationDate=entry_expDate->get_text();
    securityId=entry_securityId->get_text();
    if(val==false)
    {

        Gtk::MessageDialog dialog3( "Information",false,Gtk::MESSAGE_WARNING);
        dialog3.set_secondary_text("Opps! Not a valid card.");
        dialog3.run();
    }
    else
    {

    }
    //image.set("image1.jpg");
    //dialog->get_vbox()->pack_start(image);

    delete dialog;
    delete label;
    delete label1;
    delete label2;
    delete label3;
    delete label5;
    delete label6;
    delete label7;
    delete entry_first;
    delete entry_last;
    delete entry_date;
    delete entry_password;
    delete entry_creditCardNo;
    delete entry_expDate;
    delete entry_securityId;
}

//We are passing two strings into the constructor of the box (the first and last name)
Info_box::Info_box(std::string first_name, std::string last_name, std::string dateOfBirth,
    std::string newPassword, std::string creditCardNo,
    std::string exprationDate, std::string securityId)
{
    set_title("--Registered Person--");
    set_size_request(200, 300);

    add(vbox);

    label.set_text("First name: "+first_name);
    label.set_padding(10,10);
    vbox.pack_start(label);

    label1.set_text("Last name: "+last_name);
    label1.set_padding(10,10);
    vbox.pack_start(label1);

    label2.set_text("Date of Birth: "+dateOfBirth);
    label2.set_padding(10,10);
    vbox.pack_start(label2);

    label3.set_text("New Password: "+newPassword);
    label3.set_padding(10,10);
    vbox.pack_start(label3);

    label5.set_text("Credit Card Number: "+creditCardNo);
    label5.set_padding(10,10);
    vbox.pack_start(label5);

    label6.set_text("Expiration File: "+exprationDate);
    label6.set_padding(10,10);
    vbox.pack_start(label6);

    label7.set_text("Security ID: "+securityId);
    label7.set_padding(10,10);
    vbox.pack_start(label7);

    register_button.set_label("Confirm");
    register_button.signal_pressed().connect(sigc::mem_fun(*this,&Info_box::register_function));
    vbox.pack_start(register_button);
/*
    image.set("image1.jpg");
     set_size_request(image.get_width()/10, image.get_height()/10);
    vbox.pack_start(image);
*/

    show_all_children();
}

Info_box::~Info_box(){};

void Info_box::register_function()
{
    hide();
}

