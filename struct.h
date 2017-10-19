#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Struct:public Term
{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name), _args(args) {
  }

  Term * args(int index) {
    return _args[index];
  }

  Atom const & name() {
    return _name;
  }
  
  
  string value() const{
    *_value =_name.value() + "(";
	
	//std::cout << " *************" << &_args[0] << "***********" <<std::endl;
	
    for(int i = 0; i < _args.size() - 1 ; i++){
      *_value += _args[i]-> value() + ", ";
    }
    *_value += _args[_args.size()-1]-> value() + ")";
    return  *_value;
  }
  
  
  
  string symbol() const{
    string ret =_name.symbol() + "(";
	
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }
  
  
  
  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++){
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }
  
  string *_value = new string[1];
  
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
