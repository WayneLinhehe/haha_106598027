#ifndef VARIABLE_H
#define VARIABLE_H



#endif

#include <string> 
using namespace std;

class Number ;
class Atom ;

class Variable{
public:
	Variable(string s):_symbol(s){}
	
	string value(){ return _value; }
	string symbol(){ return _symbol; }
	bool assignable(){ return _assignable; }
  
	bool match( Variable a ) {return _symbol == a.symbol();}
	bool match( Atom a ) ;
	bool match( Number a ) ;
	
	void assigned( string a ) {
		_value = a ;
		_assignable = false ;
	}
  
/*
  bool match( Atom atom ){
      bool ret = _assignable;
      if(_assignable){
          _value = atom.symbol() ;
          _assignable = false;
      }
      else if ( _value == atom.symbol() ) {
          ret = true ;
      }
      return ret;
  }
*/

/*
    bool match( Number a ){
        bool ret = _assignable;
        if(_assignable){
            _value = a.symbol() ;
            _assignable = false;
        }
        else if ( _value == a.symbol() ) {
            ret = true ;
        }
        return ret;
    }
*/
private:
    string _value;
    bool _assignable = true;
    string  _symbol;
};
