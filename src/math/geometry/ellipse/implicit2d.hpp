 #ifndef Dh_math_geometry_ellipse_implicit2D_HPP_
 #define Dh_math_geometry_ellipse_implicit2D_HPP_

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
        class implicit2D
         {     // A x^2 +  Bxy + Cy^2+  Dx +  Ey+F = 0;
          public:
            typedef scalar_name   scalar_type;

            typedef ::math::linear::vector::point<scalar_name,2>   point_type;

            typedef ::math::geometry::ellipse::base2D<scalar_name>   base2D_type;
            typedef ::math::geometry::ellipse::simple2D<scalar_name> simple2D_type;
            typedef ::math::geometry::ellipse::general2D<scalar_name> general2D_type;
            typedef ::math::geometry::ellipse::implicit2D<scalar_name> this_type;

            implicit2D()
             {
             }

            implicit2D( scalar_type const& A, scalar_type const& B, scalar_type const& C, scalar_type const& D, scalar_type const& E, scalar_type const& F )
             :m_coeffcient{A,B,C,D,E,F}
             {
             }

            explicit implicit2D( base2D_type const& base )
             {
              *this = base;
             }

            explicit implicit2D( simple2D_type const& simple )
             {
              *this = simple;
             }

            explicit implicit2D( general2D_type const& simple )
             {
              *this = simple;
             }

            this_type & operator=( base2D_type const& base )
             {
              auto const & a = base.mayor();
              auto const & b = base.minor();

              A() =  b*b ;
              B() =     0;
              C() = a*a ;
              D() =    0;
              E() =    0;
              F() = - a*a*b*b;
              return *this;
             }

            this_type & operator=( simple2D_type const& simple )
             {
              auto const & a = simple.mayor(); //! < axis along x
              auto const & b = simple.minor();
              auto const & x = simple.center()[0];
              auto const & y = simple.center()[1];
              A() =  b*b ;
              B() =  0;
              C() = a*a;
              D() = -2*A() * x - B() * y;
              E() = -B()*x-2*C() * y;
              F() =  A()*x*x + B()*x*y + C()*y*y - a*a*b*b;
              return *this;
             }

            this_type & operator=( general2D_type const& general )
             {
              auto const & a = general.mayor(); //! < axis along x
              auto const & b = general.minor();
              auto const & theta = general.rotation();
              auto const & x = general.center()[0];
              auto const & y = general.center()[1];

              auto const & c = cos( theta );
              auto const & s = sin( theta );

              A() = a*a* s * s +  b*b* c*c;
              B() = 2*(b*b-a*a)* s * c;
              C() = a*a* c * c +  b*b* s*s;
              D() = -2*A()*x - B() * y;
              E() =  -B()*x - 2*C()*y ;
              F() =  A()*x*x + B()*x*y + C()*y*y-a*a*b*b;

              //B() /= A();
              //C() /= A();
              //D() /= A();
              //E() /= A();
              //F() /= A();
              //A() /= A();

              return *this;
             }

          public:
            scalar_type eval( point_type const& point )
             {
              auto const& x = point[0];
              auto const& y = point[1];

              auto result = A() * x*x + B() *x*y + C()*y*y + D() * x + E() * y + F();
              return result;
             }

          public:     
            typedef  std::array<scalar_type,6> coeffcient_type;
            coeffcient_type const& coeffcient()const{ return m_coeffcient; }
            coeffcient_type      & coeffcient()     { return m_coeffcient; }
          public:
           coeffcient_type  m_coeffcient;

          public:
            scalar_type const& A()const{ return m_coeffcient[0]; }
            scalar_type      & A()     { return m_coeffcient[0]; }
            scalar_type const& B()const{ return m_coeffcient[1]; }
            scalar_type      & B()     { return m_coeffcient[1]; }
            scalar_type const& C()const{ return m_coeffcient[2]; }
            scalar_type      & C()     { return m_coeffcient[2]; }
            scalar_type const& D()const{ return m_coeffcient[3]; }
            scalar_type      & D()     { return m_coeffcient[3]; }
            scalar_type const& E()const{ return m_coeffcient[4]; }
            scalar_type      & E()     { return m_coeffcient[4]; }
            scalar_type const& F()const{ return m_coeffcient[5]; }
            scalar_type      & F()     { return m_coeffcient[5]; }
         };

      }
    }
  }

#endif
