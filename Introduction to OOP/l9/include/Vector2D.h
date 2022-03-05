#pragma once
#include <cstring>


class Vector2D {
    /**vector with carthesian coordinates. 
       Class also contains variable count which counts number of existing vectors*/

    private:
        double x;   //x coordinate
        double y;   //y coordinate
    public:
        int static count;   //counter of existing vectors
        
        //constructors
        Vector2D();
        /**basic constructor which increases count of vectors*/
        
        Vector2D(const Vector2D &vector);
        /**copy constructor, while copying prints information about copy to console*/
        
        Vector2D(const Vector2D &&vector);
        /**move constructor, while moving prints information about move to console*/
        
        
        //destructor
        ~Vector2D();
        /**decreases count of vectors*/ 
        
        
        //named constructors 
        Vector2D static fromCarthesian(double x,double y);
        /**Creates and returns Vector2D with given carthesian coordinates */
        
        Vector2D static fromPolar(double r, double phi);
        /**Creates and returns Vector2D with carthesian coordinates calculated from given polar coordinates*/
        
        
        //methods
        void print(const char *message) const;
        /**prints message and vector coordinates in carthesian system*/
        
        double dot(const Vector2D &vector) const;
        /** returns dot value of two vectors */
        
        Vector2D add(const Vector2D &vector) const;
        /** returns new vector which is a sum of two vectors */
};
