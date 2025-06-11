#ifndef math_geometry_direction_polar
#define math_geometry_direction_polar

// ::math::geometry::direction::polar<scalar_name>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/length.hpp"
#include "../deg2rad.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<typename scalar_name, std::size_t dimesion_number >
       class two;

      template<typename scalar_name >
       class ABC2D;

      template<typename scalar_name, std::size_t dimesion_number >
       class parametric;

      template<typename scalar_name, std::size_t dimension_number>
        class normal;

      template< typename scalar_name>
       class polar //!< defined with one point and angle against X-axis
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, 2 > point_type;

           typedef ::math::geometry::direction::two<scalar_name, 2>               two_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>              ABC2D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type;
           typedef ::math::geometry::direction::polar<scalar_name>               this_type;
           typedef ::math::geometry::direction::normal<scalar_name, 2>         normal_type;

         public:
           polar()
            {
            }

         public:
           polar( point_type const& origin, scalar_type const& angle )
            : m_origin( origin )
            , m_angle( angle )
            {
            }

         public:
           explicit polar( two_type const& two )
            {
             *this = two;
            }

         public:
           explicit polar( ABC2D_type const& abc )
            {
             *this = abc;
            }

         public:
           explicit polar( parametric_type const& parametric )
            {
             *this = parametric;
            }

         public:
           explicit polar( normal_type const& normal )
            {
             *this = normal;
            }

         public:
           polar & operator=( two_type const& two )
            {
             this->m_origin = two.first();
             point_type direction;

             ::math::linear::vector::subtraction( direction, two.second(), two.first() );

             this->m_angle = atan2( direction[1], direction[0] );

             return *this;
            }

           polar & operator=( ABC2D_type const& abc )
            {
             scalar_type D;
             D = abc.A() * abc.A()  +  abc.B() * abc.B() ;
             this->m_origin[0] = - abc.C() * ( abc.A() / D );
             this->m_origin[1] = - abc.C() * ( abc.B() / D );

             this->m_angle = atan2( -abc.A(), +abc.B() );

             return *this;
            }

           polar & operator=( parametric_type const& parametric )
            {
             this->m_origin = parametric.origin();
             this->m_angle = atan2( parametric.direction()[1], parametric.direction()[0] );

             return *this;
            }

           this_type & operator=( normal_type const& normal )
            {
             this->origin()[0] = normal.radius() * cos( normal.angle() - math::constants::PHI_div_2 );
             this->origin()[1] = normal.radius() * sin( normal.angle() - math::constants::PHI_div_2 );

             this->angle() = normal.angle();
             return *this;
            }


         public:
           point_type point( scalar_type const& parameter )const
            {
             return { this->m_origin[0] + parameter * cos( this->m_angle ), this->m_origin[1] + parameter * sin( this->m_angle ) };
            }

           this_type & fix( )
            {
             //this->m_angle = fmod( this->m_angle, ::math::geometry::deg2rad( 360.0 ) );
             if( 0 < this->m_angle )
              {
               this->m_angle = fmod( this->m_angle, ::math::geometry::deg2rad( 360.0 ) );
              }
             else if( this->m_angle < 0 )
              {
               this->m_angle = fmod( this->m_angle, ::math::geometry::deg2rad( 360.0 ) );
               this->m_angle += ::math::geometry::deg2rad( 360.0 );
              }

             return *this;
            }

           this_type fix( )const
            {
             this_type result;
             //result.m_angle = fmod( this->m_angle, ::math::geometry::deg2rad( 360.0 ) );

             if( 0 < result.m_angle )
              {
               result.m_angle = fmod( result.m_angle, ::math::geometry::deg2rad( 360.0 ) );
              }
             else if( result.m_angle < 0 )
              {
               result.m_angle = fmod( result.m_angle, ::math::geometry::deg2rad( 360.0 ) );
               result.m_angle += ::math::geometry::deg2rad( 360.0 );
              }
             result.m_origin = this->m_origin;
             return result;
            }

        public:
           point_type const& origin()const
            {
             return m_origin;
            }
           point_type & origin()
            {
             return m_origin;
            }
         private:
           point_type m_origin;

         public:
           scalar_type const& angle()const
            {
             return m_angle;
            }
           scalar_type & angle()
            {
             return m_angle;
            }
         private:
           scalar_type m_angle;
        };

     }
   }
 }

#endif
