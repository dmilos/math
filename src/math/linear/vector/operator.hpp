#ifndef math_linear_operation_operation_HPP_
 #define math_linear_operation_operation_HPP_

// using namespace ::math::linear::vector



#include "./structure.hpp"

#include "./addition.hpp"
#include "./subtraction.hpp"
#include "./negate.hpp"
#include "./scale.hpp"

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name,dimension_number >
        operator+
         (
           ::math::linear::vector::structure< scalar_name,dimension_number> const& left_param
          ,::math::linear::vector::structure< scalar_name,dimension_number> const& right_param
         )
         {
          ::math::linear::vector::structure< scalar_name,dimension_number> Ir_result;
          ::math::linear::vector::addition( Ir_result, left_param, right_param );
          return Ir_result;
         }

        template< typename N_left, typename N_right, unsigned dimension_number >
        inline
        ::math::linear::vector::structure<N_left,dimension_number>&
        operator+=
        (
          ::math::linear::vector::structure<N_left,dimension_number>       & left_param,
          ::math::linear::vector::structure<N_right,dimension_number> const& right_param
        )
         {
          ::math::linear::vector::addition( left_param, right_param );
          return left_param;
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator-
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > Ir_result;
          ::math::linear::vector::subtraction( Ir_result, left_param, right_param );
          return Ir_result;
         }

        template< typename N_left, typename N_right, unsigned dimension_number >
        inline
        ::math::linear::vector::structure<N_left,dimension_number>&
        operator-=
         (
          ::math::linear::vector::structure<N_left,dimension_number> & left_param,
          ::math::linear::vector::structure<N_right,dimension_number> const& right_param
         )
         {
          ::math::linear::vector::subtraction( left_param, right_param );
          return left_param;
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator-
         (
          ::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > Ir_result;

          ::math::linear::vector::negate( Ir_result, right_param );

          return Ir_result;
         }

       /*
       template< typename scalar_name, unsigned dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator*
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          typedef ::math::linear::vector::structure< scalar_name, dimension_number > Tf_array;
          Tf_array Ir_result;

          typename Tf_array::T_size I_projection = dimension_number;
          while( I_projection-- )
           {
            Ir_result[I_projection] = left_param[I_projection] * right_param[I_projection];
           }
          return Ir_result;
         }
       */

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator *
         (
             value_name                                            const& value_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > Ir_result;
          ::math::linear::vector::scale( Ir_result, value_param, right_param );
          return Ir_result;
         }

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator*
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,value_name                                              const& value_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > Ir_result;
          ::math::linear::vector::scale( Ir_result, value_param, left_param );
          return Ir_result;
         }

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >&
        operator*=
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & left_param
          ,value_name                                    const         & value_param
         )
         {
          ::math::linear::vector::scale( left_param, value_param );
          return left_param;
         }

       /*
       template< typename scalar_name, unsigned dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator/
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          typedef ::math::linear::vector::structure< scalar_name, dimension_number > Tf_array;
          Tf_array Ir_result;
          typename Tf_array::T_size I_projection = dimension_number;
          scalar_name       *I_result = &Ir_result[0];
          scalar_name const *I_left   = &left_param[0];
          scalar_name const *I_right  = &right_param[0];
          while( I_projection-- )
           {
            *I_result = *I_left / *I_right;
            ++I_left; ++I_right; ++I_result;
           }

          return Ir_result;
         }
       */

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator/
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,value_name                                              const& P_scalar
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > Ir_result;

          ::math::linear::vector::scale( Ir_result, scalar_name(1)/P_scalar, left_param );

          return Ir_result;

         }

       /*
       template< typename scalar_name, unsigned dimension_number, typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        operator/
         (
           scalar_name                                                         const& P_scalar
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          typedef ::math::linear::vector::structure< scalar_name, dimension_number > Tf_array;
          Tf_array Ir_result;

          typename Tf_array::T_size I_projection = dimension_number;
          while( I_projection-- )
           {
            Ir_result[I_projection] = typename Tf_array::T_value( P_scalar / right_param[I_projection] );
           }
          return Ir_result;
         }
       */

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >&
        operator/=
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & left_param
          ,value_name                                              const& P_scalar
         )
         {
          ::math::linear::vector::scale( left_param, scalar_name(1)/P_scalar );
          return left_param;
         }

      }
    }
  }

#endif
