#ifndef Dh_math_geometry_ellipse_general2D_HPP_
 #define Dh_math_geometry_ellipse_general2D_HPP_

 // ::math::geometry::ellipse::general2D<scalar_name>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/fill.hpp"

#include "./base2d.hpp"
#include "./simple2d.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace ellipse
      {

       template< typename scalar_name >
        class base2D;

       template< typename scalar_name >
        class simple2D;

       template
        <
          typename scalar_name
        >
        class general2D
         {
          public:
            typedef scalar_name   scalar_type;

            typedef ::math::linear::vector::point<scalar_name,2>   point_type;

            typedef ::math::geometry::ellipse::base2D<scalar_name>   base2D_type;
            typedef ::math::geometry::ellipse::simple2D<scalar_name> simple2D_type;
            typedef ::math::geometry::ellipse::general2D<scalar_name> this_type;

            general2D()
             {
             }

            general2D( point_type const& center, scalar_type const& mayor_X, scalar_type const& minor_Y, scalar_type const& rotation = scalar_type( 0 ) )
             :m_center(  center )
             ,m_size( { mayor_X, minor_Y } )
             ,m_rotation( rotation )
             {
             }

            general2D( point_type const& center, point_type const& size, scalar_type const& rotation = scalar_type( 0 ) )
             :m_center(  center )
             ,m_size( size )
             ,m_rotation( rotation )
             {
             }

            explicit general2D( base2D_type const& base )
             {
              *this = base;
             }

            explicit general2D( simple2D_type const& simple )
             {
              *this = simple;
             }

            this_type & operator=( base2D_type const& base )
             {
              ::math::linear::vector::fill( this->m_center, scalar_type(0) );
              this->m_size = base.size();
              m_rotation = 0;
              return *this;
             }

            this_type & operator=( simple2D_type const& simple )
             {
              this->m_center = simple.center();
              this->m_size = simple.size();
              this->m_rotation = 0;
              return *this;
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

         public:
            point_type const& center()const{ return m_center; }
            point_type      & center()     { return m_center; }
          private:
            point_type m_center;

          public:
            scalar_type const& rotation()const{ return m_rotation; }
            scalar_type      & rotation()     { return m_rotation; }
          private:
            scalar_type m_rotation;

         };

      }
    }
  }

#endif
