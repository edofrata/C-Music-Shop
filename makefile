
# variables for the makefile
$(CXX) = g++
$(CXXFLAGS) = -g -Wall

#creating the file which will have the main
music_shop : music_shop.cpp music_shop.o methods.o
	$(CXX) $(CXXFLAGS) -o music_shop music_shop.cpp music_shop.o methods.o
#compiling the file which I will need for compiling the main one
music_shop.o : music_shop.cpp class.h
	$(CXX) $(CXXFLAGS) music_shop.cpp
#compiling the second file which I will need for compiling the man one
methods.o : methods.cpp class.h
	$(CXX) $(CXXFLAGS) methods.cpp

# creating a PHONY target as the clean method is
.PHONY: clean 
clean :
	rm *.o
