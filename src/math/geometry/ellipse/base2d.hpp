#ifndef Dh_math_geometry_ellipse_base2D_HPP_
 #define Dh_math_geometry_ellipse_base2D_HPP_

 // ::math::geometry::ellipse::base2D<scalar_name>

#include "../../linear/vector/structure.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace ellipse
      {

       template
        <
          typename scalar_name
        >
        class base2D // ->  center
         {
          public:
            typedef scalar_name   scalar_type;
            typedef ::math::linear::vector::point<scalar_name,2>   point_type;

            base2D()
             {
             }

            base2D( scalar_type const& mayor_X, scalar_type const& minor_Y )
             :m_size( { mayor_X, minor_Y } )
             {
             }

          public:
            point_type const& size()const{ return m_size; }
            point_type      & size()     { return m_size; }

            scalar_type const& mayor()const{ return m_size[0]; }
            scalar_type      & mayor()     { return m_size[0]; }
            scalar_type const&     a()const{ return m_size[0]; }
            scalar_type      &     a()     { return m_size[0]; }
            scalar_type const& minor()const{ return m_size[1]; }
            scalar_type      & minor()     { return m_size[1]; }
            scalar_type const&     b()const{ return m_size[1]; }
            scalar_type      &     b()     { return m_size[1]; }
          private:
            point_type m_size;
         };

      }
    }
  }

#endif
