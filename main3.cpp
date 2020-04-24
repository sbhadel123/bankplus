#include "main_window3.h"
#include <gtkmm/application.h>

int	main(int argc, char*argv[])
{
	Gtk::Main app(argc, argv);
	main_window window;
	Gtk::Main::run(window);
	return	0;

}
