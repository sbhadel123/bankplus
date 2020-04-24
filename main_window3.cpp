#include "main_window3.h"
#include <iostream>

main_window::main_window():box(Gtk::ORIENTATION_VERTICAL),sign_out("Sign Out")
{
  set_size_request(300,200);
  set_title("$$$$ BANK++ $$$$");

  add(box);

  box.pack_start(menubar);

  //Top Menu bar
  menufiles1.set_label("Accounts");
  menubar.append(menufiles1);

  menufiles2.set_label("Transfer");
  menubar.append(menufiles2);

  menufiles3.set_label("Open Account");
  menubar.append(menufiles3);

  menufiles4.set_label("Help & Support");
  menubar.append(menufiles4);

 //sub-menu for Accounts
  menufiles1.set_submenu(submenu1);
  checking_account.set_label("Checking Account");
  submenu1.append(checking_account);

  saving_account.set_label("Saving Account");
  submenu1.append(saving_account);

  credit_card.set_label("Credit Card");
  submenu1.append(credit_card);

  //sub-menu for Transfer
  menufiles2.set_submenu(submenu2);
  between_ac.set_label("Between Your Acocunts");
  submenu2.append(between_ac);

  ac_at_bpp.set_label("Account at Bank ++");
  submenu2.append(ac_at_bpp);

  ac_at_another.set_label("Account at Another Bank");
  submenu2.append(ac_at_another);

  //sub-menu for Open Account
  menufiles3.set_submenu(submenu3);
  open_account.set_label("Open new Account");
  submenu3.append(open_account);

  //sub-menu for Help & Support
  menufiles4.set_submenu(submenu4);
  contact.set_label("Contact Us");
  submenu4.append(contact);

  appointment.set_label("Schedule an appointment");
  submenu4.append(appointment);

  locations.set_label("Locations");
  submenu4.append(locations);

  //sign_out Button
  box.pack_start(sign_out);

  show_all_children();

}
main_window::~main_window()
{
}
