#ifndef Dh_math_geometry_homography_transform
#define Dh_math_geometry_homography_transform

// ::math::linear::homography::transform( result, matrix, point )
// ::math::linear::homography::transform( result, matrix )


#include "./structure.hpp"
#include "../vector/vector.hpp"
#include "../matrix/invert.hpp"
#include "../matrix/matrix.hpp"

namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name, unsigned dimension_number >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, dimension_number >         & result
         ,::math::linear::homography::structure<  scalar_name, dimension_number >    const& matrix
         ,::math::linear::vector::structure<      scalar_name, dimension_number >    const& point
         )
        {
         scalar_name divisor  =  matrix[dimension_number][dimension_number];

         for( std::size_t i=0; i < dimension_number; ++i )
          {
           divisor += matrix[dimension_number][ i ] * point[ i ];
          }

         for( std::size_t i=0; i< dimension_number; ++i )
          {
           result[i] = matrix[i][dimension_number];
           for( std::size_t j=0; j < dimension_number; ++j )
            {
             result[i] += matrix[i][j] * point[j];
            }
           result[i] /= divisor;
          }

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >           & result
         ,::math::linear::homography::structure<  scalar_name, 2 >      const& matrix
         ,::math::linear::vector::structure<      scalar_name, 2 >      const& point
         )
        {
         scalar_name divisor  =  matrix[2][0] * point[0]
                               + matrix[2][1] * point[1]
                               + matrix[2][2];

         result[0] = ( matrix[0][0] * point[0]  +  matrix[0][1] * point[1]  +  matrix[0][2])/divisor;
         result[1] = ( matrix[1][0] * point[0]  +  matrix[1][1] * point[1]  +  matrix[1][2])/divisor;

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >          & result
         ,::math::linear::homography::structure<  scalar_name, 2>      const& matrix
         )
        {
         ::math::linear::vector::structure<      scalar_name, 2 >           tmp;

         ::math::linear::homography::transform( tmp, matrix, result );

         result = tmp;
         return /*result*/;
        }


      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& matrix
         ,::math::linear::vector::structure<      scalar_name, 3 >      const& point
         )
        {
         scalar_name divisor  =   matrix[3][0] * point[0]
                               +  matrix[3][1] * point[1]
                               +  matrix[3][2] * point[2]
                               +  matrix[3][3];

         result[0] = ( matrix[0][0] * point[0] +  matrix[0][1] * point[1] + matrix[0][2] * point[2] + matrix[0][3] )/divisor;
         result[1] = ( matrix[1][0] * point[0] +  matrix[1][1] * point[1] + matrix[1][2] * point[2] + matrix[1][3] )/divisor;
         result[2] = ( matrix[2][0] * point[0] +  matrix[2][1] * point[1] + matrix[2][2] * point[2] + matrix[2][3] )/divisor;

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& homography
         )
        {
         ::math::linear::vector::structure<      scalar_name, 3 >           tmp;

         ::math::linear::homography::transform( tmp, homography, result );

         result = tmp;
         return /*result*/;
        }

       template<  typename scalar_name >
        ::math::geometry::direction::ABC2D<scalar_name> &
        transform // TODO should be structure
         (
           ::math::geometry::direction::ABC2D<scalar_name>                  & result
          ,::math::linear::homography::structure<  scalar_name, 2 >    const& homography
          ,::math::geometry::direction::ABC2D<scalar_name>             const& direction
         )
         {
          ::math::linear::homography::structure<  scalar_name, 2 >  jacobian;
          ::math::linear::matrix::invert( jacobian, homography );
          ::math::linear::matrix::transpose( jacobian );
          ::math::linear::matrix::transform( result.array(), jacobian, direction.array() );
          return result;
         }

     }
   }
 }

#endif
