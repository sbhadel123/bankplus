CXXFLAGS += -std=c++11
GTKFLAGS =`/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex:  login.o signup.o prac.o main.o main_window3.o
	$(CXX) $(CXXFLAGS) -o signup login.o signup.o prac.o main.o main_window3.o $(GTKFLAGS)
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
signup.o: signup.h signup.cpp
	$(CXX) $(CXXFLAGS) -c signup.cpp $(GTKFLAGS)
login.o: login.h login.cpp
	$(CXX) $(CXXFLAGS) -c login.cpp	$(GTKFLAGS)
prac.o: signup.h prac.cpp
	$(CXX) $(CXXFLAGS) -c prac.cpp $(GTKFLAGS)
main_window3.o: main_window3.h main_window3.cpp
	$(CXX) $(CXXFLAGS) -c main_window3.cpp $(GTKFLAGS)
	
