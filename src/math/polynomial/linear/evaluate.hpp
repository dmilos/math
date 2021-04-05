#ifndef math_polynomial_linear_evaluate_HPP_
 #define math_polynomial_linear_evaluate_HPP_

 // ::math::polynomial::linear::evaluate<scalar_name>( t, coefficient )



 namespace math
  {
   namespace polynomial
    {
     namespace linear
      {

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t
          ,scalar_name    const  coefficient[2]
         )
         {
          return coefficient[0] + t * coefficient[1];
         }

      }
    }
  }

#endif
