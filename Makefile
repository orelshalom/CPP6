CXX=clang++-5.0
CXXFLAGS=-std=c++17 -Wall -Werror -Wvla 
 
all: Board.o Character.o Insert.o IllegalCharException.o IllegalCoordinateException.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Character.o: Character.cpp Character.h
	$(CXX) $(CXXFLAGS) -c Character.cpp -o Character.o

Insert.o: Insert.cpp Insert.h
	$(CXX) $(CXXFLAGS) -c Insert.cpp -o Insert.o

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o			

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o

clean:
	rm *.o 