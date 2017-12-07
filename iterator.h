#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class NullIterator :public Iterator<Term*>{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};


class StructIterator :public Iterator<Term*> {
public:
  friend class Struct;
  friend class List;
  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
private:
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};







class StructIterator1 :public Iterator<Term*> {  // I DO  //把方法寫到建構子裡面
public:
  friend class Struct;
  friend class List;
  void first() {
    _index = 0;
  }
  
  void add_q_q1 (Term *term) {
	  
	//std::cout << term->symbol() << std::endl ;
	
	//q_q.push_back(term) ;
	
	if (Struct * s = dynamic_cast<Struct*> (term) ){
		
		for (int i = 0 ; i < s->arity() ; i++) {
			
			add_q_q2(s->args(i)) ;
		}
	}
	if (List * s = dynamic_cast<List*> (term) ){
		
		for (int i = 0 ; i < s->arity() ; i++) {
			
			add_q_q2(s->args(i)) ;
		}
	}
  }
  
  void add_q_q2 (Term *term) {
	//std::cout << term->symbol() << std::endl ;
	q_q.push_back(term) ;
	
	if (Struct * s = dynamic_cast<Struct*> (term)){
		add_q_q1(s) ;
	}
	if (List * s = dynamic_cast<List*> (term)){
		add_q_q1(s) ;
	}
	
  }
  

  Term* currentItem() const {
    return q_q[_index];
  }

  bool isDone() const {
    return _index >= q_q.size();
  }

  void next() {
    _index++;
  }
private:
  StructIterator1(Term *s): _index(0), _s(s) {
	  //std::cout << "00000" << std::endl ;
	  
	  //std::cout << _s->symbol() << std::endl ;
	  
	  add_q_q1(_s) ;
	  /*
	  for (int j = 0 ; j < q_q.size() ; j++) {
		std::cout << q_q[j]->symbol() << "   123" << std::endl ;
	  }
	  */
  }
  int _index;
  Term* _s;
  std::vector<Term *> q_q;
};



class StructIterator2 :public Iterator<Term*> {  // I DO  //把方法寫到建構子裡面
public:
  friend class Struct;
  friend class List;
  void first() {
    _index = 0;
  }
  
  void add_q_q1 (Term *term) {
	  
	//std::cout << term->symbol() << std::endl ;
	
	//q_q.push_back(term) ;
	
	if (Struct * s = dynamic_cast<Struct*> (term) ){
		
		int oo = 0 ;
		for (int i = 0 ; i < s->arity() ; i++) {
			q_q.push_back(s->args(i)) ;
		}
		while ( oo < q_q.size() ){
			if ( Struct * ss = dynamic_cast<Struct*> (q_q[oo])  ) {
					
				for (int i = 0 ; i < ss->arity() ; i++) {
					q_q.push_back(ss->args(i)) ;
				}
			}
			if ( List * ss = dynamic_cast<List*> (q_q[oo])  ) {
					
				for (int i = 0 ; i < ss->arity() ; i++) {
					q_q.push_back(ss->args(i)) ;
				}
			}
			oo++ ;
		}
	}
	if (List * s = dynamic_cast<List*> (term) ){
		
		int oo = 0 ;
		for (int i = 0 ; i < s->arity() ; i++) {
			q_q.push_back(s->args(i)) ;
		}
		while ( oo < q_q.size() ){
			if ( Struct * ss = dynamic_cast<Struct*> (q_q[oo])  ) {
					
				for (int i = 0 ; i < ss->arity() ; i++) {
					q_q.push_back(ss->args(i)) ;
				}
			}
			if ( List * ss = dynamic_cast<List*> (q_q[oo])  ) {
					
				for (int i = 0 ; i < ss->arity() ; i++) {
					q_q.push_back(ss->args(i)) ;
				}
			}
			oo++ ;
		}
	}
  }
  

  Term* currentItem() const {
    return q_q[_index];
  }

  bool isDone() const {
    return _index >= q_q.size();
  }

  void next() {
    _index++;
  }
private:
  StructIterator2(Term *s): _index(0), _s(s) {
	  //std::cout << "00000" << std::endl ;
	  
	  //std::cout << _s->symbol() << std::endl ;
	  
	  add_q_q1(_s) ;
	  /*
	  for (int j = 0 ; j < q_q.size() ; j++) {
		std::cout << q_q[j]->symbol() << "   123" << std::endl ;
	  }
	  */
  }
  int _index;
  Term* _s;
  std::vector<Term *> q_q;
  
};

















class ListIterator :public Iterator<Term*> {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};
#endif
