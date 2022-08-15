#ifndef Dh_math_geometry_circle_intersectU2P
 #define Dh_math_geometry_circle_intersectU2P

// ::math::geometry::circle::U2P<scalar_name>( unit )
// ::math::geometry::circle::intersect<scalar_name>( l1, l2, parametric )

#include "../unit.hpp"

#include "../../direction/parametric.hpp"

#include "../../../linear/vector/dot.hpp"


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
         ,std::size_t dimension_number
        >
        struct U2P //!< Intersect unit circle and direction
         {
          public:
            typedef scalar_name scalar_type;

            typedef ::math::linear::vector::point<scalar_name,dimension_number>                 point_type;
            typedef ::math::geometry::direction::parametric<scalar_name,dimension_number>   direction_type;

            static unsigned process
             (
               scalar_type  & lambda0
              ,scalar_type  & lambda1
              ,direction_type   const & direction
              ,scalar_type      const & epsilon = 1e-10
             )
             {
              point_type const& heading = direction.origin();
              scalar_type coefficient[3]=
               {
                    ::math::linear::vector::dot( heading, heading ) - 1
                ,2* ::math::linear::vector::dot( direction.direction(), heading )
                ,   ::math::linear::vector::dot( direction.direction(), direction.direction() )
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
         ,std::size_t dimension_number
        >
        unsigned intersect
         (
           scalar_name  & lambda0
          ,scalar_name  & lambda1
          ,::math::geometry::direction::parametric<scalar_name,dimension_number>   const & direction
          ,scalar_name      const & epsilon = 1e-6
         )
         {
          return ::math::geometry::circle::U2P<scalar_name,dimension_number>::process( lambda0, lambda1, direction, epsilon );
         }



      }
    }
  }

#endif
