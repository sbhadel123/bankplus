
/*
#include "login.h"
#include <gtkmm.h>
#include "signup.h"
int main(int argc, char **argv)
{
    Gtk::Main app(argc, argv);
    Person p;
    Info_box window(p.first_name, p.last_name, p.dateOfBirth, p.newPassword, p.creditCardNo, p.exprationDate, p.securityId);
    Gtk::Main::run(window);
    return 0;
}
*/

#include "login.h"
#include "signup.h"
//#include "main_window3.h"
#include <gtkmm/application.h>
//#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
		
	Gtk:: Main app(argc, argv);
	Login_window w;
	Gtk::Main::run(w);
	return 0;

}

