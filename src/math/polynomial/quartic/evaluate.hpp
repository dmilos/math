#ifndef math_polynomial_quartic_evaluate_HPP_
 #define math_polynomial_quartic_evaluate_HPP_

// ::math::polynomial::quartic::evaluate<scalar_name>( t, coefficient )
// ::math::polynomial::quadric::evaluate<scalar_name>( t, 0, 1, 2, 3, 4 )


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
          ,scalar_name    const  coefficient_4
         )
         {
          return coefficient_0 + t * ( coefficient_1 + t*( coefficient_2 + t*( coefficient_3 + t*coefficient_4 ) ) );
         }

       template
        <
          typename parameter_name
         ,typename scalar_name
        >
        inline scalar_name evaluate
         (
           parameter_name const& t, std::array< scalar_name, 5 >  const& coefficient
         )
         {
          return ::math::polynomial::quartic::evaluate<scalar_name>( t, coefficient.data() );
         }

      }
    }
  }

#endif
