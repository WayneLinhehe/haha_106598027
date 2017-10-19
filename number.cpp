#include "number.h"
#include "variable.h"
#include "atom.h"

#include <iostream>

using namespace std;


bool Number::match(Variable &a){
	
	bool ans = false ;
	if ( a.assignable() ) {
		*(a._value) = this->value() ;
		a._assignable = false ;
		
		ans = true ;
	}
	
	else if ( *(a._value) == this->value() ) {
		ans = true ;
	}
	
	return ans ;
	
	
}

bool Number::match(Atom &a){
	//cout << "--   " << endl;
	return *_value == a.symbol();
}