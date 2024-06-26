#ifndef math_polynomial_cubic_evaluate_HPP_
 #define math_polynomial_cubic_evaluate_HPP_

 // ::math::polynomial::cubic::evaluate<scalar_name>( t, coefficient )
 // ::math::polynomial::cubic::evaluate<scalar_name>( t, 0, 1, 2, 3 )


 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t
          ,scalar_name const coefficient[4]
         )
         {
          return coefficient[0] + t* ( coefficient[1] + t*( coefficient[2] + t*coefficient[3] ) );
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
          ,scalar_name    const  coefficient_2
          ,scalar_name    const  coefficient_3
         )
         {
          return coefficient_0 + t*( coefficient_1 + t*( coefficient_2 + t*coefficient_3 ) );
         }

      }
    }
  }

#endif
