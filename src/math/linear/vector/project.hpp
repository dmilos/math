#ifndef math_library_linear_algebra__vector_project_HPP_
 #define math_library_linear_algebra__vector_project_HPP_

 // ::math::linear::vector::project( result, point, normal )



#include "./structure.hpp"

 #include "./operator.hpp"



 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        project
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& point_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& normal_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( point_param, normal_param );
          result_param = point_param - I_dot * normal_param;
         }

       template< typename scalar_name >
        inline
        void
        project
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& normal_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( point_param, normal_param );
          result_param[0] = point_param[0] - I_dot * normal_param[0];
          result_param[1] = point_param[1] - I_dot * normal_param[1];
         }

       template< typename scalar_name >
        inline
        void
        project
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& normal_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( point_param, normal_param );
          result_param[0] = point_param[0] - I_dot * normal_param[0];
          result_param[1] = point_param[1] - I_dot * normal_param[1];
          result_param[2] = point_param[2] - I_dot * normal_param[2];
         }

       template< typename scalar_name >
        inline
        void
        project
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& point_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& normal_param
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( point_param, normal_param );
          result_param[0] = point_param[0] - I_dot * normal_param[0];
          result_param[1] = point_param[1] - I_dot * normal_param[1];
          result_param[2] = point_param[2] - I_dot * normal_param[2];
          result_param[3] = point_param[3] - I_dot * normal_param[3];
         }

      }
    }
  }

#endif


