#ifndef math_polynomial_solve_linear_HPP_
 #define math_polynomial_solve_linear_HPP_

 // ::math::polynomial::solve::linear<scalar_name>( zero, coefficient, epsilon = 1e-6 )

 #define math_polynomial_solve_linear(_b,_a,_t2) ((not_epsilon(_a)?(_t2=-(_b)/(_a),1):0))


 namespace math
  {
   namespace polynomial
    {
     namespace solve
      {
       // namespace linear {

       template
        <
          typename scalar_name
        >
        inline unsigned linear( scalar_name root[1], scalar_name const coefficient[2], scalar_name const& epsilon = 1e-6 )
        {
         if( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
          {
           root[0] = NAN;
           return 0;
          }
         root[0] = -coefficient[0]/coefficient[1];

         return 1;
        }

       template
        <
          typename scalar_name
        >
        inline unsigned linear( std::array<scalar_name,1> & zero, std::array<scalar_name,2> const & coefficient, scalar_name const& epsilon = 1e-6 )
         {
          return ::math::polynomial::solve::linear( zero.data(),  coefficient.data(), epsilon );
         }

       // }

      }
    }
  }

#endif
