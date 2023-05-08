#ifndef Dh_math_linear_matrix_construct
 #define Dh_math_linear_matrix_construct

 // ::math::linear::matrix::construct<scalar_name,dimension_number,dimension_number>

#include <limits>

#include "./structure.hpp"
#include "./multiply.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        bool construct
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>        & targt2source
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>   const& target_system  //!< vectors are in columns
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>   const& source_system  //!< vectors are in columns
         )
         {
          ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> source_invert;

          if( false == ::math::linear::matrix::invert( source_invert, source_system ) )
           {
            return false;
           }

          ::math::linear::matrix::multiply( targt2source, target_system, source_invert );
          return true;
         }

      }
    }
  }

#endif
