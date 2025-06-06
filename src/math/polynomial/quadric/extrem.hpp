#ifndef math_polynomial_quadric_extrem_HPP_
 #define math_polynomial_quadric_extrem_HPP_

 // ::math::polynomial::quadric::extrem<scalar_name>( result, coefficient, epsilon = 1e-6 )


 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

       template
        <
          typename scalar_name
        >  //! [0] + [1] *x + [2] * x^2 = 0, minimum or maximum depend of sign of A = a[2]
        scalar_name extrem( std::array<scalar_name,3> & result, std::array<scalar_name,3> const coefficient, scalar_name const& epsilon = 1e-6 )
         {
          scalar_name const& a = coefficient[2];
          scalar_name const& b = coefficient[1];
          scalar_name const& c = coefficient[0];

          scalar_name result = NAN;
          if( ( -epsilon < a ) &&( a < epsilon ) )
           {
            return result;
           }
          result = - b / ( scalar_name(2) * a );

          return result ;
         }

      }
    }
  }

#endif
