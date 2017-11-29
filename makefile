all: madRace utAtom utVariable hw6


hw6: mainScanner.o atom.o list.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o hw6 mainScanner.o atom.o list.o -lgtest
else
	g++ -o hw6 mainScanner.o atom.o list.o -lgtest -lpthread
endif

mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ -std=c++11 -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp


mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp


mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h
		g++ -std=c++11 -c mainScanner.cpp
utIterator: mainIterator.o atom.o list.o iterator.h
	g++ -o utIterator mainIterator.o atom.o list.o struct.h -lgtest -lpthread

mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=c++11 -c mainIterator.cpp



clean:
	rm -f *.o madRace utAtom utVariable utScanner
stat:
	wc *.h *.cpp