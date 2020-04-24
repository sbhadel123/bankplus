#include "login.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]){

	Gtk:: Main app(argc, argv);

	Login_window w;

	Gtk::Main::run(w);
	return 0;

}

