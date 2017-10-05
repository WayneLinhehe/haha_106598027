#include "number.h"
#include "variable.h"
#include "atom.h"

#include <iostream>
using namespace std;



bool Atom::match(Variable &a){
	
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

bool Atom::match(Number a){
	//cout << "--   " << endl;
	return _symbol == a.symbol();
}