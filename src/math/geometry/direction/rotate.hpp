#ifndef math_geometry_direction_rotate_HPP_
 #define math_geometry_direction_rotate_HPP_

// ::math::geometry::direction::rotate( r, alpha, direction )
// ::math::geometry::direction::rotate( r, center, alpha, direction )

#include "../../linear/vector/rotate.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/addition.hpp"
#include "./parametric.hpp"
#include "./two.hpp"
#include "./abc.hpp"

#include "../../linear/vector/rotate.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace direction
      {

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::parametric<scalar_name, 2>       &    result_param
          ,       value_name                                        const&     angle_param
          ,::math::geometry::direction::parametric<scalar_name, 2>  const& direction_param
         )
         {
          ::math::linear::vector::rotate( result_param.origin(),    angle_param, direction_param.origin()    );
          ::math::linear::vector::rotate( result_param.direction(), angle_param, direction_param.direction() );
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::parametric<scalar_name, 2>          &    result_param
          ,::math::linear::vector::point< scalar_name, 2 >             const&    center_param
          ,       value_name                                           const&     angle_param
          ,::math::geometry::direction::parametric<scalar_name, 2>     const& direction_param
         )
         {
          ::math::geometry::direction::parametric<scalar_name, 2> tmp{direction_param};

          ::math::linear::vector::subtraction( tmp.origin(), center_param );

          ::math::geometry::direction::rotate( result_param, angle_param, tmp );

          ::math::linear::vector::addition( result_param.origin(), center_param );
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::two<scalar_name, 2>       &    result_param
          ,       value_name                                 const&     angle_param
          ,::math::geometry::direction::two<scalar_name, 2>  const& direction_param
         )
         {
          ::math::linear::vector::rotate( result_param.first(),  angle_param, direction_param.first()  );
          ::math::linear::vector::rotate( result_param.second(), angle_param, direction_param.second() );
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::two<scalar_name, 2>       &    result_param
          ,::math::linear::vector::point< scalar_name, 2 >   const&    center_param
          ,       value_name                                 const&     angle_param
          ,::math::geometry::direction::two<scalar_name, 2>  const& direction_param
         )
         {
          ::math::geometry::direction::two<scalar_name, 2> tmp{direction_param};

          ::math::linear::vector::subtraction( tmp.first(),  center_param );
          ::math::linear::vector::subtraction( tmp.second(), center_param );

          ::math::geometry::direction::rotate( result_param, angle_param, tmp );

          ::math::linear::vector::addition( result_param.first(),  center_param );
          ::math::linear::vector::addition( result_param.second(), center_param );
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::ABC2D<scalar_name>       &    result_param
          ,       value_name                                const&     angle_param
          ,::math::geometry::direction::ABC2D<scalar_name>  const& direction_param
         )
         {
          //X = x * cos( angle_param ) - y * sin( angle_param );
          //Y = x * sin( angle_param ) + y * cos( angle_param );
           auto const& A = direction_param.A();
           auto const& B = direction_param.B();

          result_param.A() =  A * cos( angle_param ) +  B * sin( angle_param );
          result_param.B() = -A * sin( angle_param ) +  B * cos( angle_param );
          result_param.C() = direction_param.C();
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::ABC2D<scalar_name>       &    result_param
          ,::math::linear::vector::point< scalar_name, 2 >  const&    center_param
          ,       value_name                                const&     angle_param
          ,::math::geometry::direction::ABC2D<scalar_name>  const& direction_param
         )
         {
          ::math::geometry::direction::ABC2D<scalar_name> tmp{direction_param};

          tmp.C() = + tmp.A()*center_param[0] + tmp.B()*center_param[1] + tmp.C();

          ::math::geometry::direction::rotate( result_param, angle_param, tmp );

          result_param.C() = - result_param.A()*center_param[0] - result_param.B()*center_param[1] + result_param.C();
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::polar<scalar_name>       &    result_param
          ,       value_name                                const&     angle_param
          ,::math::geometry::direction::polar<scalar_name>  const& direction_param
         )
         {
          ::math::linear::vector::rotate( result_param.origin(), angle_param, direction_param.origin() );
          result_param.angle() = direction_param.angle() + angle_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::geometry::direction::polar<scalar_name>       &    result_param
          ,::math::linear::vector::point< scalar_name,2 >   const&    center_param
          ,       value_name                                const&     angle_param
          ,::math::geometry::direction::polar<scalar_name>  const& direction_param
         )
         {
          ::math::linear::vector::rotate( result_param.origin(), angle_param, direction_param.origin(), center_param );
          result_param.angle() = direction_param.angle() + angle_param;
         }

      }
    }
  }

 #endif
