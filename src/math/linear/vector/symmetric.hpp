#ifndef math_library_linear_algebra__vector_symmetric_HPP_
 #define math_library_linear_algebra__vector_symmetric_HPP_

 // ::math::linear::vector::symmetric( result, point, bisectrix )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        symmetric
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& point_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& bisectrix_param
         )
         {
          using namespace ::math::linear::vector;
          result_param = - point_param + 2 * ::math::linear::vector::dot( point_param, bisectrix_param ) * bisectrix_param;
         }

       template< typename scalar_name >
        inline
        void
        symmetric
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& bisectrix_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = 2 * ::math::linear::vector::dot( point_param, bisectrix_param );
          result_param[0] = - point_param[0] + I_dot * bisectrix_param[0];
          result_param[1] = - point_param[1] + I_dot * bisectrix_param[1];
         }

       template< typename scalar_name >
        inline
        void
        symmetric
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& bisectrix_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = 2 * ::math::linear::vector::dot( point_param, bisectrix_param );
          result_param[0] = - point_param[0] + I_dot * bisectrix_param[0];
          result_param[1] = - point_param[1] + I_dot * bisectrix_param[1];
          result_param[2] = - point_param[2] + I_dot * bisectrix_param[2];
         }

       template< typename scalar_name >
        inline
        void
        symmetric
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& bisectrix_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = 2 * ::math::linear::vector::dot( point_param, bisectrix_param );
          result_param[0] = - point_param[0] + I_dot * bisectrix_param[0];
          result_param[1] = - point_param[1] + I_dot * bisectrix_param[1];
          result_param[2] = - point_param[2] + I_dot * bisectrix_param[2];
          result_param[3] = - point_param[3] + I_dot * bisectrix_param[3];
         }

      }
    }
  }

#endif
