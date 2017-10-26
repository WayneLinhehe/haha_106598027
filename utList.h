#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
	
	
	vector<Term *> args = {};
	List l(args);
	
	EXPECT_EQ("[]", l.symbol());
	
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
	
	Number n1(496) ;
	Number n2(8128) ;
	vector<Term *> args = {&n1 , &n2};
	List l(args);
	
	EXPECT_EQ("[496, 8128]", l.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
	Atom terence_tao("terence_tao") ;
	Atom alan_mathison_turing("alan_mathison_turing") ;
	
	vector<Term *> args = {&terence_tao , &alan_mathison_turing};
	List l(args);
	
	EXPECT_EQ("[terence_tao, alan_mathison_turing]", l.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
	Variable X("X") ;
	Variable Y("Y") ;
	
	vector<Term *> args = {&X , &Y};
	List l(args);
	
	EXPECT_EQ("[X, Y]", l.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	Atom tom("tom") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	EXPECT_FALSE(tom.match(l)) ;
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	Number n2(8128) ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	EXPECT_FALSE(n2.match(l)) ;
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	
	std::vector<Term *> v = {&X};
	Struct s(Atom("s"), v);
	
	
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	EXPECT_FALSE(s.match(l)) ;
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	Variable Y("Y") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	Y.match(l) ;
	
	EXPECT_EQ("[496, X, terence_tao]", Y.value());
}

// ?- X = [496, X, terence_tao].
// false. (no score)
TEST(List, matchToVarOccuredInListShouldFail) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	EXPECT_TRUE(X.match(l)) ;
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	List l2(args);
	
	EXPECT_TRUE(l.match(l2)) ;
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
	
	Number n1(496) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	Variable Y("Y") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	vector<Term *> args2 = {&n1 , &Y , &terence_tao};
	List l2(args2);
	
	EXPECT_TRUE(l.match(l2)) ;
	
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
	
	Number n1(496) ;
	Number n2(8128) ;
	Variable X("X") ;
	Atom terence_tao("terence_tao") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	vector<Term *> args2 = {&n1 , &n2 , &terence_tao};
	List l2(args2);
	
	l.match(l2) ;
	
	EXPECT_EQ("8128" , X.value()) ;
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
	
	Number n1(496) ;
	Variable X("X") ;
	Variable Y("Y") ;
	Atom terence_tao("terence_tao") ;
	Atom alan_mathison_turing("alan_mathison_turing") ;
	
	vector<Term *> args = {&n1 , &X , &terence_tao};
	List l(args);
	
	Y.match(l) ;
	X.match(alan_mathison_turing) ;
	
	EXPECT_EQ("[496, alan_mathison_turing, terence_tao]" , Y.value()) ;
	EXPECT_EQ("alan_mathison_turing" , X.value()) ;
}

// Example: 
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
	
	
	Atom f("first"), s("second"), t("third");
	vector<Term *> args = {&f, &s, &t};
	List l(args);

	EXPECT_EQ(string("first"), l.head()->symbol());
	EXPECT_EQ(string("[second, third]"), l.tail()->value());
  
  
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
	

  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
  
  
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
	
	Atom f("first"), s("second"), t("third");
	vector<Term *> args = {&f};
	List l(args) ;
	vector<Term *> args2 = {&l , &s , &t};
	List l2(args2) ;
	
	EXPECT_EQ(string("[first]"), l2.head()->value());
	EXPECT_EQ(string("[second, third]"), l2.tail()->value());
	
	

}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
	Atom f("first"), s("second"), t("third");
	vector<Term *> args = {&f, &s, &t};
	List l(args);

	EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
	EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());
}
 
// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
	vector<Term *> args = {};
	List l(args);
	try{
		l.head();
	}
		catch( const string err){
		ASSERT_EQ("Accessing head in an empty list",err);
	}
	
}

// Given there is a empty list
// When client still want to get the tail of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
	vector<Term *> args = {};
	List l(args);
	try{
		l.head();
	}
		catch( const string err){
		ASSERT_EQ("Accessing head in an empty list",err);
	}
}




#endif
