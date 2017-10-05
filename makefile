all:  hw2



hw2: mainTerm.o number.o atom.o variable.o
	g++ -o hw2 mainTerm.o number.o atom.o variable.o -lgtest -lpthread
	
mainTerm.o: mainTerm.cpp
	g++ -std=c++11 -c mainTerm.cpp

number.o: number.cpp number.h
	g++ -std=c++11 -c number.cpp 
	
variable.o: variable.cpp variable.h
	g++ -std=c++11 -c variable.cpp
	
atom.o: atom.cpp atom.h
	g++ -std=c++11 -c atom.cpp
	
	
clean:
	
	ifeq (${OS}, Windows_NT)
		del *.o *.exe
	else
		rm -f *.o *.h.gch hw2
	endif
	
	
	
	
stat:
	wc *.h *.cpp
