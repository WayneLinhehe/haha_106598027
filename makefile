all: hw7

hw7: mainIterator.o atom.o list.o struct.o iterator.h utIterator.h
ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainIterator.o atom.o list.o struct.o -lgtest
else
	g++ -o hw7 mainIterator.o atom.o list.o struct.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp

list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h
	g++ -std=gnu++0x -c mainScanner.cpp

mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=gnu++0x -c mainIterator.cpp


clean:
	rm -f *.o madRace utAtom utVariable utScanner hw7
stat:
	wc *.h *.cpp
