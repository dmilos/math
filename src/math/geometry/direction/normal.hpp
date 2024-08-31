#ifndef math_geometry_direction_normal
#define math_geometry_direction_normal

// ::math::geometry::direction::normal<scalar_name>
#include <array>
#include "../../linear/vector/structure.hpp"





namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<typename scalar_name, std::size_t dimension_number >
        class two;

      template<typename scalar_name, std::size_t dimension_number >
        class parametric;

      template
       <
         typename         scalar_name
        ,std::size_t dimension_number
       >
       class normal
        {
         public:

           typedef std::size_t      size_type;
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point<scalar_type,dimension_number> angle_type;

           typedef ::math::geometry::direction::parametric<scalar_name, dimension_number>        parametric_type;
           typedef ::math::geometry::direction::normal<scalar_name, dimension_number >               normal_type,this_type;

         public:
           explicit normal(  )
            {
            }
           explicit normal( angle_type const& angle, scalar_type const& rotation=0, scalar_type const& radius=0 )
            :m_angle( angle ), m_rotation( rotation ), m_radius( radius )
            {
            }

           explicit normal( parametric_type const& parametric )
            {
             *this = parametric;
            }

         public:
           this_type & operator=( parametric_type const& parametric )
            {
             // TODO parametric.origin() = ::math::geometry::polar2cartesian( this->angle() )
             // TODO
             // TODO parametric.direction()[0] = cos( this->angle() );
             // TODO parametric.direction()[1] = sin( this->angle() );

             return *this;
            }

         public:
           void set( scalar_type const& A=0, scalar_type const& twist=0, scalar_type const& R=0 )
            {
             m_angle = A;
             m_rotation = twist;
             m_radius = R;
            }

         public:
           angle_type const& angle()const { return m_angle; }
           angle_type      & angle()      { return m_angle; }
           scalar_type const& rotation()const{ return m_rotation; }
           scalar_type      & rotation()     { return m_rotation; }
           scalar_type const& radius()const{ return m_radius; }
           scalar_type      & radius()     { return m_radius; }

         private:
           angle_type  m_angle;
           scalar_type m_rotation;
           scalar_type m_radius;
        };

      template<typename scalar_name >
        class ABC2D;

      template<typename scalar_name>
        class polar;

      template
       <
         typename scalar_name
       >
       class normal<scalar_name,2> // cos( alpha ) * x  +  sin( alpha ) * y - R = 0
        {
         public:

           typedef std::size_t      size_type;
           typedef scalar_name scalar_type;

           typedef ::math::geometry::direction::two<scalar_name, 2>               two_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>              ABC2D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type;
           typedef ::math::geometry::direction::polar<scalar_name>              polar_type;
           typedef ::math::geometry::direction::normal<scalar_name,2>          normal_type, this_type;

         public:
           explicit normal( scalar_type const& angle=0, scalar_type const& radius=0 )
            :m_angle( angle ), m_radius( radius )
            {
            }

           explicit normal( two_type const& two )
            {
             *this = two;
            }

           explicit normal( parametric_type const& parametric )
            {
             *this = parametric;
            }

           explicit normal( polar_type const& polar )
            {
             *this = polar;
            }

         public:
           this_type & operator=( ABC2D_type const& abc )
            {
             // TODO
             return *this;
            }

           this_type & operator=( parametric_type const& parametric )
            {

             return *this;
            }

           this_type & operator=( polar_type const& polar )
            {
             return *this;
            }

           this_type & operator=( two_type const& two )
            {
             // TODO two.first()[0] = this->radius() * cos( this->angle() + math::constants::PHI_div_2 );
             // TODO two.first()[1] = this->radius() * sin( this->angle() + math::constants::PHI_div_2 );
             // TODO
             // TODO two.second()[0] = two.first()[0] + cos( this->angle() );
             // TODO two.second()[1] = two.first()[1] + sin( this->angle() );

             return *this;
            }

         public:
           void set( scalar_type const& A, scalar_type const& R )
            {
             m_angle = A;  m_radius = R;
            }

         public:
           scalar_type const& angle()const { return m_angle; }
           scalar_type      & angle()      { return m_angle; }
           scalar_type const& radius()const{ return m_radius; }
           scalar_type      & radius()     { return m_radius; }

         private:
           scalar_type m_angle;
           scalar_type m_radius;
        };

     }
   }
 }

#endif
