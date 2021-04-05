#ifndef math_geometry_quadric2d_structure
 #define math_geometry_quadric2d_structure

 // ::math::geometry::quadric::structure2d<scalar_name>

#include "../../linear/vector/structure.hpp"
#include "../../linear/matrix/structure.hpp"

#include "../../geometry/circle/unit.hpp"
#include "../../geometry/circle/simple.hpp"

#include "../../geometry/ellipse/base2d.hpp"
#include "../../geometry/ellipse/general2d.hpp"
#include "../../geometry/ellipse/simple2d.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace quadric
      {

       template
        <
          typename scalar_name
        >
        class structure2d
         {
          public:
            typedef scalar_name scalar_type;
            typedef ::math::linear::vector::point<scalar_type,6> coefficient_type;
            typedef ::math::linear::matrix::structure<scalar_type,3,3> matrix_type;

            typedef ::math::geometry::circle::unit<scalar_type,2>          circle_unit2D_type;
            typedef ::math::geometry::circle::simple<scalar_type,2>      circle_simple2D_type;

            typedef ::math::geometry::ellipse::simple2D<scalar_type>      ellipse_simple2D_type;
            typedef ::math::geometry::ellipse::general2D<scalar_type>    ellipse_general2D_type;
            typedef ::math::geometry::ellipse::base2D<scalar_type>          ellipse_base2D_type;

            typedef ::math::geometry::quadric::structure2d<scalar_type> this_type;

            structure2d()
            {
            }

            explicit structure2d( circle_unit2D_type const& that )
             {
              auto const & a = 1; auto const a2 = a * a;
              auto const & b = 1; auto const b2 = b * b;
              auto const & theta = 0; auto sinT = sin( theta ); auto cosT = cos( theta );
              auto const & x = 0;
              auto const & y = 0;

              auto const & A = m_coefficient[0] = a2 * this_type::sqr( sinT ) + b2 * this_type::sqr( cosT );
              auto const & B = m_coefficient[1] = 2 * ( b2 - a2 ) * sinT * cosT;
              auto const & C = m_coefficient[2] = a2 * this_type::sqr( cosT ) + b2 * this_type::sqr( sinT );
              /*auto const & D = */m_coefficient[3] =  - 2 * A * x -      B * y;
              /*auto const & E = */m_coefficient[4] =      - B * x -  2 * C * y;
              /*auto const & F = */m_coefficient[5] = A * this_type::sqr( x ) + B*x*y+ C*this_type::sqr( y ) - a2 * b2;
             }

            explicit structure2d( circle_simple2D_type const& that )
             {
              auto const & a = that.radius(); auto const a2 = a * a;
              auto const & b = that.radius(); auto const b2 = b * b;
              auto const & theta = 0; auto sinT = sin( theta ); auto cosT = cos( theta );
              auto const & x = that.center()[0];
              auto const & y = that.center()[1];

              auto const & A = m_coefficient[0] = a2 * this_type::sqr( sinT ) + b2 * this_type::sqr( cosT );
              auto const & B = m_coefficient[1] = 2 * ( b2 - a2 ) * sinT * cosT;
              auto const & C = m_coefficient[2] = a2 * this_type::sqr( cosT ) + b2 * this_type::sqr( sinT );
              auto const & D = m_coefficient[3] =  - 2 * A * x -      B * y;
              auto const & E = m_coefficient[4] =      - B * x -  2 * C * y;
              auto const & F = m_coefficient[5] = A * this_type::sqr( x ) + B*x*y+ C*this_type::sqr( y ) - a2 * b2;

             }

            explicit structure2d( ellipse_simple2D_type  const& that )
             : structure2d( ellipse_general2D_type ( that ) )
             {
             }
            explicit structure2d( ellipse_base2D_type  const& that )
             : structure2d( ellipse_general2D_type ( that ) )
             {
             }

            explicit structure2d( ellipse_general2D_type  const& that)
             { // https://en.wikipedia.org/wiki/Ellipse#Ellipse_as_quadric
              auto const & a = that.size()[0]; auto const a2 = a * a;
              auto const & b = that.size()[1]; auto const b2 = b * b;
              auto const & theta = that.rotation(); auto sinT = sin( theta ); auto cosT = cos( theta );
              auto const & x = that.center()[0];
              auto const & y = that.center()[1];

              auto const & A = m_coefficient[0] = a2 * this_type::sqr( sinT ) + b2 * this_type::sqr( cosT );
              auto const & B = m_coefficient[1] = 2 * ( b2 - a2 ) * sinT * cosT;
              auto const & C = m_coefficient[2] = a2 * this_type::sqr( cosT ) + b2 * this_type::sqr( sinT );
              auto const & D = m_coefficient[3] =  - 2 * A * x -      B * y;
              auto const & E = m_coefficient[4] =      - B * x -  2 * C * y;
              auto const & F = m_coefficient[5] = A * this_type::sqr( x ) + B*x*y+ C*this_type::sqr( y ) - a2 * b2;
             }

          public:
            void matrix( matrix_type & m )
             {
              m[0][0] = this_type::A();   m[0][1] = this_type::B()/2; m[0][2] = this_type::D()/2;
              m[1][0] = this_type::B()/2; m[1][1] = this_type::C();   m[1][2] = this_type::E()/2;
              m[2][0] = this_type::D()/2; m[2][1] = this_type::E()/2; m[2][2] = this_type::F();
             }

          public: // A X^2 + B X Y + C Y^2 + D X + E Y + F = 0
             scalar_type const& A()const{ return m_coefficient[0]; }
             scalar_type const& B()const{ return m_coefficient[1]; }
             scalar_type const& C()const{ return m_coefficient[2]; }
             scalar_type const& D()const{ return m_coefficient[3]; }
             scalar_type const& E()const{ return m_coefficient[4]; }
             scalar_type const& F()const{ return m_coefficient[5]; }

            coefficient_type const& coefficient()const
             {
              return m_coefficient;
             }
            coefficient_type & coefficient()
             {
              return m_coefficient;
             }
          private:
            coefficient_type m_coefficient;
          private:
            scalar_type sqr( scalar_type const& a){ return a*a; }
         };

      }
    }
  }

#endif
