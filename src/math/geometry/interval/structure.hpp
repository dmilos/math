#ifndef math_geometry_interval_structure_hpp_
 #define math_geometry_interval_structure_hpp_

// ::math::geometry::interval::structure<scalar_name,dimension_number>

#include <array>

#include "../../linear/vector/structure.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
       struct structure
        {
         public:
           typedef ::math::linear::vector::point<scalar_name, dimension_number > point_type;
           typedef std::array<point_type, 2 > container_type;

           structure() {}
           structure( point_type const& first, point_type const& second ):m_corner{ first, second }{}
           explicit structure( container_type const& c ):m_corner{ c }{}

           point_type const& operator[]( unsigned const index )const{ return m_corner[index]; }
           point_type      & operator[]( unsigned const index )     { return m_corner[index]; }

           point_type const& corner( unsigned const index )const{ return m_corner[index]; }
           point_type      & corner( unsigned const index )     { return m_corner[index]; }

           point_type const& lo( )const{ return m_corner[0]; }
           point_type      & lo( )     { return m_corner[0]; }

           point_type const& hi( )const{ return m_corner[1]; }
           point_type      & hi( )     { return m_corner[1]; }

           container_type const& container()const{ return m_corner; }
           container_type      & container()     { return m_corner; }

         public:
           container_type m_corner;
        };

       template
        <
          typename scalar_name
        >
       struct structure< scalar_name, 1 >
        {
         public:
           typedef scalar_name point_type;

           structure() {}
           structure( point_type const& first, point_type const& second ):m_corner{ first, second }{}

           point_type const& operator[]( unsigned const index )const{ return m_corner[index]; }
           point_type      & operator[]( unsigned const index )     { return m_corner[index]; }

           point_type const& corner( unsigned const index )const{ return m_corner[index]; }
           point_type      & corner( unsigned const index )     { return m_corner[index]; }

           point_type const& lo( )const{ return m_corner[0]; }
           point_type      & lo( )     { return m_corner[0]; }

           point_type const& hi( )const{ return m_corner[1]; }
           point_type      & hi( )     { return m_corner[1]; }

         public:
           point_type m_corner[2];
        };


      }
    }
  }

#endif
