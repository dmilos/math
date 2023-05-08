#ifndef Dh_math_linear_homography_transform
#define Dh_math_linear_homography_transform

// ::math::linear::homography::transform( result, matrix, point )
// ::math::linear::homography::transform( result, matrix )
// ::math::linear::homography::transform( result, matrix, direction )


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

      template<  typename scalar_name, ::math::type::size_type dimension_number >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, dimension_number >         & result
         ,::math::linear::homography::structure<  scalar_name, dimension_number >    const& display2space
         ,::math::linear::vector::structure<      scalar_name, dimension_number >    const& point
         )
        {
         scalar_name divisor  =  display2space[dimension_number][dimension_number];

         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           divisor += display2space[dimension_number][ i ] * point[ i ];
          }

         for( ::math::type::size_type i=0; i< dimension_number; ++i )
          {
           result[i] = display2space[i][dimension_number];
           for( ::math::type::size_type j=0; j < dimension_number; ++j )
            {
             result[i] += display2space[i][j] * point[j];
            }
           result[i] /= divisor;
          }

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >           & result
         ,::math::linear::homography::structure<  scalar_name, 2 >      const& display2space
         ,::math::linear::vector::structure<      scalar_name, 2 >      const& point
         )
        {
         scalar_name divisor  =  display2space[2][0] * point[0]
                               + display2space[2][1] * point[1]
                               + display2space[2][2];

         result[0] = ( display2space[0][0] * point[0]  +  display2space[0][1] * point[1]  +  display2space[0][2])/divisor;
         result[1] = ( display2space[1][0] * point[0]  +  display2space[1][1] * point[1]  +  display2space[1][2])/divisor;

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >          & result
         ,::math::linear::homography::structure<  scalar_name, 2>      const& display2space
         )
        {
         typedef ::math::linear::vector::structure<      scalar_name, 2 >  vector_type;

         ::math::linear::homography::transform( result, display2space, vector_type( result ) );

         return /*result*/;
        }


      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& display2space
         ,::math::linear::vector::structure<      scalar_name, 3 >      const& point
         )
        {
         scalar_name divisor  =   display2space[3][0] * point[0]
                               +  display2space[3][1] * point[1]
                               +  display2space[3][2] * point[2]
                               +  display2space[3][3];

         result[0] = ( display2space[0][0] * point[0]  +  display2space[0][1] * point[1] + display2space[0][2] * point[2]  +  display2space[0][3] )/divisor;
         result[1] = ( display2space[1][0] * point[0]  +  display2space[1][1] * point[1] + display2space[1][2] * point[2]  +  display2space[1][3] )/divisor;
         result[2] = ( display2space[2][0] * point[0]  +  display2space[2][1] * point[1] + display2space[2][2] * point[2]  +  display2space[2][3] )/divisor;

         return /*result*/;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& display2space
         )
        {
         typedef ::math::linear::vector::structure<      scalar_name, 3 >  vector_type;

         ::math::linear::homography::transform( result, display2space, vector_type( result ) );

         return /*result*/;
        }

       template<  typename scalar_name >
        ::math::geometry::direction::ABC2D<scalar_name> &
        transform // TODO should be structure
         (
           ::math::geometry::direction::ABC2D<scalar_name>                  & result
          ,::math::linear::homography::structure<  scalar_name, 2 >    const& display2space
          ,::math::geometry::direction::ABC2D<scalar_name>             const& direction
         )
         {
          ::math::linear::homography::structure<  scalar_name, 2 >  jacobian;
          ::math::linear::matrix::invert( jacobian, display2space );
          ::math::linear::matrix::transpose( jacobian );
          ::math::linear::matrix::transform( result.array(), jacobian, direction.array() );
          return result;
         }

     }
   }
 }

#endif
