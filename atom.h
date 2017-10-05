#ifndef ATOM_H
#define ATOM_H


#endif
#include <string> 
using namespace std;

class Number ;
class Variable ;

class Atom {
public:
    Atom (string s) {
		_symbol = s ;
		_value = s ;
	}

    string value(){ return _value; }
    string symbol(){ return _symbol; }
	
	bool match(Atom a) {return _symbol == a.symbol();}
	bool match(Number a ) ;
	bool match(Variable &a ) ;
	
private:
    string _symbol;
    string _value;


};
