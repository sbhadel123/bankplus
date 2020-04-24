#ifndef LOGIN_P
#define LOGIN_P

#include <gtkmm.h>
#include "signup.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "main_window3.h"

using namespace std;


class Login_window: public Gtk::Window{

	public:
					string fname;
					string line_from_line;
					vector<PersonInfo> Customer_Information;
					ifstream inFile;
					Login_window();
					virtual ~Login_window();
					void verify_Account();
					
	//widgets
	Gtk::Image image;
	Gtk::Box box;
	Gtk:: Entry entry1;
	Gtk:: Label e1;
	Gtk:: Label e2;
	Gtk::Button send;
	Gtk::Button signin;
	Gtk::CheckButton checkbutton;
	Gtk::Label label1;
	Gtk::Label label2;
	Gtk::Box v1;
	Gtk::Box v2;
	Gtk::Entry entry2;
	
	};

#endif
