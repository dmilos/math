#ifndef math_geometry_direction_fit2D
#define math_geometry_direction_fit2D

// ::math::geometry::direction::fit2D<double>::process( abc, cloud )
// ::math::geometry::direction::fit2D<double>::process( a, b, samples )

#include <vector>
#include "../../linear/vector/vector.hpp"
#include "./abc.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template
       <
        typename scalar_name = double
       >
       struct fit2D
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::type::size_type size_type;
           typedef ::math::linear::vector::point<scalar_name,2>       point_type;
           typedef ::math::geometry::direction::ABC2D<scalar_type>    line_type;

           typedef std::vector< point_type >   cloud_type;
           typedef std::vector< scalar_type > sample_type;


         public:
           fit2D()
            {
             reset();
            }
         public:
           static bool process( line_type & line, cloud_type const& cloud )
            {
             return process( line.A(), line.B(), line.C(), cloud );
            }

           // A * x + B * y + C = 0
           static bool process( scalar_type & A, scalar_type & B, scalar_type & C, cloud_type const& cloud )
            {
             if( cloud.size() < 2 )
               {
                return false;
               }

             scalar_type X=0, Y=0, XY=0, X2=0, Y2 = 0;

             for( auto const& point: cloud )
              {
               X  += point[0];
               Y  += point[1];
               XY += point[0] * point[1];
               X2 += point[0] * point[0];
               Y2 += point[1] * point[1];
              }

             X  /= cloud.size();
             Y  /= cloud.size();
             XY /= cloud.size();
             X2 /= cloud.size();
             Y2 /= cloud.size();

             scalar_type Bx = X2 - X * X;
             scalar_type By = Y2 - Y * Y;

             if( fabs( Bx ) < fabs( By ) )
              {
               A = By;
               B = - ( XY - X * Y );
              }
             else
              {
               A = - ( XY - X * Y );
               B = Bx;
              }

             C = - ( A * X + B * Y );

             return true;
            }

           // y = a * x + b; f((sample.size()-1)/2) = sample[0]; f((sample.size()-1)/2+1) = sample[1]; ...
           static bool process( scalar_type & a, scalar_type & b, sample_type const& sample )
            {
             if( sample.size() < 2 )
              {
               return false;
              }

             scalar_type X = -(sample.size() - scalar_type(1)) / scalar_type(2), Y=0, XY=0, X2=0;

             for( auto const& value : sample )
              {
               Y  += value;
               XY += X * value;
               X2 += X * X;
               X  += scalar_type(1);
              }

             Y  /= sample.size();
             XY /= sample.size();
             X2 /= sample.size();

             a = XY / X2;
             b = Y;

             return true;
            }

           void reset()
            {
             m_count = 0;
             m_X  = 0;
             m_Y  = 0;
             m_XY = 0;
             m_X2 = 0;
             m_Y2 = 0;
            }
           bool push( point_type const& sample )
            {
             ++m_count;
             m_X  += sample[0];
             m_Y  += sample[1];
             m_XY += sample[0] * sample[1];
             m_X2 += sample[0] * sample[0];
             m_Y2 += sample[1] * sample[1];
             return true;
            }

           line_type direction()const
            {
             scalar_type X  = m_X  / m_count;
             scalar_type Y  = m_Y  / m_count;
             scalar_type XY = m_XY / m_count;
             scalar_type X2 = m_X2 / m_count;
             scalar_type Y2 = m_Y2 / m_count;

             scalar_type Bx = X2 - X * X;
             scalar_type By = Y2 - Y * Y;

             line_type result;
             if( fabs( Bx ) < fabs( By ) )
              {
               result.A() = By;
               result.B() = - ( XY - X * Y );
              }
             else
              {
               result.A() = - ( XY - X * Y );
               result.B() = Bx;
              }

             result.C() = - ( result.A() * X + result.B() * Y );
             return result;
            }
        private:
          size_type m_count;
          scalar_type  m_X, m_Y, m_XY,  m_X2,   m_Y2;
       };

      template
       <
        typename scalar_name = double
       >
       bool fit
        (
         ::math::geometry::direction::ABC2D<scalar_name>                    & abc
         , std::vector< ::math::linear::vector::point<scalar_name,2> > const& cloud
        )
        {
          return ::math::geometry::direction::fit2D<scalar_name>::process( abc, cloud );
        }

     }
   }
 }

#endif
