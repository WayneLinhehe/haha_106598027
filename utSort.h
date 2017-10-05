#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

using namespace std;

const double epsilon = 0.000001;

TEST (Sort, sortByIncreasingPerimeter) {


    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Rectangle rect2(3, 8, 12, 22);
    Rectangle rect3(3, 8, 12, 23);
    Triangle tri({1, 1}, {3, 1}, {6, 6});
    Triangle tri2({1, 1}, {6, 1}, {1, 5});

    std::list<Shape *> shapes;

    shapes.push_back(&cir);
    shapes.push_back(&rect);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);
    shapes.push_back(&tri);
    shapes.push_back(&tri2);




    Sort sort1 ;
    sort1.sortByIncreasingPerimeter(&shapes) ;
/*
    std::cout << "------------------" << std::endl;

    for ( std::list<Shape *>::iterator y = shapes.begin() ; y != shapes.end() ; y++ ) {
        std::cout << (*y)->perimeter() << std::endl;
    }
    */
    std::list<Shape *>::iterator ans = shapes.begin() ;

    std::cout << (*ans)->perimeter() << std::endl ;

    ASSERT_NEAR(14.9020197067107762, (*ans)->perimeter(), epsilon);


}










TEST (Sort, sortByDecreasingPerimeter) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Rectangle rect2(3, 8, 12, 22);
    Rectangle rect3(3, 8, 12, 23);
    Triangle tri({1, 1}, {3, 1}, {6, 6});
    Triangle tri2({1, 1}, {6, 1}, {1, 5});

    std::list<Shape *> shapes;

    shapes.push_back(&cir);
    shapes.push_back(&rect);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);
    shapes.push_back(&tri);
    shapes.push_back(&tri2);




    Sort sort1 ;
    sort1.sortByDecreasingPerimeter(&shapes) ;
/*
    std::cout << "------------------" << std::endl;

    for ( std::list<Shape *>::iterator y = shapes.begin() ; y != shapes.end() ; y++ ) {
        std::cout << (*y)->perimeter() << std::endl;
    }
    */
    std::list<Shape *>::iterator ans = shapes.begin() ;

std::cout << (*ans)->perimeter() << std::endl ;

    ASSERT_NEAR(70, (*ans)->perimeter(), epsilon);
}











TEST (Sort, sortByIncreasingArea) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Rectangle rect2(3, 8, 12, 22);
    Rectangle rect3(3, 8, 12, 23);
    Triangle tri({1, 1}, {3, 1}, {6, 6});
    Triangle tri2({1, 1}, {6, 1}, {1, 5});

    std::list<Shape *> shapes;

    shapes.push_back(&cir);
    shapes.push_back(&rect);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);
    shapes.push_back(&tri);
    shapes.push_back(&tri2);




    Sort sort1 ;
    sort1.sortByIncreasingArea(&shapes) ;
/*
    std::cout << "------------------" << std::endl;

    for ( std::list<Shape *>::iterator y = shapes.begin() ; y != shapes.end() ; y++ ) {
        std::cout << (*y)->perimeter() << std::endl;
    }
*/
    std::list<Shape *>::iterator ans = shapes.begin() ;

    std::cout << (*ans)->area() << std::endl ;

    ASSERT_NEAR(5, (*ans)->area(), epsilon);

}

TEST (Sort, sortByDecreasingArea) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Rectangle rect2(3, 8, 12, 22);
    Rectangle rect3(3, 8, 12, 23);
    Triangle tri({1, 1}, {3, 1}, {6, 6});
    Triangle tri2({1, 1}, {6, 1}, {1, 5});

    std::list<Shape *> shapes;

    shapes.push_back(&cir);
    shapes.push_back(&rect);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);
    shapes.push_back(&tri);
    shapes.push_back(&tri2);




    Sort sort1 ;
    sort1.sortByDecreasingArea(&shapes) ;
    /*
        std::cout << "------------------" << std::endl;

        for ( std::list<Shape *>::iterator y = shapes.begin() ; y != shapes.end() ; y++ ) {
            std::cout << (*y)->perimeter() << std::endl;
        }
    */
    std::list<Shape *>::iterator ans = shapes.begin() ;

    std::cout << (*ans)->area() << std::endl ;

    ASSERT_NEAR(380.13271108436493, (*ans)->area(), epsilon);
}

TEST (Sort, sortByIncreasingCompactness) {


    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Rectangle rect2(3, 8, 12, 22);
    Rectangle rect3(3, 8, 12, 23);
    Triangle tri({1, 1}, {3, 1}, {6, 6});
    Triangle tri2({1, 1}, {6, 1}, {1, 5});

    std::list<Shape *> shapes;

    shapes.push_back(&cir);
    shapes.push_back(&rect);
    shapes.push_back(&rect2);
    shapes.push_back(&rect3);
    shapes.push_back(&tri);
    shapes.push_back(&tri2);




    Sort sort1 ;
    sort1.sortByIncreasingCompactness(&shapes) ;
    /*
        std::cout << "------------------" << std::endl;

        for ( std::list<Shape *>::iterator y = shapes.begin() ; y != shapes.end() ; y++ ) {
             std::cout << (*y)->perimeter() << std::endl;
        }
        */
    std::list<Shape *>::iterator ans = shapes.begin() ;

    std::cout << ( (*ans)->area() / (*ans)->perimeter() ) << std::endl ;

    ASSERT_NEAR(0.335524989, ( (*ans)->area() / (*ans)->perimeter() ) , epsilon);

}

#endif
