#ifndef Dh_math_linear_homography_convert
#define Dh_math_linear_homography_convert

// ::math::linear::homography::convert( result, affine )


#include "../affine/structure.hpp"

namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name, unsigned dimension_number >
       void convert // from_affine
        (
          ::math::linear::homography::structure<  scalar_name, dimension_number >      & result
         ,::math::linear::affine::structure<      scalar_name, dimension_number >      const& affine
        )
        {
         for( std::size_t i = 0; i< dimension_number ; ++i )
          for( std::size_t j = 0; j< dimension_number; ++j )
           {
            result[i][j] = affine[i][j];
           }

         for( std::size_t i = 0; i < dimension_number; ++i )
          {
           result[i][dimension_number ] = affine[dimension_number ][i];
           result[dimension_number ][i] = 0;
          }

         result[dimension_number ][dimension_number ] = 1;

         return ;
        }

     }
   }
 }

#endif
