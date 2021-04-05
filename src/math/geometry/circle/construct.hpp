#ifndef Dh_math_geometry_circle_construct
 #define Dh_math_geometry_circle_construct

// ::math::geometry::circle::construct<scalar_name>( first, second, third )

#include  "./simple.hpp"
#include  "../direction/bisector.hpp"
#include  "../direction/intersect.hpp"
#include  "../../linear/vector/distance.hpp"
#include  "../../linear/matrix/determinant.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace circle
      {

       template
        <
          typename scalar_name
        >
        bool construct
         (
           ::math::geometry::circle::simple<scalar_name,2>          & result
          ,::math::linear::vector::point<scalar_name,2>        const& first
          ,::math::linear::vector::point<scalar_name,2>        const& second
          ,::math::linear::vector::point<scalar_name,2>        const& third
         )
         {
          auto bisector_first = ::math::geometry::direction::bisector( first, second );
          auto bisector_secnd = ::math::geometry::direction::bisector( first, third );
          auto bisector_third = ::math::geometry::direction::bisector( second, third );

          ::math::linear::vector::point<  scalar_name, 2 > center;
          if( false == ::math::geometry::direction::intersect( center, bisector_first, bisector_third ) )
           {
            return false;
           }

           auto radius = ::math::linear::vector::distance( center, first );
           result = ::math::geometry::circle::simple<scalar_name,2>{ center, radius };
           return true;
         }


       template
        <
          typename scalar_name
        >
        bool construct
         (
           ::math::geometry::circle::simple<scalar_name,3>          & result
          ,::math::linear::vector::point<scalar_name,3>        const& p0
          ,::math::linear::vector::point<scalar_name,3>        const& p1
          ,::math::linear::vector::point<scalar_name,3>        const& p2
          ,::math::linear::vector::point<scalar_name,3>        const& p3
         )
         { // create sphere from 4 given points
          ::math::linear::matrix::structure<scalar_name,4,4> matrix;
          static scalar_name epsilon = 1e-8;

           matrix[0][0] = p0[0];  matrix[0][1] = p0[1]; matrix[0][2] = p0[2];  matrix[0][3] = scalar_name(1);
           matrix[1][0] = p1[0];  matrix[1][1] = p1[1]; matrix[1][2] = p1[2];  matrix[1][3] = scalar_name(1);
           matrix[2][0] = p2[0];  matrix[2][1] = p2[1]; matrix[2][2] = p2[2];  matrix[2][3] = scalar_name(1);
           matrix[3][0] = p3[0];  matrix[3][1] = p3[1]; matrix[3][2] = p3[2];  matrix[3][3] = scalar_name(1);
           auto T = ::math::linear::matrix::determinant( matrix );

           if( ( -epsilon < T ) && ( T < epsilon ) )
            {
             return false;
            }

           auto t0 =  -::math::linear::vector::dot( p0, p0 );
           auto t1 =  -::math::linear::vector::dot( p1, p1 );
           auto t2 =  -::math::linear::vector::dot( p2, p2 );
           auto t3 =  -::math::linear::vector::dot( p3, p3 );

           matrix[0][0] = t0;
           matrix[1][0] = t1;
           matrix[2][0] = t2;
           matrix[3][0] = t3;
           auto D = ::math::linear::matrix::determinant( matrix ) / T;

           matrix[0][0] = p0[0];  matrix[0][1] = t0;
           matrix[1][0] = p1[0];  matrix[1][1] = t1;
           matrix[2][0] = p2[0];  matrix[2][1] = t2;
           matrix[3][0] = p3[0];  matrix[3][1] = t3;
           auto E = ::math::linear::matrix::determinant( matrix ) / T;

                                  matrix[0][1] = p0[1]; matrix[0][2] = t0;
                                  matrix[1][1] = p1[1]; matrix[1][2] = t1;
                                  matrix[2][1] = p2[1]; matrix[2][2] = t2;
                                  matrix[3][1] = p3[1]; matrix[3][2] = t3;

           auto F = ::math::linear::matrix::determinant( matrix ) / T;

                                                        matrix[0][2] = p0[2]; matrix[0][3] = t0;
                                                        matrix[1][2] = p1[2]; matrix[1][3] = t1;
                                                        matrix[2][2] = p2[2]; matrix[2][3] = t2;
                                                        matrix[3][2] = p3[2]; matrix[3][3] = t3;

           auto G = ::math::linear::matrix::determinant( matrix ) / T;

           auto radius = scalar_name( sqrt( D*D + E*E + F*F - scalar_name(4)*G ) ) / scalar_name(2);
           result = ::math::geometry::circle::simple<scalar_name,3>{ { -D/scalar_name(2), -E /scalar_name(2), -F /scalar_name(2) }, radius };

           return true;
         }

      }
    }
  }

#endif
