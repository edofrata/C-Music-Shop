
# variables for the makefile
CXX = g++ -std=c++17
CXXFLAGS =   -c -Wall

#Compiling the file which will run the program
music_shop : music_shop.o methods.o
	$(CXX) music_shop.o methods.o -o music_shop
	

#COmpiling the file which contains the main
music_shop.o : music_shop.cpp music_shop.hpp
	$(CXX) $(CXXFLAGS) music_shop.cpp
	
#Compiling the methods file
methods.o : methods.cpp music_shop.hpp
	$(CXX) $(CXXFLAGS) methods.cpp

# creating a PHONY target as the clean method is
.PHONY: clean
clean :
	rm *.o
	rm music_shop
	rm music_shop_test
