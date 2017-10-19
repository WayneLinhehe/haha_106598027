#ifndef UTVARIABLE_H
#define UTVARIABLE_H

#include "variable.h"
#include "struct.h"
#include "atom.h"
#include "number.h"

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X.symbol());
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}

TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
	Variable X("X") ;
	Number n(2.7182) ;
	ASSERT_TRUE(X.match(n)) ;
	ASSERT_EQ( "2.7182", X.value());
	
	std::cout << "1   " << std::endl;
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
	
	Variable X("X") ;
	Variable Y("Y") ;
	
	Number n(1) ;
	
	EXPECT_TRUE(X.match(Y));
	EXPECT_TRUE(X.match(n));
	ASSERT_EQ( "1", Y.value() ) ;
	
	std::cout << "2   " << std::endl;
}
  
// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
	
	Variable X("X") ;
	Variable Y("Y") ;
	
	Number n(1) ;
	
	EXPECT_TRUE(X.match(Y));
	EXPECT_TRUE(Y.match(n));
	ASSERT_EQ( "1", X.value() ) ;
	
	std::cout << "3   " << std::endl;
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
	
	Variable X("X") ;
	
	Number n(1) ;
	
	EXPECT_TRUE(X.match(X));
	EXPECT_TRUE(X.match(n));
	ASSERT_EQ( "1", X.value() ) ;
	
	std::cout << "4   " << std::endl;
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
	
	Variable X("X") ;
	Variable Y("Y") ;
	Number n(1) ;
	
	EXPECT_TRUE(Y.match(n));
	EXPECT_TRUE(X.match(Y));
	ASSERT_EQ( "1", X.value() ) ;
	
	std::cout << "5   " << std::endl;
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
	Variable X("X") ;
	Variable Y("Y") ;
	Variable Z("Z") ;
	Number n(1) ;
	
	EXPECT_TRUE(X.match(Y));
	EXPECT_TRUE(Y.match(Z));
	EXPECT_TRUE(Z.match(n));
	ASSERT_EQ( "1", X.value() ) ;
	ASSERT_EQ( "1", Y.value() ) ;
	ASSERT_EQ( "1", Z.value() ) ;
	
	std::cout << "6   " << std::endl;
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
	Variable X("X") ;
	Variable Y("Y") ;
	Variable Z("Z") ;
	Number n(1) ;
	
	EXPECT_TRUE(X.match(Y));
	EXPECT_TRUE(X.match(Z));
	EXPECT_TRUE(Z.match(n));
	ASSERT_EQ( "1", X.value() ) ;
	ASSERT_EQ( "1", Y.value() ) ;
	ASSERT_EQ( "1", Z.value() ) ;
	
	std::cout << "7   " << std::endl;
}

// s(X)
// Y=s(X)
// Y.symbol()="Y"
// Y.value()="s(X)"

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {  //FAIL
	
	
	Variable X("X") ;
	Variable Y("Y") ;
	
	std::vector<Term *> v = {&X};
	Struct s(Atom("s"), v) ;
	
	EXPECT_TRUE(Y.match(s));
	ASSERT_EQ( "Y", Y.symbol() ) ;
	ASSERT_EQ( "s(X)", Y.value() ) ;
	
	std::cout << "8   " << std::endl;
	
}

// s(X)
// Y=s(X)
// X=teddy
// Y.symbol()="Y"
// Y.value()="s(teddy)"

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {  //FAIL
	
	
	Variable X("X") ;
	Variable Y("Y") ;
	Atom teddy("teddy") ;
	
	std::vector<Term *> v = {&X};
	Struct s(Atom("s"), v) ;
	
	EXPECT_TRUE(Y.match(s));
	EXPECT_TRUE(X.match(teddy));
	
	std::cout << "===" << X.value() << std::endl;
	
	ASSERT_EQ( "Y", Y.symbol() ) ;
	ASSERT_EQ( "s(teddy)", Y.value() ) ;
	
	std::cout << "9   " << std::endl;
	
	
}

#endif



