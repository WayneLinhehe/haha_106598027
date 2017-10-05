#include "number.h"
#include "variable.h"
#include "atom.h"

#include <iostream>
using namespace std;


bool Number::match(Variable &a){
	
	bool ans = false ;
	if ( a.assignable() ) {
		a.assigned( this->value() ) ;
		ans = true ;
	}
	
	else if ( a.value() == this->value() ) {
		ans = true ;
	}
	
	return ans ;
	
	
}

bool Number::match(Atom a){
	//cout << "--   " << endl;
	return _symbol == a.symbol();
}