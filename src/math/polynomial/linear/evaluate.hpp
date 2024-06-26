#ifndef math_polynomial_linear_evaluate_HPP_
 #define math_polynomial_linear_evaluate_HPP_

 // ::math::polynomial::linear::evaluate<scalar_name>( t, coefficient )
 // ::math::polynomial::linear::evaluate<scalar_name>( t, 0, 1 )


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

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t
          ,scalar_name    const  coefficient_0
          ,scalar_name    const  coefficient_1
         )
         {
          return coefficient_0 + t * coefficient_1;
         }

      }
    }
  }

#endif
