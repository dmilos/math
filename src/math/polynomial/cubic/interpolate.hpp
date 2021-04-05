#ifndef math_polynomial_interpolate_cubic_HPP_
 #define math_polynomial_interpolate_cubic_HPP_

 // ::math::polynomial::solve::cubic<scalar_name>( coefficient, x, y )



 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate
         (
           scalar_name coefficient[4]
          ,scalar_name const& x0, scalar_name const& y0
          ,scalar_name const& x1, scalar_name const& y1
          ,scalar_name const& x2, scalar_name const& y2
          ,scalar_name const& x3, scalar_name const& y3
          ,scalar_name const& epsilon = 1e-12
         )
         {
          scalar_name f0 = y0 /( x0 - x1 ) /( x0 - x2 )/(x0- x3 );
          scalar_name f1 = y1 /( x1 - x0 ) /( x1 - x2 )/(x1- x3 );
          scalar_name f2 = y2 /( x2 - x0 ) /( x2 - x1 )/(x2- x3 );
          scalar_name f3 = y3 /( x3 - x0 ) /( x3 - x1 )/(x3- x2 );

          scalar_name a0 = f0;
          scalar_name b0 = f0*( -( x1 + x2 + x3 ) );
          scalar_name c0 = f0*( x1*x2 + x1*x3  + x2*x3 );
          scalar_name d0 = f0*( -( x1*x2*x3 ) );

          scalar_name a1 = f1;
          scalar_name b1 = f1*( -( x0 + x2 + x3 ) );
          scalar_name c1 = f1*( x0*x2 + x0*x3  + x2*x3 );
          scalar_name d1 = f1*( -( x0 * x2 * x3 ) );

          scalar_name a2 = f2;
          scalar_name b2 = f2*( -( x0 + x1 + x3 ) );
          scalar_name c2 = f2*(x0*x1 + x0*x3  + x1*x3 );
          scalar_name d2 = f2*( - ( x0 * x1 * x3  ) );

          scalar_name a3 = f3;
          scalar_name b3 = f3*( -( x0 + x1 + x2 ) );
          scalar_name c3 = f3*(x0*x1 + x0*x2  + x1*x2 );
          scalar_name d3 = f3*( - ( x0 * x1 * x2  ) );

          coefficient[ 3 ] = a0 + a1 + a2 + a3;
          coefficient[ 2 ] = b0 + b1 + b2 + b3;
          coefficient[ 1 ] = c0 + c1 + c2 + c3;
          coefficient[ 0 ] = d0 + d1 + d2 + d3;
          return true;
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( scalar_name coefficient[4], std::array< std::array< scalar_name, 2> , 4 > const& cloud, scalar_name const& epsilon = 1e-12 )
         {
          return ::math::polynomial::cubic::interpolate( coefficient, cloud[0][0], cloud[0][1]
                                                                     , cloud[1][0], cloud[1][1]
                                                                     , cloud[2][0], cloud[2][1]
                                                                     , cloud[3][0], cloud[3][1], epsilon );
         }

      }
    }
  }

#endif
