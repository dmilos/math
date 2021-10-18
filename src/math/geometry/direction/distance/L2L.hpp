#ifndef math_geometry_distance_L2L
#define math_geometry_distance_L2L

// ::math::geometry::direction::L2L< scalar, dimension>.process( parametric, parametric )
// ::math::geometry::direction::distance( median, parametric, parametric, epsilon )

#include "../../../linear/vector/dot.hpp"
#include "../../../linear/vector/subtraction.hpp"
#include "../../../linear/vector/scale.hpp"
#include "../../../linear/vector/addition.hpp"
#include "../../../linear/vector/distance.hpp"

#include "../parametric.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<  typename scalar_name, unsigned dimension_number >
       class L2L
        {
         public: // http://geomalgorithms.com/a07-_distance.html
           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, dimension_number > point_type;
           typedef ::math::geometry::direction::parametric< scalar_type, dimension_number > parametric_type;

         public:
           bool process( parametric_type const& first, parametric_type const& second, scalar_type const& epsilon = 1e-12 )
            {
             point_type bond;

             ::math::linear::vector::subtraction( bond, first.origin(), second.origin() );

             scalar_type a = ::math::linear::vector::dot( first.direction(),   first.direction() );
             scalar_type b = ::math::linear::vector::dot( first.direction(),  second.direction() );
             scalar_type c = ::math::linear::vector::dot( second.direction(), second.direction() );

             scalar_type D = a * c  -  b * b;

             if( D < epsilon )
              {
               return false;
              }

             scalar_type d = ::math::linear::vector::dot( first.direction(),  bond );
             scalar_type e = ::math::linear::vector::dot( second.direction(), bond );

             m_lambdaF = ( b * e - c * d  ) / D;
             m_lambdaS = ( a * e - b * d  ) / D;

             ::math::linear::vector::scale(    m_pointF, m_lambdaF,  first.direction() );
             ::math::linear::vector::addition( m_pointF, first.origin() );

             ::math::linear::vector::scale(    m_pointS, m_lambdaS ,  second.direction() );
             ::math::linear::vector::addition( m_pointS, second.origin() );

             return true;
            }

         public:
           scalar_type const& distance()const
            {
             return m_distance = ::math::linear::vector::distance( m_pointF, m_pointS );
            }

           point_type const& median()const
            {
             ::math::linear::vector::addition( m_median, m_pointF, m_pointS );
             ::math::linear::vector::scale<scalar_type>( m_median, 0.5 );
             return m_median;
            }

         public:
           point_type const& first()const{ return m_pointF; }
         private:
           point_type m_pointF;

         public:
           point_type const& second()const{ return m_pointS; }
         private:
           point_type m_pointS;

         public:
           scalar_type const& lambdaF()const{ return m_lambdaF; }
         private:
           scalar_type m_lambdaF;

         public:
           scalar_type const& lambdaS()const{ return m_lambdaS; }
         private:
           scalar_type m_lambdaS;

         private:
           mutable scalar_type m_distance;
           mutable point_type  m_median;
        };

      template<  typename scalar_name, unsigned dimension_number >
       bool distance
        (
          scalar_name  & distance
         ,::math::geometry::direction::parametric< scalar_name, dimension_number > const& first
         ,::math::geometry::direction::parametric< scalar_name, dimension_number > const& second
         ,scalar_name const& epsilon = 1e-12
        )
        {
         ::math::geometry::direction::L2L<scalar_name,dimension_number> calculator;

         if( false == calculator.process( first, second, epsilon ) )
          {
           return false;
          }
         distance = calculator.distance();
         return true;
        }

     }
   }
 }

#endif
