#ifndef Dh_math_linear_homography_construct1
#define Dh_math_linear_homography_construct1

 // ::math::linear::homography::construct( result, A, B )
 // ::math::linear::homography::construct_invert( result, A, B )
 // ::math::linear::homography::construct_invert( result, data )

#include "./structure.hpp"
#include "../../polynomial/linear/interpolate.hpp"
#include "../../function/clamper.hpp"
#include "../../linear/matrix/multiply.hpp"






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
        ) //0 = homography(0) ;  B = homography( A );  1 = homography(1);
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
        ) // 0 = homography(0) ;  A = homography( B ); 1 = homography(1);
        {
         result[0][0] = A-A*B;  result[0][1] =  A - B;
         result[1][0] =     0;  result[1][1] =  B-A*B;
        }

      template<  typename scalar_name >
       void construct  //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name,1>      & result
         ,std::array< std::pair<scalar_name,scalar_name>, 3  > const& data
        ) //! data[0].second = homography( data[0].first );
          //! data[1].second = homography( data[1].first );
          //! data[2].second = homography( data[2].first );
        {
         ::math::linear::homography::structure<scalar_name,1> toOne;

         ::math::polynomial::linear::interpolate<scalar_name>( toOne[0], data[0].first, data[2].first, 0, 1 );
         toOne[1][0] =  0;  toOne[1][1] =   1;

         scalar_name A = ::math::function::any_to_any<scalar_name>( data[1].first , data[0].first,  data[2].first,  0, 1 );
         scalar_name B = ::math::function::any_to_any<scalar_name>( data[1].second, data[0].second, data[2].second, 0, 1 );

         ::math::linear::homography::structure<scalar_name,1> base;
         ::math::linear::homography::construct( base, A, B );

         ::math::linear::homography::structure<scalar_name,1> fromOne;
         ::math::polynomial::linear::interpolate<scalar_name>( fromOne[0], 0, 1, data[0].second, data[2].second );
         fromOne[1][0] =  0;  fromOne[1][1] =   1;

         ::math::linear::matrix::multiply( result, fromOne, base, toOne );
        }

     }
   }
 }

#endif
