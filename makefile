all: hw6

hw6: mainParser.o atom.o
  ifeq (${OS}, Windows_NT)
  	g++ -o hw6 mainParser.o atom.o -lgtest
  else
    g++ -o hw5 mainParser.o atom.o -lgtest -lpthread
  endif

mainParser.o: mainParser.cpp utParser.h parser.h  atom.h struct.h variable.h scanner.h
  g++ -std=gnu++0x -c mainParser.cpp

mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h
  g++ -std=gnu++0x -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
  g++ -std=gnu++0x -c atom.cpp

mainVariable.o: mainVariable.cpp utVariable.h variable.h
  g++ -std=gnu++0x -c mainVariable.cpp
  
mainList.o: mainList.cpp utList.h list.h
  g++ -std=gnu++0x -c mainList.cpp
  
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h
  g++ -std=gnu++0x -c mainScanner.cpp
  

clean:
ifeq (${OS}, Windows_NT)
  rm *.o *.exe
else
  rm -f *.o hw5
endif