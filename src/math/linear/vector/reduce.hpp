#ifndef Dh_DDMRM_math_LA_vector_reduce_HPP_
 #define Dh_DDMRM_math_LA_vector_reduce_HPP_

 // ::math::linear::vector::reduce<scalar_name,dimension_number>

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< ::math::type::size_type dimension_left_number, typename scalar_name, ::math::type::size_type dimension_right_number  >
        ::math::linear::vector::structure<scalar_name,dimension_left_number>
        reduce( ::math::linear::vector::structure<scalar_name,dimension_right_number> const& right )
         {
          ::math::linear::vector::structure<scalar_name,dimension_left_number> result;
          for( ::math::type::size_type index = 0; index < std::min( dimension_left_number, dimension_right_number ); ++index )
           {
            result[ index ] = right[ index ];
           }
          return result;
         }


       template< ::math::type::size_type dimension_left_number, typename scalar_name, ::math::type::size_type dimension_right_number  >
        ::math::linear::vector::structure<scalar_name,dimension_left_number> &
        reduce
         (
          ::math::linear::vector::structure<scalar_name,dimension_left_number>        & result
          ,::math::linear::vector::structure<scalar_name,dimension_right_number> const& right
         )
         {
          for( ::math::type::size_type index = 0; index < std::min( dimension_left_number, dimension_right_number ); ++index )
           {
            result[ index ] = right[ index ];
           }
          return result;
         }

      }
    }
  }

#endif
