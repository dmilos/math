#ifndef math_polynomial_quadric_depressing_HPP_
 #define math_polynomial_quadric_depressing_HPP_

 // ::math::polynomial::quadric::depressing<scalar_name>( result, coefficient, epsilon = 1e-6 )


 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

       template
        <
          typename scalar_name
        >  // [0] + [1] *x + [2] * x^2 = 0
        scalar_name depressing( std::array<scalar_name,3> & result, std::array<scalar_name,3> const coefficient, scalar_name const& epsilon = 1e-6 )
         {
          scalar_name const& a= coefficient[2];
          scalar_name const& b= coefficient[1];
          scalar_name const& c= coefficient[0];

          scalar_name shift = NAN;
          if( (-epsilon < a ) &&( a < epsilon ) )
           {
            return shift;
           }
          shift = -b/( 2 * a );

          result[0] =  c + b * shift + shift * shift * a;
          result[1] =  0;
          result[2] =  a;
          return -shift ;
         }

      }
    }
  }

#endif
