#include "login.h"
#include "signup.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "main_window3.h"

using namespace std;

Login_window::Login_window(): box(Gtk::ORIENTATION_VERTICAL){
			
			inFile.open("customer.txt");

    while(!inFile.eof())
    {
        PersonInfo P;
        getline(inFile,line_from_line);
        P.File_Read(line_from_line);
        Customer_Information.push_back(P);
    }
			//this->fname=Customer_Information[0].first_name;
			
			set_size_request(400,300);
			set_title("--BANK++--");

			add(box);

			e2.set_text("");
			v2.pack_start(e2);
			image.set("bank1.jpg");
			image.set_pixel_size(5);

			v2.pack_start(image);

			box.pack_start(v2);

			label1.set_text("Enter your username: ");
			box.pack_start(label1);

			entry1.set_max_length(50);
			entry1.set_text("USERNAME");
			entry1.select_region(0,entry1.get_text_length());
			box.pack_start(entry1);


			label2.set_text("Enter your password: ");
			box.pack_start(label2);

			entry2.set_max_length(50);
			entry2.set_text("PASSWORD");
			entry2.select_region(0,entry2.get_text_length());
			box.pack_start(entry2);

			send.add_label("log in");
			send.signal_pressed().connect(sigc::mem_fun(*this, &Login_window::verify_Account));
			v1.pack_start(send);

			signin.add_label("sign up");
			signin.signal_pressed().connect([]
                                 {
                                    Person p;
                                   });
			v1.pack_start(signin);

			e1.set_text("");
			box.pack_start(e1);
			box.pack_start(v1);

			show_all_children();
			
		}

        void Login_window::verify_Account()
        {
           for(int i=0; i<Customer_Information.size(); i++)
            {
                if(entry1.get_text()==Customer_Information[i].first_name)
                {
					
					main_window mw;
					Gtk::Main::run(mw);
                    /*Gtk::MessageDialog dialog3( "Information",false,Gtk::MESSAGE_WARNING);
                    dialog3.set_secondary_text("Valid Account.");
                    dialog3.run();*/
					hide();
					//new_window();
                }
           }

        }
		
		
		Login_window::~Login_window(){
		}
