#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include<gtkmm.h>

class main_window : public Gtk::Window
{
public:
  main_window();
  virtual ~main_window();

  //widgets
  Gtk::Image image;
  Gtk::Menu submenu1, submenu2,submenu3,submenu4;
  Gtk::MenuBar menubar;
  Gtk::MenuItem menufiles1,menufiles2,menufiles3,menufiles4,checking_account,saving_account,credit_card,between_ac,ac_at_bpp,ac_at_another,open_account,contact,appointment,locations;
  Gtk::SeparatorMenuItem line;
  Gtk::Box box;
  Gtk::Button sign_out;

};

#endif
