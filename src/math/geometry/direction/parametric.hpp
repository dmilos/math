#ifndef math_geometry_direction_parametric
#define math_geometry_direction_parametric

// ::math::geometry::direction::parametric<scalar_name, dimension>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/length.hpp"

#include "../../constants.hpp"


namespace math
 {
  namespace geometry
   {
      namespace direction
       {

      template<typename scalar_name, std::size_t dimesion_number >
       class two;

      template<typename scalar_name, std::size_t dimension_number>
        class normal;

      template
       <
        typename    scalar_name
       ,std::size_t   dimension_number
       >
       class parametric //! defined by origin and  direction
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, dimension_number > point_type;

           typedef ::math::geometry::direction::two<scalar_name, dimension_number> two_type;

         public:
           parametric()
            {
            }

         public:
           parametric( point_type const& origin, point_type const& direction )
            : m_origin( origin )
            , m_direction( direction )
            {
            }

         public:
           explicit parametric( two_type const& two )
            : m_origin( two.first() )
            {
             *this = two;
            }

         public:
           parametric & operator=( two_type const& two )
            {
             m_origin = two.first();
             ::math::linear::vector::subtraction( this->m_direction, two.second(), two.first() );
             return *this;
            }

         public:
           void point( point_type  & p, scalar_type const& parameter )const
            {
             ::math::linear::vector::scale( p, parameter, this->direction() );
             ::math::linear::vector::addition( p, this->origin() );
            }

           point_type  point( scalar_type const& parameter )const
            {
             point_type result;
             ::math::linear::vector::scale( result, parameter, this->direction() );
             ::math::linear::vector::addition( result, this->origin() );
             return result;
            }

           static point_type point( point_type const& origin, scalar_type const& parameter, point_type const& direction )
            {
             point_type result;
             ::math::linear::vector::scale( result, parameter, direction );
             ::math::linear::vector::addition( result, origin );
             return result;
            }

           static void point( point_type  & p, point_type const& origin, scalar_type const& parameter, point_type const& direction )
            {
             point_type result;
             ::math::linear::vector::scale( result, parameter, direction );
             ::math::linear::vector::addition( result, origin );
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
           point_type const& direction()const
            {
             return m_direction;
            }
           point_type & direction()
            {
             return m_direction;
            }
         private:
           point_type m_direction;
        };

      template<typename scalar_name >
       class ABC2D;

      template< typename    scalar_name >
       class polar;

      template< typename    scalar_name>
       class parametric< scalar_name, 2 >
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, 2 > point_type;

           typedef ::math::geometry::direction::two<scalar_name, 2>               two_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>              ABC2D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type, this_type;
           typedef ::math::geometry::direction::polar<scalar_name>              polar_type;
           typedef ::math::geometry::direction::normal<scalar_name, 2>         normal_type;

         public:
           parametric()
            {
            }

         public:
           parametric( point_type const& origin, point_type const& direction )
            : m_origin( origin )
            , m_direction( direction )
            {
            }

         public:
           explicit parametric( two_type const& two )
            {
             *this = two;
            }

         public:
           explicit parametric( ABC2D_type const& abc )
            {
             *this = abc;
            }
         public:
           explicit parametric( polar_type const& polar )
            {
             *this = polar;
            }

           explicit parametric( normal_type const& normal )
            {
             *this = normal;
            }

         public:
           this_type & operator=( two_type const& two )
            {
             m_origin = two.first();
             ::math::linear::vector::subtraction( this->m_direction, two.second(), two.first() );
             //::math::linear::vector::length<scalar_type>( this->m_direction, 1 );
             return *this;
            }

           this_type & operator=( ABC2D_type const& abc )
            {
             // original this->m_direction[0] = - abc.B();
             // original this->m_direction[1] = + abc.A();

             this->m_direction[0] = + abc.B();
             this->m_direction[1] = - abc.A();

             scalar_type D = abc.A() * abc.A()  +  abc.B() * abc.B();

             this->m_origin[0] = - abc.C() * ( abc.A() / D );
             this->m_origin[1] = - abc.C() * ( abc.B() / D );
             return *this;
            }

           this_type & operator=( polar_type const& polar )
            {
             this->m_direction[0] = cos( polar.angle() ) ;
             this->m_direction[1] = sin( polar.angle() ) ;

             this->m_origin = polar.origin();

             return *this;
            }

           this_type & operator=( normal_type const& normal )
            {
             this->origin()[0] = normal.radius() * cos( normal.angle() - ::math::constants::PHI_div_2 );
             this->origin()[1] = normal.radius() * sin( normal.angle() - ::math::constants::PHI_div_2 );
             this->direction()[0] = cos( normal.angle() );
             this->direction()[1] = sin( normal.angle() );
             return *this;
            }

         public:
           point_type point( scalar_type const& parameter )const
            {
             using namespace ::math::linear::vector;
             return this->origin() + parameter * this->direction();
            }

          static point_type const& point( point_type const& origin, scalar_type const& parameter, point_type const&direction )
           {
             using namespace ::math::linear::vector;
             return origin() + parameter* direction();
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
           point_type const& direction()const
            {
             return m_direction;
            }
           point_type & direction()
            {
             return m_direction;
            }
         private:
           point_type m_direction;
        };

     }
   }
 }

#endif
