all: hw4
		
hw4: mainList.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainList.o atom.o -lgtest
else
	g++ -o hw4 mainList.o atom.o -lgtest -lpthread
endif
		
mainList.o: mainList.cpp utList.h list.h utAtom.h
	g++ -std=gnu++0x -c mainList.cpp
	
clean:
ifeq (${OS}, Windows_NT)
	rm *.o *.exe
else
	rm -f *.o hw4
endif