#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <string> 
using namespace std;

class Number ;
class Atom ;
class Struct ;

class Variable : public Term {
public:
	Variable(string s):_symbol(s){
		*_value = s ;
	}
	
	string value() const { return *_value; }
	string symbol() const { return _symbol; }
	bool assignable(){ return _assignable; }
  
	bool match( Variable &a ) ;
	bool match( Atom &a ) ;
	bool match( Number &a ) ;
	bool match( Struct &a ) ;
	
	/*
	void assigned( string a ) {
		_value = (a) ;
		_assignable = false ;
	}
	*/
	
	string *_value = new string[1];
    bool _assignable = true;
    string _symbol;
	
	
	
private:
    
};

#endif
