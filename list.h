#ifndef LIST_H
#define LIST_H

#include "atom.h"

#include <vector>

#include <string>

using std::string;
using std::vector;

class List : public Term {
public:
  string symbol() const {
	
	string ret =  "[";
	if (!_elements.empty()){
		std::vector<Term *>::const_iterator it = _elements.begin();
		for (; it != _elements.end()-1; ++it)
		  ret += (*it)->symbol()+", ";
		ret  += (*it)->symbol()+"]";
	}
	else{
		ret  += "]";
	}
    return ret;
  }
  string value() const {
    string ret = "[";
	if (!_elements.empty()){
    std::vector<Term *>::const_iterator it = _elements.begin();
    for (; it != _elements.end()-1; ++it)
      ret += (*it)->value()+", ";
    ret  += (*it)->value()+"]";
	}
	else{
		ret  += "]";
	}
    return ret;
  }
  bool 	match(Term & term) {
	
	List * ps = dynamic_cast<List *>(&term);
	
	if (ps){
      if(_elements.size()!= ps->_elements.size())
        return false;
      for(int i=0;i<_elements.size();i++){
        //if(_elements[i]->symbol() != ps->_elements[i]->symbol())
        //    return false;
		if ( !_elements[i]->match(*ps->_elements[i]) ){
			return false;
		}
      }
      return true;
    }
    return false;
	
	
  }
  

public:

  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  
  Term * head() const {
	  if (_elements.empty()){
		throw string("Accessing head in an empty list");
	  }
	  else{
		return _elements[0] ;
	  }
  }
  List * tail() const {
	  
	  if (_elements.empty()){
		  throw string("Accessing tail in an empty list");
	  }
	  else{
		  vector<Term *> v ;
		  for(int i=1;i<_elements.size();i++){
			v.push_back(_elements[i]) ;
		  }
		  List *l = new List(v);
		  
		  return l ;
	  }
  }

  
  
  
  
  
  
  
  
private:
  vector<Term *> _elements;

};

#endif
