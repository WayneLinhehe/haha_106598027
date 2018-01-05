all: shell hw8


shell: shell.o atom.o list.o struct.o scanner.h parser.h exception.h
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o atom.o list.o struct.o -lgtest
else
	g++ -o shell shell.o atom.o list.o struct.o -lgtest -lpthread
endif

hw8: mainExp.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainExp.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 mainExp.o atom.o list.o struct.o -lgtest -lpthread
endif


mainAtom.o: mainAtom.cpp utList.h utAtom.h atom.h utStruct.h struct.h
	g++ -std=gnu++0x -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
	
shell.o: shell.cpp scanner.h  atom.h struct.h variable.h parser.h
	g++ -std=gnu++0x -c shell.cpp

mainVariable.o: mainVariable.cpp utVariable.h variable.h
	g++ -std=gnu++0x -c mainVariable.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp

mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h utExp.h
	g++ -std=gnu++0x -c mainScanner.cpp
		
mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=gnu++0x -c mainIterator.cpp


clean:
	rm -f *.o utScanner hw8
stat:
	wc *.h *.cpp
