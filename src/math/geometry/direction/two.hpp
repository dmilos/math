#ifndef math_geometry_direction_two
#define math_geometry_direction_two

// ::math::geometry::direction::two<scalar_name,dimension_number>
#include <cmath>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/addition.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<typename scalar_name, std::size_t dimension_number >
       class parametric;

      template
       <
        typename        scalar_name
       ,std::size_t   dimension_number
       >
       class two //!< defined with two points: first and second
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, dimension_number > point_type;

           typedef ::math::geometry::direction::parametric<scalar_name, dimension_number> paramatric_type;

         public:
           two()
            {
            }

           two( point_type const& first, point_type const& second )
            : m_first( first )
            , m_second( second )
            {
            }

           explicit two( paramatric_type const& paramatric )
            {
             *this = paramatric;
            }

         public:
           two & operator=( paramatric_type const& parametric )
            {
             this->m_first = parametric.origin();
             ::math::linear::vector::addition( this->m_second, parametric.origin(), parametric.direction() );

             return *this;
            }

         public:
           point_type const& first()const
            {
             return m_first;
            }
           point_type & first()
            {
             return m_first;
            }
         private:
           point_type m_first;

         public:
           point_type const& second()const
            {
             return m_second;
            }
           point_type & second()
            {
             return m_second;
            }
         private:
           point_type m_second;
        };

      template<typename scalar_name >
       class ABC2D;

      template< typename    scalar_name >
       class polar;

      template< typename        scalar_name >
       class two< scalar_name, 2 >
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, 2 > point_type;

           typedef ::math::geometry::direction::two<scalar_name, 2>              this_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>              ABC2D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> paramatric_type;
           typedef ::math::geometry::direction::polar<scalar_name>              polar_type;

         public:
           two()
            {
            }

           two( point_type const& first, point_type const& second )
            : m_first( first )
            , m_second( second )
            {
            }

           explicit two( ABC2D_type const& abc )
            {
             *this = abc;
            }

           explicit two( paramatric_type const& paramatric )
            {
             *this = paramatric;
            }

         public:
           two & operator=( ABC2D_type const& abc )
            {
             scalar_type D = abc.A() * abc.A()  +  abc.B() * abc.B();

             this->m_first[0] = - abc.C() * ( abc.A() / D );
             this->m_first[1] = - abc.C() * ( abc.B() / D );

             this->m_second[0] = (-abc.B()) + this->m_first[0];
             this->m_second[1] = (+abc.A()) + this->m_first[1];

             return *this;
            }

           two & operator=( paramatric_type const& parametric )
            {
             this->m_first = parametric.origin();
             ::math::linear::vector::addition( this->m_second, parametric.origin(), parametric.direction() );

             return *this;
            }

           two & operator=( polar_type const& polar )
            {
             this->m_first     = polar.origin();
             this->m_second[0] = polar.origin()[0] + cos( polar.angle() );
             this->m_second[1] = polar.origin()[1] + sin( polar.angle() );
             return *this;
            }

         public:
           point_type const& first()const
            {
             return m_first;
            }
           point_type & first()
            {
             return m_first;
            }
         private:
           point_type m_first;

         public:
           point_type const& second()const
            {
             return m_second;
            }
           point_type & second()
            {
             return m_second;
            }
         private:
           point_type m_second;

        };

     }
   }
 }

#endif
