#ifndef math_polynomial_cubic_evaluate_HPP_
 #define math_polynomial_cubic_evaluate_HPP_

 // ::math::polynomial::cubic::evaluate<scalar_name>( t, coefficient )



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
          return coefficient[0] + t * ( coefficient[1] + t*( coefficient[2] + t*coefficient[3] ) );;
         }

      }
    }
  }

#endif
