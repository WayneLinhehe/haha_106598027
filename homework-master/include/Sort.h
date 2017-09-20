#include <list>
#include "Shapes.h"
#include <math.h>

class Sort {

public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
        //std::cout << shapeList << std::endl ;

        for ( std::list<Shape *>::iterator it = (*shapeList).begin() ; it != (*shapeList).end() ; it++ ) {

            std::list<Shape *>::iterator count = (*shapeList).end() ;
            for (std::list<Shape *>::iterator it2 = (*shapeList).begin();  it2 !=  count   ;   it2++) {

                if ( (*it)->perimeter() < (*it2)->perimeter() ){
                    std::swap(*it,*it2) ;
                }
            }
            /*
                        std::cout << "333333333333" << std::endl;
                        for ( std::list<Shape *>::iterator y = (*shapeList).begin() ; y != (*shapeList).end() ; y++ ) {
                            std::cout << (*y)->perimeter() << std::endl;
                        }
                        std::cout << "33333333333333" << std::endl;
                        */
            count-- ;
        }
    };

public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
        //std::cout << shapeList << std::endl ;

        for ( std::list<Shape *>::iterator it = (*shapeList).begin() ; it != (*shapeList).end() ; it++ ) {

            std::list<Shape *>::iterator count = (*shapeList).end() ;
            for (std::list<Shape *>::iterator it2 = (*shapeList).begin();  it2 != count ;   it2++) {

                if ( (*it)->perimeter() > (*it2)->perimeter() ){
                    std::swap(*it,*it2) ;
                }
            }

            /*
            std::cout << "333333333333" << std::endl;
            for ( std::list<Shape *>::iterator y = (*shapeList).begin() ; y != (*shapeList).end() ; y++ ) {
                std::cout << (*y)->perimeter() << std::endl;
            }
            std::cout << "33333333333333" << std::endl;
*/
            count-- ;
        }
    };

public :static void sortByIncreasingArea(std::list<Shape *> * shapeList){


        //std::cout << shapeList << std::endl ;

        for ( std::list<Shape *>::iterator it = (*shapeList).begin() ; it != (*shapeList).end() ; it++ ) {
            std::list<Shape *>::iterator count = (*shapeList).end() ;
            for (std::list<Shape *>::iterator it2 = (*shapeList).begin();  it2 != count ;  it2++) {

                if ( (*it)->area() < (*it2)->area() ){
                    std::swap(*it,*it2) ;
                }
            }
            /*
            std::cout << "333333333333" << std::endl;
            for ( std::list<Shape *>::iterator y = (*shapeList).begin() ; y != (*shapeList).end() ; y++ ) {
                std::cout << (*y)->perimeter() << std::endl;
            }
            std::cout << "33333333333333" << std::endl;
*/
            count-- ;
        }









    };

public :static void sortByDecreasingArea(std::list<Shape *> * shapeList){

        //std::cout << shapeList << std::endl ;

        for ( std::list<Shape *>::iterator it = (*shapeList).begin() ; it != (*shapeList).end() ; it++ ) {

            std::list<Shape *>::iterator count = (*shapeList).end() ;
            for (std::list<Shape *>::iterator it2 = (*shapeList).begin();  it2 != count ;   it2++) {

                if ( (*it)->area() > (*it2)->area() ){
                    std::swap(*it,*it2) ;
                }
            }
            /*
            std::cout << "333333333333" << std::endl;
            for ( std::list<Shape *>::iterator y = (*shapeList).begin() ; y != (*shapeList).end() ; y++ ) {
                std::cout << (*y)->perimeter() << std::endl;
            }
            std::cout << "33333333333333" << std::endl;
*/
            count-- ;
        }



    };

public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList) {
        ;
        // Compactness = area/perimeter

        //std::cout << shapeList << std::endl ;

        for (std::list<Shape *>::iterator it = (*shapeList).begin(); it != (*shapeList).end(); it++) {

            std::list<Shape *>::iterator count = (*shapeList).end() ;
            for (std::list<Shape *>::iterator it2 = (*shapeList).begin(); it2 != count ; it2++) {

                if ( ( (*it)->area() / (*it)->perimeter() ) < ( (*it2)->area() / (*it2)->perimeter() ) )  {
                    std::swap(*it, *it2);
                }
            }
            /*
            std::cout << "333333333333" << std::endl;
            for ( std::list<Shape *>::iterator y = (*shapeList).begin() ; y != (*shapeList).end() ; y++ ) {
                std::cout << (*y)->perimeter() << std::endl;
            }
            std::cout << "33333333333333" << std::endl;
    */
            count--;
        }
    }


};
