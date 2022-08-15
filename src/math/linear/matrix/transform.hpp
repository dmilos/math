#ifndef Dh_math_linear_matrix_transform
 #define Dh_math_linear_matrix_transform

// ::math::linear::matrix::transform<scalar_name,width_number,height_number>

#include "./structure.hpp"
#include "../vector/vector.hpp"




 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,height_number>                   & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& left
          ,::math::linear::vector::structure<scalar_name,width_number>               const& right
         )
         {
          for( ::math::type::size_type i=0; i< height_number; ++i )
           {
            result[i]=0;
            for( ::math::type::size_type j=0; j < width_number; ++j )
             {
              result[i] += left[i][j] * right[j];
             }
           }
         }

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,width_number>                    & result
          ,::math::linear::vector::structure<scalar_name,height_number>              const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& right
         )
         {
          for( ::math::type::size_type i=0; i< width_number; ++i )
           {
            result[i]=0;
            for( ::math::type::size_type j=0; j < height_number; ++j )
             {
              result[i] += left[j] * right[j][i];
             }
           }
         }


      }
    }
  }

#endif
