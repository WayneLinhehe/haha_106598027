#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"


TEST(iterator, one) {
    
    
    Struct s(Atom("s"), {});
    Iterator<Term*> *itStruct = s.createDFSIterator();
    itStruct->first();
    
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, second) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term*> *itStruct = s.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, three) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
	Struct g(Atom("g"), { &one, &t, &s });
    Iterator<Term*> *itStruct = g.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("s(1, t(X, 2), Y)", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, four) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term*> *itStruct = s.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, five) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
	Struct g(Atom("g"), { &one, &t, &s });
    Iterator<Term*> *itStruct = g.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("s(1, t(X, 2), Y)", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, six) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List l1({&one, &X, &Y});
    List l2({&l1, &two});
    Iterator<Term*> *itStruct = l2.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("[1, X, Y]", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}


TEST(iterator, seven) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List l1({&one, &X, &Y});
    List l2({&two});
	Struct t(Atom("t"), { &l1, &l2 });
	
    Iterator<Term*> *itStruct = t.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("[1, X, Y]", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("[2]", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}


TEST(iterator, eight){
  Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List l1({&one, &X, &Y});
    List l2({&two});
	Struct t(Atom("t"), { &l1, &l2 });
	
    Iterator<Term*> *itStruct = t.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("[1, X, Y]", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("[2]", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
	itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nine){
	
	Number one(1);
	Iterator<Term*> *itStruct = one.createIterator();
	itStruct->first();
	ASSERT_TRUE(itStruct->isDone());
	
}
TEST(iterator, ten){
	
	Atom x("x");
	Iterator<Term*> *itStruct = x.createIterator();
	itStruct->first();
	ASSERT_TRUE(itStruct->isDone());
	
}
TEST(iterator, eleven){
	
	Variable X("X");
	Iterator<Term*> *itStruct = X.createIterator();
	itStruct->first();
	ASSERT_TRUE(itStruct->isDone());
	
}

TEST(iterator, twelve) {
	Atom x("x");
    List l1({&x});
    Iterator<Term*> *itStruct = l1.createDFSIterator();
    itStruct->first();
	ASSERT_EQ("x", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

#endif
