#ifndef math_polynomial_quadric_evaluate_HPP_
 #define math_polynomial_quadric_evaluate_HPP_

 // ::math::polynomial::quadric::evaluate<scalar_name>( t, coefficient )



 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t
          ,scalar_name    const coefficient[4]
         )
         {
          return coefficient[0] + t * ( coefficient[1] + t* coefficient[2] );
         }

      }
    }
  }

#endif
