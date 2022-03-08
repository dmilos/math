#ifndef Dh_math_linear_homography_construct1
#define Dh_math_linear_homography_construct1

 // ::math::linear::homography::construct( result, A, B )

#include "./structure.hpp"









namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void construct //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name,1> & result
         ,scalar_name const& A
         ,scalar_name const& B
        ) // B = homography( A )
        {
         result[0][0] = B-A*B;  result[0][1] =    0;
         result[1][0] = B-A;    result[1][1] =  A-A*B;
        }


      template<  typename scalar_name >
       void construct_invert //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name,1> & result
         ,scalar_name const& A
         ,scalar_name const& B
        ) // A = homography( B )
        {
         result[0][0] = A-A*B;  result[0][1] =  A - B;
         result[1][0] =     0;  result[1][1] =  B-A*B;
        }

     }
   }
 }

#endif
