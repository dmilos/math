#ifndef math_library_linear_algebra__vector_aritmetic_assign_HPP_
 #define math_library_linear_algebra__vector_aritmetic_assign_HPP_

 // ::math::linear::vector::assign( result, left )
 

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, typename scalar2_name, unsigned dimension_number>
        inline
        void
        assign
         (
           ::math::linear::vector::structure< scalar_name,  dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar2_name, dimension_number > const& left_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_right  = left_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_right;
             *I_result =  scalar_name( *I_right );
           }
         }

       template< typename scalar_name, typename scalar2_name, unsigned dimension_number>
        inline
        void
        assign
         (
           ::math::linear::vector::structure< scalar_name,  2 >      & result_param
          ,::math::linear::vector::structure< scalar2_name, 2 > const& left_param
         )
         {
          result_param[0] = scalar_name( left_param[0] );
          result_param[1] = scalar_name( left_param[1] );
         }

       template< typename scalar_name, typename scalar2_name, unsigned dimension_number>
        inline
        void
        assign
         (
           ::math::linear::vector::structure< scalar_name,  3 >      & result_param
          ,::math::linear::vector::structure< scalar2_name, 3 > const& left_param
         )
         {
          result_param[0] = scalar_name( left_param[0] );
          result_param[1] = scalar_name( left_param[1] );
          result_param[2] = scalar_name( left_param[2] );
         }

       template< typename scalar_name, typename scalar2_name, unsigned dimension_number>
        inline
        void
        assign
         (
           ::math::linear::vector::structure< scalar_name,  4 >      & result_param
          ,::math::linear::vector::structure< scalar2_name, 4 > const& left_param
         )
         {
          result_param[0] = scalar_name( left_param[0] );
          result_param[1] = scalar_name( left_param[1] );
          result_param[2] = scalar_name( left_param[2] );
          result_param[3] = scalar_name( left_param[3] );
         }

     }
   }
 }

#endif