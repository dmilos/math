#ifndef math_library_linear_algebra__vector_reflect_HPP_
 #define math_library_linear_algebra__vector_reflect_HPP_
 
//::math::linear::vector::reflect( result, incident, normal )

#include "./structure.hpp"


 
 
 


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& incident
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& normal
         )
         {
          using namespace ::math::linear::vector;
          result_param = incident - scalar_name(2) * ::math::linear::vector::dot( incident, normal ) * normal;
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& incident
          ,::math::linear::vector::structure< scalar_name, 2 > const& normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( incident, normal );
          result_param[0] = incident[0] - scalar_name(2) * I_dot * normal[0];
          result_param[1] = incident[1] - scalar_name(2) * I_dot * normal[1];
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& incident
          ,::math::linear::vector::structure< scalar_name, 3 > const& normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( incident, normal );
          result_param[0] = incident[0] - scalar_name(2) * I_dot * normal[0];
          result_param[1] = incident[1] - scalar_name(2) * I_dot * normal[1];
          result_param[2] = incident[2] - scalar_name(2) * I_dot * normal[2];
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& incident
          ,::math::linear::vector::structure< scalar_name, 4 > const& normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( incident, normal );
          result_param[0] = incident[0] - scalar_name(2) * I_dot * normal[0];
          result_param[1] = incident[1] - scalar_name(2) * I_dot * normal[1];
          result_param[2] = incident[2] - scalar_name(2) * I_dot * normal[2];
          result_param[3] = incident[3] - scalar_name(2) * I_dot * normal[3];
         }

      }
    }
  }

#endif
