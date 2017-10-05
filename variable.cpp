#include "number.h"
#include "atom.h"
#include "variable.h"

using namespace std;


bool Variable::match(Number a){
	bool ans = false ;
	if ( this->assignable() ) {
		this->assigned( a.value() ) ;
		ans = true ;
	}
	
	else if ( this->value() == a.value() ) {
		ans = true ;
	}
	
	return ans ;
}


bool Variable::match(Atom a){
	bool ans = false ;
	if ( this->assignable() ) {
		this->assigned( a.value() ) ;
		ans = true ;
	}
	
	else if ( this->value() == a.value() ) {
		ans = true ;
	}
	
	return ans ;
}