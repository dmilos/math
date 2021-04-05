#ifndef math_polynomial_quartic_evaluate_HPP_
 #define math_polynomial_quartic_evaluate_HPP_

 // ::math::polynomial::quartic::evaluate<scalar_name>( t, coefficient )



 namespace math
  {
   namespace polynomial
    {
     namespace quartic
      {

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t
          ,scalar_name    const coefficient[5]
         )
         {
          return coefficient[0] + t * ( coefficient[1] + t*( coefficient[2] + t*( coefficient[3] + t*coefficient[4] ) ) );
         }

      }
    }
  }

#endif
