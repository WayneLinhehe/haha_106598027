#include "number.h"
#include "atom.h"
#include "variable.h"
#include "struct.h"
#include <iostream>

using namespace std;



bool Variable::match(Number &a){
	bool ans = false ;
	if ( this->assignable() ) {
		*_value = a.value();
        a._value = this->_value ;
		this->_assignable = false ;
		
		ans = true ;
	}
	
	else if ( this->value() == a.value() ) {
		ans = true ;
	}
	
	return ans ;
}

bool Variable::match(Atom &a){
	
	bool ans = false ;
	if ( this->assignable() ) {
		
		//std::cout << " ............" << a.symbol() << " ..........." << std::endl;
		
		*_value = a.symbol();
        a._symbol = this->_value;
		this->_assignable = false ;
		
		ans = true ;
	}
	
	else if ( this->value() == a.value() ) {
		ans = true ;
	}
	
	return ans ;
}


bool Variable::match(Variable &a){
	bool ans = false ;
	if ( this->assignable() && a.assignable() == false ) {
		this->_value = a._value;
		this->_assignable = false ;
		ans = true ;
	}
	else if ( this->assignable() == false && a.assignable() ) {
		a._value = this->_value;
		a._assignable = false ;
		ans = true ;
	}
	else if ( this->assignable() && a.assignable() ) {
		a._value = this->_value ;
		ans = true ;
	}
	else if ( this->assignable() == false && a.assignable() == false ) {
		if (this->value() == a.value()){
			ans = true ;
		}
	}
	
	
	return ans ;
}

bool Variable::match(Struct &a){
	/*
	bool ans = false ;
	if ( this->assignable() ) {
		
		this->_value = a._value;
		this->_assignable = false ;
		ans = true ;
		
	}
	else if ( this->assignable() == false ) {
		
		
		
		ans = true ;
		
	}
	
	
	return ans ;
	*/
	
}












