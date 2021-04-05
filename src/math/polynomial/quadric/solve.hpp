#ifndef math_polynomial_quadric_solve_HPP_
 #define math_polynomial_quadric_solve_HPP_

// ::math::polynomial::solve::quadric::general<scalar_name>( root, coefficient, epsilon = 1e-6 )

#include "../linear/solve.hpp"


 #define math_polynomial_solve_quadric(_a,_b,_c,_d,_t1,_t2) \
  (                                                         \
   ( (_d)=(_b)*(_b)-4.0*(_a)*(_c), 1e-20 < (_d) ) ?         \
    (                                                       \
     (_d)=sqrt(_d),                                         \
      (_t1)=(-(_b)-(_d))/(_a)*0.5,                          \
      (_t2)=(-(_b)+(_d))/(_a)*0.5,                          \
     2                                                      \
    ):                                                      \
    (                                                       \
     ( 0.0 <= (_d) ) ?                                      \
     ((_t1)=(_t2)=-(_b)/(_a),1) : 0                         \
    )                                                       \
  )


 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {
       namespace solve
        {

         template
          <
            typename scalar_name
          >
          int form110( scalar_name root[2], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-6 )
           {
            return 1;
           }

         template
          <
            typename scalar_name
          > // C + 0 *x + A* x^2 = 0
          int depressed( scalar_name root[2], scalar_name const & C, scalar_name const& A, scalar_name const& epsilon = 1e-6 )
           {
            scalar_name & solution = root[0] = -C/A;

            if( solution < -epsilon )
             {
              root[0] = root[1] = NAN;
              return 0;
             }

            if( solution  < epsilon )
             {
              solution = 0;
              root[1] = NAN;
              return 1;
             }
            root[0] = - sqrt( solution );
            root[1] = - solution;
            return 2;
           }

         template
          <
            typename scalar_name
          > // C + 0 *x + 1 * x^2 = 0
          int trivial( scalar_name root[2], scalar_name const C, scalar_name const& epsilon = 1e-6 )
           {
            scalar_name & solution = root[0] = -C;

            if( solution < -epsilon )
             {
              root[0] = root[1] = NAN;
              return 0;
             }

            if( solution < epsilon )
             {
              solution = 0;
              root[1] = NAN;
              return 1;
             }

            root[0] = - sqrt( solution );
            root[1] = - root[0];
            return 2;
           }

         template
          <
            typename scalar_name
          > // C + B *x + A * x^2 = 0
          int general( scalar_name root[2], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-6 )
           {
            scalar_name const& a = coefficient[2];
            if( ( -epsilon < a ) && ( a < epsilon ) )
             {
              root[1] = NAN;
              return ::math::polynomial::solve::linear( root, coefficient, epsilon );
             }

            scalar_name const& b = coefficient[1];
            scalar_name const& c = coefficient[0];
            if( ( -epsilon < b ) && ( b < epsilon ) )
             {
              return ::math::polynomial::quadric::solve::depressed( root, c, a, epsilon );
             }

            if( ( -epsilon < c ) && ( c < epsilon ) )
             {
              root[0] = scalar_name(0);
              if( 0  == ::math::polynomial::solve::linear( root+1, coefficient+1, epsilon ) )
               {
                root[0] = root[1] = NAN;
                return 0;
               }
              if( root [ 1 ] < root[ 0 ] )
               {
                root[0] = root[1];
                root[0] = scalar_name(0);
               }
              return 2;
             }

            scalar_name d = b*b - scalar_name(4)*a*c;

            if( d < - epsilon )
             {
              root[1] = root[0] = NAN;
              return 0;
             }

            if( d < epsilon )
             {
              root[0] = -b/(scalar_name(2)*a);
              root[1] = NAN;
              return 1;
             }

            d = sqrt( d );

            if( a < 0 )
             {
              root[1] = ( -b - d )/(scalar_name(2)*a);
              root[0] = ( -b + d )/(scalar_name(2)*a);
             }
            else
             {
              root[0] = ( -b - d )/(scalar_name(2)*a);
              root[1] = ( -b + d )/(scalar_name(2)*a);
             }

            return 2;
           }

         template
          <
            typename scalar_name
          > // C + B *x + A * x^2 = 0
          inline unsigned general( std::array<scalar_name,2> & root, std::array<scalar_name,3> const & coefficient, scalar_name const& epsilon = 1e-6 )
           {
            return ::math::polynomial::quadric::solve::general( root.data(), coefficient.data(), epsilon );
           }

         template
          <
            typename scalar_name
          >// C + B *x + A * x^2 = 0
          inline unsigned general( scalar_name &z0, scalar_name &z1, std::array<scalar_name,3> const & coefficient, scalar_name const& epsilon = 1e-6 )
           {
            scalar_name root[2];
            auto count = ::math::polynomial::quadric::solve::general( root, coefficient.data(), epsilon );
            z0 = root[0];
            z1 = root[1];
            return count;
           }

         template
          <
            typename scalar_name
          > // C + B *x + 1 * x^2 = 0
          inline int monic( scalar_name root[2], scalar_name const coefficient[2], scalar_name const& epsilon = 1e-6 )
           {
            scalar_name const& b = coefficient[1];
            scalar_name const& c = coefficient[0];
            if( ( -epsilon < b ) && ( b < epsilon ) )
             {
              return ::math::polynomial::quadric::solve::trivial<scalar_name>( root, c, epsilon );
             }

            if( ( -epsilon < c ) && ( c < epsilon ) )
             {
              root[0] = scalar_name(0);
              root[1] = -b;

              if( root [ 1 ] < root[ 0 ] )
               {
                root[0] = root[1];
                root[0] = scalar_name(0);
               }
              return 2;
             }

            scalar_name d = b*b - scalar_name(4)*c;

            if( d < - epsilon )
             {
              root[1] =  root[0] = NAN;
              return 0;
             }

            if( d < epsilon )
             {
              root[0] = -b/(scalar_name(2));
              root[1] = root[0];
              return 1;
             }

            d = sqrt( d );

            root[0] = ( -b - d )/scalar_name(2);
            root[1] = ( -b + d )/scalar_name(2);

            return 2;
           }

         template
          <
            typename scalar_name
          > // C + B *x + 1 * x^2 = 0
          inline int monic( scalar_name root[2], scalar_name const C, scalar_name const B, scalar_name const& epsilon = 1e-6 )
           {
            scalar_name coefficinet[2]={ C, B };
            return ::math::polynomial::quadric::solve::monic( root, coefficinet, epsilon );
           }

        }
      }
    }
  }

#endif
