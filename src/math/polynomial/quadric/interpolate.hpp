#ifndef math_polynomial_quadric_interpolate_HPP_
 #define math_polynomial_quadric_interpolate_HPP_

 // ::math::polynomial::quadric::interpolate<scalar_name>( coefficient, x, y )



 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

       template
        <
          typename scalar_name
        >
        inline bool interpolate
         (
           scalar_name coefficient[3]
          ,scalar_name const& x0, scalar_name const& y0
          ,scalar_name const& x1, scalar_name const& y1
          ,scalar_name const& x2, scalar_name const& y2
          ,scalar_name const& epsilon = 1e-12
         )
         {
          if( fabs( x0 - x1 ) < epsilon) return false;
          if( fabs( x0 - x2 ) < epsilon) return false;
          if( fabs( x1 - x2 ) < epsilon) return false;

          scalar_name f0 = y0 /( x0 - x1 ) /( x0 - x2 ); //!< TODO move this UP
          scalar_name f1 = y1 /( x1 - x0 ) /( x1 - x2 ); //!< TODO move this UP
          scalar_name f2 = y2 /( x2 - x0 ) /( x2 - x1 ); //!< TODO move this UP

          scalar_name a0 = f0;
          scalar_name b0 = f0*( -( x1 + x2 ) );
          scalar_name c0 = f0*( x1*x2 );

          scalar_name a1 = f1;
          scalar_name b1 = f1*( -( x0 + x2 ) );
          scalar_name c1 = f1*( x0*x2 );

          scalar_name a2 = f2;
          scalar_name b2 = f2*( -( x0 + x1 ) );
          scalar_name c2 = f2*( x0*x1 );

          coefficient[ 2 ] = a0 + a1 + a2;
          coefficient[ 1 ] = b0 + b1 + b2;
          coefficient[ 0 ] = c0 + c1 + c2;
          return true;
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate
         (
            scalar_name                                          coefficient[3]
          , std::array< std::array< scalar_name, 2> , 3 > const& cloud
          , scalar_name                                   const& epsilon = 1e-12
         )
         {
          return ::math::polynomial::quadric::interpolate( coefficient, cloud[0][0], cloud[0][1]
                                                                     , cloud[1][0], cloud[1][1]
                                                                     , cloud[2][0], cloud[2][1], epsilon );
         }

      }
    }
  }

#endif
