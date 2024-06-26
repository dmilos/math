#ifndef math_polynomial_quadric_evaluate_HPP_
 #define math_polynomial_quadric_evaluate_HPP_

 // ::math::polynomial::quadric::evaluate<scalar_name>( t, coefficient )
 // ::math::polynomial::quadric::evaluate<scalar_name>( t, 0, 1, 2 )


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
          ,scalar_name    const coefficient[3]
         )
         {
          return coefficient[0] + t * ( coefficient[1] + t* coefficient[2] );
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
         )
         {
          return coefficient_0 + t * ( coefficient_1 + t * coefficient_2 );
         }

      }
    }
  }

#endif
