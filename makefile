all:  hw3



hw3: mainTerm.o number.o atom.o variable.o
	g++ -o hw3 mainTerm.o number.o atom.o variable.o -lgtest -lpthread
	
mainTerm.o: mainTerm.cpp 
	g++ -std=c++11 -c mainTerm.cpp

number.o: number.cpp number.h term.h
	g++ -std=c++11 -c number.cpp 
	
variable.o: variable.cpp variable.h term.h
	g++ -std=c++11 -c variable.cpp
	
atom.o: atom.cpp atom.h term.h
	g++ -std=c++11 -c atom.cpp
	
	
clean:
	rm -f *.o *.h.gch hw3
stat:
	wc *.h *.cpp