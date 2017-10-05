#ifndef UTTERM_H
#define UTTERM_H

#include "variable.h"
#include "number.h"
#include "atom.h"

//test Number.value()
TEST (Number, ctor) {
    Number n(25) ;
    ASSERT_EQ("25", n.value());

    std::cout << "1   " << n.value() << std::endl;
}

//test Number.symbol()
TEST (Number, symbol) {
    Number n(25) ;
    ASSERT_EQ("25", n.symbol());

    std::cout << "2   " << n.symbol() << std::endl;
}

//?- 25 = 25.
// true.
TEST (Number, matchSuccess) {
    Number n(25) ;
    Number m(25) ;
    ASSERT_TRUE(n.match(m));

    std::cout << "3   " << std::endl;
}

//?- 25 = 0.
// false.
TEST (Number, matchFailureDiffValue) {
    Number n(25) ;
    Number m(0) ;
    ASSERT_FALSE(n.match(m));

    std::cout << "4   " << std::endl;

}

//?- 25 = tom.
// false.
TEST (Number, matchFailureDiffConstant) {

    Number n(25) ;
    Atom tom("tom") ;

    ASSERT_FALSE(n.match(tom)) ;

    std::cout << "5   " << std::endl;

}

//?- 25 = X.
// true.
TEST (Number, matchSuccessToVar) {
	
	Variable X("X") ;
    Number n(25) ;

    ASSERT_TRUE( n.match(X) ) ;
	
    std::cout << "6   " << std::endl;
}

//?- tom = 25.
// false.
TEST (Atom, matchFailureDiffConstant) {
	
	Number n(25) ;
    Atom tom("tom") ;
	
	ASSERT_FALSE( tom.match(n) ) ;
	
	std::cout << "7   " << std::endl;
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	
	Atom tom("tom") ;
	Variable X("X") ;
	
	EXPECT_TRUE(tom.match(X));
	ASSERT_EQ("tom",X.value());
	
	std::cout << "8   " << std::endl;

}

// ?- X = tom, tom = X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	
	Variable X("X") ;
	Atom tom("tom") ;
	
	EXPECT_TRUE( X.match(tom) );
	EXPECT_TRUE( tom.match(X) );
	
	ASSERT_EQ("tom",X.value());
	
	std::cout << "9   " << std::endl;
}

// ?- X = jerry, tom = X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	
	Variable X("X") ;
	Atom jerry("jerry") ;
	
	EXPECT_TRUE( X.match(jerry) );
	
	Atom tom("tom") ;
	
	ASSERT_FALSE( tom.match(X) );
	
	std::cout << "10   " << std::endl;
	
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
	
	Variable X("X") ;
	Number n(5) ;
	
	EXPECT_TRUE( X.match(n) );
	
	ASSERT_EQ("5",X.value());
	
	std::cout << "11   " << std::endl;
}

// ?- X = 25, X = 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
	
	Variable X("X") ;
	Number n(25) ;
	
	EXPECT_TRUE( X.match(n) );
	
	Number m(100) ;
	
	ASSERT_FALSE( X.match(m) );
	
	std::cout << "12   " << std::endl;
	
}

// ?- X = tom, X = 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
	
	Variable X("X") ;
	Atom tom("tom") ;
	
	EXPECT_TRUE( X.match(tom) );
	
	Number n(25) ;
	
	ASSERT_FALSE( X.match(n) );
	
	std::cout << "13   " << std::endl;
}

//?- tom = X, 25 = X.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
	
	Variable X("X") ;
	Atom tom("tom") ;
	
	EXPECT_TRUE( tom.match(X) );
	
	Number n(25) ;
	
	ASSERT_FALSE( n.match(X) );
	
	std::cout << "14   " << std::endl;
}

//?- X = tom, X = tom.
// true.
TEST(Variable, reAssignTheSameAtom){
	
	Atom tom("tom") ;
	Variable X("X") ;
	
	EXPECT_TRUE( X.match(tom) );
	
	ASSERT_TRUE( X.match(tom) );
	
	std::cout << "15   " << std::endl;
}

#endif
