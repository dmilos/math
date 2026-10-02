#ifndef math_polynomial_quartic_construct4_HPP_
 #define math_polynomial_quartic_construct4_HPP_

 // ::math::polynomial::quartic::construct<scalar_name>( result, zero )

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace quartic
      {

       template
        <
          typename scalar_name
        >
        void construct( std::array<scalar_name,5> & result, std::array<scalar_name,4> const& zero )
         {
          auto & A  = result[4];
          auto & B  = result[3];
          auto & C  = result[2];
          auto & D  = result[1];
          auto & E  = result[0];

          A = scalar_name(1);
          B = -( zero[0] + zero[1] + zero[2]+ zero[3] );

          C =    zero[0] * zero[1]
               + zero[0] * zero[2]
               + zero[0] * zero[3]

               + zero[1] * zero[2]
               + zero[1] * zero[3]

               + zero[2] * zero[3]
              ;

          D = -(   zero[0] * zero[1]* zero[2]
                 + zero[0] * zero[1]* zero[3]
                 + zero[0] * zero[2]* zero[3]
                 + zero[1] * zero[2]* zero[3]
          );
          E = -( zero[0] * zero[1]* zero[2] * zero[3] );
         }

      }
    }
  }

#endif
