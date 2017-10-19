#ifndef NUMBER_H
#define NUMBER_H


#include "term.h"
#include <string>
#include <sstream>

using std::string;

class Variable ;
class Atom ;
class Struct ;

class Number : public Term{
	
public:
	Number(double value){
		stringstream ss;
        ss<<value;
        
        *_value = ss.str();
	}
	string value() const { return *_value; }
    string symbol() const { return *_value; }
	
	bool match(Number &a){ return *_value == a.symbol();}
    bool match(Variable &a) ; 
	bool match(Atom &a);
	bool match(Struct &a);
	
	string *_value = new string[1];

private:

    


};

#endif
