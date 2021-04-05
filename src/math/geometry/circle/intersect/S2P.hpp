#ifndef Dh_math_geometry_circle_intersectS2P
 #define Dh_math_geometry_circle_intersectS2P

// ::math::geometry::circle::S2P<scalar_name>
// ::math::geometry::circle::intersect<scalar_name>( l1, l2, simple, parametric )

#include "../simple.hpp"

#include "../../direction/parametric.hpp"

#include "../../../linear/vector/dot.hpp"
#include "../../../linear/vector/subtraction.hpp"

#include "../../../polynomial/quadric/solve.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace circle
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        struct S2P  // intersect simple circleND with direction
         {
          public:
            typedef scalar_name scalar_type;

            typedef ::math::linear::vector::point<scalar_name,dimension_number>                 point_type;
            typedef ::math::geometry::circle::simple<scalar_name,dimension_number>             circle_type;
            typedef ::math::geometry::direction::parametric<scalar_name,dimension_number>   direction_type;

            static unsigned process
             (
               scalar_type  & lambda0
              ,scalar_type  & lambda1
              ,circle_type      const & circle
              ,direction_type   const & direction
              ,scalar_type      const & epsilon = 1e-6
             )
             {
              point_type heading;
              ::math::linear::vector::subtraction( heading, direction.origin(), circle.center() );
              scalar_type coefficient[3]=
               {
                 ::math::linear::vector::dot( heading,heading ) - circle.radius() * circle.radius()
                ,::math::linear::vector::dot( direction.direction(),heading )
                ,::math::linear::vector::dot( direction.direction(), direction.direction() )
               };
              scalar_type zero[2];

              switch( ::math::polynomial::quadric::solve::general( zero, coefficient, epsilon ) )
               {
                case( 0 ):
                 {
                  return 0;
                 }break;
                case( 1 ):
                 {
                  lambda0 = lambda1 = zero[0];
                  return 1;
                 }break;
                case( 2 ):
                 {
                  lambda0 = zero[0];
                  lambda1 = zero[1];
                  return 2;
                 }break;
               }

              return 0;
             }
         };

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        unsigned intersect
         (
           scalar_name  & lambda0
          ,scalar_name  & lambda1
          ,::math::geometry::circle::simple<scalar_name,dimension_number>      const & simple
          ,::math::geometry::direction::parametric<scalar_name,dimension_number>   const & direction
          ,scalar_name      const & epsilon = 1e-6
         )
         {
          return ::math::geometry::circle::S2P<scalar_name,dimension_number>::process( lambda0,lambda1,simple, direction, epsilon );
         }


      }
    }
  }

#endif
