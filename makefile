all:  hw3
 
hw3: mainTerm.o number.o atom.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o number.o atom.o variable.o -lgtest
else
	g++ -o hw3 mainTerm.o number.o atom.o variable.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utVariable.h utStruct.h
	g++ -std=gnu++0x -c mainTerm.cpp
  
number.o: number.cpp number.h
	g++ -std=gnu++0x -c number.cpp 

variable.o: variable.cpp variable.h
	g++ -std=gnu++0x -c variable.cpp
	
atom.o: atom.cpp atom.h
	g++ -std=gnu++0x -c atom.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif