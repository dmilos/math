#ifndef Dh_math_geometry_ellipse_simple2D_HPP_
 #define Dh_math_geometry_ellipse_simple2D_HPP_

// ::math::geometry::ellipse::simple2D<scalar_name>

#include "../../linear/vector/structure.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace ellipse
      {

       template< typename scalar_name >
        class base2D;

       template
        <
          typename scalar_name
        >
        class simple2D // -> aligned
         {
          public:
            typedef scalar_name scalar_type;
            typedef ::math::linear::vector::point<scalar_name,2>   point_type;

            typedef ::math::geometry::ellipse::base2D<scalar_name>   base2D_type;
            typedef ::math::geometry::ellipse::simple2D<scalar_name> this_type;

          public:
            simple2D(){}

            simple2D( point_type const& center, scalar_type const& mayor_X, scalar_type const& minor_Y )
             :m_center( center )
             ,m_size( { mayor_X, minor_Y } )
             {
             }

            explicit simple2D( base2D_type const& base )
             {
              *this = base;
             }

            this_type & operator=( base2D_type const& base )
             {
              return *this;
             }


          public:
            point_type const& center()const
             {
              return m_center;
             }
            point_type & center()
             {
              return m_center;
             }
          private:
            point_type  m_center;

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
