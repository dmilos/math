#ifndef math_function_gabor2D
#define math_function_gabor2D

 // ::math::function::gabor2D

#include <array>

#include "../linear/vector/rotate.hpp"
#include "../constants.hpp"
#include "./distribution/normal.hpp"


namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     class gabor2D
      {
       public:
         typedef  scalar_name scalar_type;
         typedef  std::array< scalar_name, 2 > point_type;

       public:
         explicit gabor2D ( scalar_type const& angle = 0 ):m_angle(angle){}

       public:
         scalar_type operator( ) ( point_type const& point_param )const
          {
           return this->calc(
             point_param
             ,this->m_angle
             ,this->m_frequency
             ,this->m_phase_shift
             ,this->m_standard_deviation
             ,this->m_gamma
           );
          }

       public:
         scalar_type real(      point_type const& point_param )const { return 0; }
         scalar_type imaginary( point_type const& point_param )const { return 0; }

       public:
         scalar_type m_angle               = 0;
         scalar_type m_frequency           = scalar_name(2) *  math::constants::PHI/5;
         scalar_type m_phase_shift         = math::constants::PHI/2;
         scalar_type m_standard_deviation  = 0.32125;
         point_type  m_gamma   {1,1};
       public:
         static scalar_type calc
          (
            point_type  const&point
           ,scalar_type const& angle_param
           ,scalar_type const& frequency_param
           ,scalar_type const& phase_shift_param
           ,scalar_type const& standard_deviation_param
           ,point_type  const& gamma_param
           )
          {
           scalar_type const & pi = math::constants::PHI;

           point_type  local;
           ::math::linear::vector::rotate( local, -angle_param, point );

           scalar_type const & x = local[0];
           scalar_type const & y = local[1];

           scalar_type vawe = cos( x * ( scalar_type(2) * pi / frequency_param)  + phase_shift_param );

           scalar_type gx = x * gamma_param[0]; gx *= gx;
           scalar_type gy = y * gamma_param[1]; gy *= gy;

           scalar_type v =(gx + gy)/( 2 * standard_deviation_param * standard_deviation_param );

           scalar_type e = exp( - v );

           scalar_type result = e * vawe;
           return result;
          }
      };

   }
 }

#endif



