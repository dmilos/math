#ifndef math_function_distribution_normal
#define math_function_distribution_normal

// ::math::function::distribution::normal
// ::math::function::distribution::normal_invert
// ::math::function::distribution::normal_PDF

#include <array>
#include "../../constants.hpp"


namespace math
 {
  namespace function
   {
    namespace distribution
     {

      template< typename scalar_name >
       inline scalar_name normal
        (
          scalar_name const& x
         ,scalar_name const& standard_deviation_param
         ,scalar_name const& mean_param
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name e  =  (x - mean_param)/standard_deviation_param;
                     e *= e;

         scalar_name e_coef  = standard_deviation_param * inv2sqrtPHI;

         scalar_name result    = exp( - e / scalar_name(2) ) / e_coef;

         return result;
        }

      template< typename scalar_name >
       inline scalar_name normal
        (
          scalar_name const& x
         ,scalar_name const& standard_deviation_param
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name e  =  x / standard_deviation_param;
                     e *= e;

         scalar_name e_coef  = standard_deviation_param * inv2sqrtPHI;

         scalar_name result    = exp( - e / scalar_name(2) ) / e_coef;

         return result;
        }

      template< typename scalar_name >
       inline scalar_name normal
        (
          scalar_name const& x
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name result = exp( - (x*x) / scalar_name(2) ) / inv2sqrtPHI;

         return result;
        }

      template< typename scalar_name >
       inline scalar_name normal_invert
        (
          scalar_name const& y
         ,scalar_name const& standard_deviation_param
         ,scalar_name const& mean_param = scalar_name(0)
        )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name x;
         x = y * standard_deviation_param * inv2sqrtPHI;
         x = - log( x ) * 2 * standard_deviation_param * standard_deviation_param;
         x = sqrt( x ) + mean_param;

         return x;
        }

      template< typename scalar_name >
       inline scalar_name normal_cumulative
        (
          scalar_name   x
         ,scalar_name const& standard_deviation_param = scalar_name(1)
        )
        { // TODO refernec here
         static scalar_name const a0 =  0.33267;
         static scalar_name const a1 =  0.4361836;
         static scalar_name const a2 = -0.1201676;
         static scalar_name const a3 =  0.9372980;

         bool sign = true;
         if( x < 0 )
          {
           sign = false;
           x = -x;
          }

         static scalar_name t0 = scalar_name(1)/( scalar_name(1) + a0*0);
         static scalar_name poly0 = t0*( a1 + t0*( a2 + t0*( a3 )));
         scalar_name phi0 = ::math::function::distribution::normal<scalar_name>(0,standard_deviation_param);

         scalar_name tX = scalar_name(1)/( scalar_name(1)+ a0*x);
         scalar_name polyX = tX*( a1 + tX*( a2 + tX*( a3 )));
         scalar_name phiX = ::math::function::distribution::normal<scalar_name>(x,standard_deviation_param);

         scalar_name resultX = scalar_name(1) - scalar_name(0.5)*( phiX * polyX )/( phi0 * poly0 );

         if( false == sign )
          {
           resultX = scalar_name(1) - resultX;
          }
         return resultX;
        }

      template< typename scalar_name >
       inline scalar_name normal_cumulative_ZS //!< Zelen & Severo
        (
          scalar_name   x
         ,scalar_name const& standard_deviation_param = scalar_name(1)
        )
        { // https://en.wikipedia.org/wiki/Normal_distribution#Numerical_approximations_for_the_normal_CDF
         static scalar_name const b0 =  0.2316419;
         static scalar_name const b1 =  0.319381530;
         static scalar_name const b2 = -0.356563782;
         static scalar_name const b3 =  1.781477937;
         static scalar_name const b4 = -1.821255978;
         static scalar_name const b5 =  1.330274429;

         bool sign = true;
         if( x < 0 )
          {
           sign = false;
           x = -x;
          }

         static scalar_name t0 = scalar_name(1)/( scalar_name(1) + b0 * 0 );
         static scalar_name poly0 = t0*( b1 + t0*( b2 + t0*( b3 + t0*( b4 + t0*b5))));
         scalar_name phi0 = ::math::function::distribution::normal<scalar_name>(0,standard_deviation_param);

         scalar_name tX    = scalar_name(1)/( scalar_name(1) + b0 * x );
         scalar_name polyX = tX*( b1 + tX*( b2 + tX*( b3 + tX*( b4 + tX*b5))));
         scalar_name phiX  = ::math::function::distribution::normal<scalar_name>(x,standard_deviation_param);

         scalar_name resultX = scalar_name(1) - scalar_name(0.5)*( phiX * polyX )/( phi0 * poly0 );

         if( false == sign )
          {
           resultX = scalar_name(1) - resultX;
          }

         return resultX;
        }

     }
   }
 }

#endif
