#ifndef math_polynomial_cubic_solve_general_HPP_
 #define math_polynomial_cubic_solve_general_HPP_

 // ::math::polynomial::cubic::solve::general<scalar_name>( result, coefficient, epsilon  )
 // ::math::polynomial::cubic::solve::general<scalar_name>( result, coefficient, epsilon  )

#include <cmath>
#include "./brian.hpp"





 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {
       namespace solve
        {

         template
          <
            typename scalar_name
          > 
          int general( scalar_name result[3], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
          {
           return ::math::polynomial::cubic::solve::brian<scalar_name>( result, coefficient, epsilon );   
          }

         template
          <
            typename scalar_name
          >
          int general( std::array<scalar_name,3> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
           {
            return ::math::polynomial::cubic::solve::brian<scalar_name>( result, coefficient, epsilon );
           }

        }
      }
    }
  }

#endif
