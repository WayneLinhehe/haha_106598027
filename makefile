all: utAtom utVariable utScanner utList utParser



utAtom: mainAtom.o atom.o
	g++ -o utAtom mainAtom.o atom.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
	g++ -std=c++11 -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp

utVariable: mainVariable.o atom.o
		g++ -o utVariable mainVariable.o atom.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp
		
		
utList: mainList.o atom.o
		g++ -o utList mainList.o atom.o -lgtest -lpthread
mainList.o: mainList.cpp utList.h list.h
		g++ -std=c++11 -c mainList.cpp

#exp: mainExp.o
#	g++ -o exp mainExp.o -lgtest -lpthread
#mainExp.o: mainExp.cpp exp.h global.h
#	g++ -std=c++11 -c mainExp.cpp

utScanner: mainScanner.o scanner.h utScanner.h
	g++ -o utScanner mainScanner.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h
		g++ -std=c++11 -c mainScanner.cpp
		

utParser: mainParser.o parser.h utParser.h
	g++ -o utParser mainParser.o atom.o -lgtest -lpthread
mainParser.o: mainParser.cpp utParser.h parser.h  atom.h struct.h variable.h scanner.h
		g++ -std=c++11 -c mainParser.cpp

#utTerm: mainTerm.o term.o struct.o var.o list.o
#	g++ -o utTerm mainTerm.o term.o var.o struct.o list.o -lgtest -lpthread
#mainTerm.o: mainTerm.cpp utTerm.h term.h var.h utStruct.h struct.h list.h utList.h
#	g++ -std=c++11 -c mainTerm.cpp
#term.o: term.h term.cpp
#	g++ -std=c++11 -c term.cpp
#struct.o: struct.h struct.cpp
#	g++ -std=c++11 -c struct.cpp
#var.o: var.h var.cpp
#g++ -std=c++11 -c var.cpp
#list.o: list.h list.cpp term.h var.h
#	g++ -std=c++11 -c list.cpp
clean:
	rm -f *.o madRace utAtom utVariable utScanner utList utParser
stat:
	wc *.h *.cpp
