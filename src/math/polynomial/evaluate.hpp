#ifndef Dh_DDMRM_math_polynomial_evaluate_HPP_
 #define Dh_DDMRM_math_polynomial_evaluate_HPP_

// math::polynomial::evaluate

 #include <array>
 #include <vector>

 #define math_polynomial_evaluate_linear(x,a0,a1) \
   ( (a0) +   (a1) * (x) )

 #define math_polynomial_evaluate_quadric(x,a0,a1,a2) \
   ( (a0) + ( (a1) + (a2) * (x)   )* (x) )

 #define math_polynomial_evaluate_cubic(x,a0,a1,a2,a3) \
  ( a0 + ( (a1) + ( (a2) + (a3) * (x) )* (x) ) * (x) )

 #define math_polynomial_evaluate_quartic(x,a0,a1,a2,a3,a4) \
 ( a0+ ( a1 + ( (a2) + ( (a3) + (a4) * (x) )* (x) ) * (x) ) * (x) )




 namespace math
  {
   namespace polynomial
    {

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, scalar_name const* coefficient, std::size_t const& size )
       {
        auto index = size-1;
        scalar_name result = coefficient[index];
        scalar_name t = scalar_name(paramter);

        while( 0 != index-- )
         {
          result = coefficient[index] + scalar_name(result) * t;
         }
        return result;
       }

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, std::vector<scalar_name> const& coefficient )
       {
        return ::math::polynomial::evaluate( paramter, coefficient.data(), coefficient.size() );
       }

     template
      <
        typename scalar_name
       ,unsigned  size_number
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, std::array<scalar_name,size_number> const& coefficient )
       {
        return ::math::polynomial::evaluate( paramter, coefficient.data(), size_number );
       }

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, std::array<scalar_name,2> const& coefficient )
       {
        scalar_name t = scalar_name(paramter);
        return coefficient[0] + t * coefficient[1] ;
       }

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, std::array<scalar_name,3> const& coefficient )
       {
        scalar_name t = scalar_name(paramter);
        return coefficient[0] + t * ( coefficient[1] + t*coefficient[2] );
       }

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
       scalar_name evaluate( parameter_name const& paramter, std::array<scalar_name,4> const& coefficient )
       {
        scalar_name t = scalar_name(paramter);
        return coefficient[0] + t * ( coefficient[1] + t*( coefficient[2] + t*coefficient[3] ) );
       }

     template
      <
        typename scalar_name
       ,typename parameter_name
      >
      scalar_name evaluate( parameter_name const& paramter, std::array<scalar_name,5> const& coefficient )
       {
        scalar_name t = scalar_name(paramter);
        return coefficient[0] + t * ( coefficient[1] + t*( coefficient[2] + t*( coefficient[3] + t*coefficient[4] ) ) );
       }

    }
  }

#endif
