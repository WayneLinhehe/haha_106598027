#ifndef ATOM_H
#define ATOM_H


#include "term.h"
#include <string>

using std::string;

class Atom : public Term{
public:
  Atom (string s) {
	  *_symbol = (s) ;
	  
  }

  string symbol() const{
    return *_symbol ;
  }
  
  string value() const{
    return *_symbol ;
  };
  
  
	bool match(Atom &a) {return *_symbol == a.symbol();}
	bool match(Number &a ) ;
	bool match(Variable &a ) ;

	string* _symbol = new string [1];
    
  private:
    
};


#endif
