#ifndef Dh_math_geometry_circle_simple2d
 #define Dh_math_geometry_circle_simple2d

// ::math::geometry::circle::simple2d<scalar_name>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/fill.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace circle
      {

       template<typename scalar_name, std::size_t dimension_number >
         class unit;

       template
        <
          typename scalar_name
         ,std::size_t dimension_number
        >
        class simple
         {
          public:
            typedef scalar_name scalar_type;
            typedef ::math::linear::vector::point<scalar_name,dimension_number>   point_type;

            typedef ::math::geometry::circle::unit<scalar_name,dimension_number>              unit_type;
            typedef ::math::geometry::circle::simple<scalar_name,dimension_number>            this_type;


          public:
            simple(){}
            simple( point_type const& center, scalar_type const& radius )
             :m_center(center), m_radius(radius)
             {
             }

            explicit simple( unit_type const& unit )
             {
              *this = unit;
             }

          public:
            this_type & operator=( unit_type const& parametric )
             {
              ::math::linear::vector::fill( this->m_center, scalar_type(0) );
              this->m_radius = scalar_type(1);
              return *this;
             }

            point_type const& center()const
             {
              return m_center;
             }
            scalar_type const& radius()const
             {
              return m_radius;
             }

          public:
            point_type m_center;
            scalar_type m_radius;
         };

      }
    }
  }

#endif
