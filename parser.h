#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
		
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
			
			_scanner.nextToken() ;
			if (_scanner.currentChar() == ')' ){
				vector<Term*> terms ;
				return new Struct(*atom,terms);
			}
			
			vector<Term*> terms = getArgs();
			return new Struct(*atom, terms);
		}
        else
          return atom;
    }
	else if(token == LIST){
		_scanner.skipLeadingWhiteSpace();
		
		
		if(_scanner.currentChar() == ']'){
			_scanner.nextToken();
			vector<Term *> args = {};
			return new List(args);
		} else {
			
			if(_currentToken == ')'){
				throw string("unexpected token");
			}
			
			vector<Term*> t = getArgs();
			return new List(t);
			
		}
	}
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term)
      args.push_back(term);
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
