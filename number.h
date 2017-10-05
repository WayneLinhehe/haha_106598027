#ifndef NUMBER_H
#define NUMBER_H


#endif
#include <string> 
#include <sstream>
using namespace std;

class Variable ;
class Atom ;


class Number {
public:
    Number (int s) {

        stringstream ss;
        ss<<s;
        _symbol = ss.str();
        _value = ss.str();

    }

    string value(){ return _value; }
    string symbol(){ return _symbol; }


	bool match(Number a){ return _symbol == a.symbol();}
    bool match(Variable &a) ; 
	bool match(Atom a);
	

private:

    string _symbol;
    string _value;


};
