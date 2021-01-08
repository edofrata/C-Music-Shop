
# variables for the makefile
CXX = g++
CXXFLAGS = -c -Wall


#creating the file which will have the main
music_shop : music_shop.o methods.o
	$(CXX) music_shop.o methods.o -o music_shop
#compiling the file which I will need for compiling the main one
music_shop.o : music_shop.cpp music_shop.hpp
	$(CXX) $(CXXFLAGS) music_shop.cpp
#compiling the second file which I will need for compiling the man one
methods.o : methods.cpp music_shop.hpp
	$(CXX) $(CXXFLAGS) methods.cpp

# creating a PHONY target as the clean method is
.PHONY: clean
clean :
	rm *.o
	rm music_shop
