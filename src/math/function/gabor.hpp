#ifndef math_function_gabor2D
#define math_function_gabor2D

 // ::math::function::gabor2D( {x,y} )
 // ::math::function::gabor<double,1>()( x )

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
             ,this->m_standard_deviation
             ,this->m_frequency
             ,this->m_phase_shift
             ,this->m_gamma
           );
          }

       public:
         scalar_type real(      point_type const& point_param )const { return 0; }
         scalar_type imaginary( point_type const& point_param )const { return 0; }

       public:
         scalar_type m_angle               = 0;
         scalar_type m_standard_deviation  = math::constants::PHI_invSQRT2;
         scalar_type m_frequency           = 0.5;
         scalar_type m_phase_shift         = math::constants::PHI/2;
         point_type  m_gamma   {1,1};
       public:
         static scalar_type calc
          (
            point_type  const&point
           ,scalar_type const& angle_param
           ,scalar_type const& standard_deviation_param
           ,scalar_type const& frequency_param
           ,scalar_type const& phase_shift_param
           ,point_type  const& gamma_param
           )
          {
           scalar_type const & pi2 = math::constants::PHI_two;

           point_type  local;
           ::math::linear::vector::rotate( local, -angle_param, point );

           scalar_type const & x = local[0];
           scalar_type const & y = local[1];

           scalar_type vawe = cos( ( pi2 * frequency_param) * x  + phase_shift_param );

           scalar_type e ; // = ::math::function::distribution::normal( sqrt(gx + gy), standard_deviation_param );;
           {
            scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;
            scalar_type gx = x * gamma_param[0]; gx *= gx;
            scalar_type gy = y * gamma_param[1]; gy *= gy;
            scalar_type v = (gx + gy)/( 2 * standard_deviation_param * standard_deviation_param );
            e = exp( - v );
            e *= inv2sqrtPHI/standard_deviation_param;
           }

           scalar_type result = e * vawe;
           return result;
          }
      };

     template< typename scalar_name, ::math::type::size_type dimension_number >
      class gabor
       {
        public:
          typedef scalar_name scalar_type;
          typedef scalar_name result_type;
          typedef scalar_name argument_type;

        public:
          static scalar_type process
           (
             argument_type  const& argument_param
            ,scalar_type    const& standard_deviation_param
            ,scalar_type    const& frequency_param
            ,scalar_type    const& phase_shift_param
            ,argument_type  const& gamma_param
           )
           {
            scalar_type vawe;
            {
             scalar_type const & pi2 = math::constants::PHI_two;
             scalar_type const & x = argument_param[0];

             vawe = cos( ( pi2 * frequency_param) * x  + phase_shift_param );
            }

            scalar_type gauss; // = ::math::function::distribution::normal( sqrt(gx + gy), standard_deviation_param );;
            {
             scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

             argument_type local;
             ::math::linear::vector::scale( local, gamma_param, argument_param );
             scalar_type length2 = ::math::linear::vector::dot( local, local );

             scalar_type power = scalar_type( -0.5 ) * length2/( standard_deviation_param * standard_deviation_param );
             scalar_name coefficient = standard_deviation_param * inv2sqrtPHI;
             gauss = exp( power ) / coefficient;
            }

            scalar_type result = gauss * vawe;
            return result;
           }

       };

     template< typename scalar_name >
      class gabor< scalar_name, 1 >
       {
        public:
          typedef scalar_name scalar_type;
          typedef scalar_name result_type;
          typedef scalar_name argument_type;

       public:
        gabor()
         {
          this->m_standard_deviation  = math::constants::PHI_invSQRT2;
          this->m_frequency           = 0.5;
          this->m_phase_shift         = math::constants::PHI_half;
         }
        gabor
         (
           scalar_type const& standard_deviation_param
          ,scalar_type const& frequency_param
          ,scalar_type const& phase_shift_param 
         )
         {
          this->m_standard_deviation = standard_deviation_param;
          this->m_frequency          = frequency_param;
          this->m_phase_shift        = phase_shift_param;
         }
       public:
         scalar_type m_standard_deviation;
         scalar_type m_frequency         ;
         scalar_type m_phase_shift       ;
       public:
         scalar_type operator( ) ( argument_type const& argument_param )const
          {
           return this->process(
              argument_param
             ,this->m_standard_deviation
             ,this->m_frequency
             ,this->m_phase_shift
           );
          }

        public:
          static scalar_type process
           (
             argument_type  const& argument_param
            ,scalar_type    const& standard_deviation_param
            ,scalar_type    const& frequency_param
            ,argument_type  const& phase_shift_param
            )
           {
            scalar_type const & pi2 = math::constants::PHI_two;

            scalar_type vawe = cos( ( pi2 * frequency_param ) * argument_param + phase_shift_param );

            scalar_type gauss = ::math::function::distribution::normal( argument_param, standard_deviation_param );

            scalar_type result = vawe * gauss;
            return result;
           }
       };

   }
 }

#endif



