#ifndef Dh_DDMRM_math_LA_vector_extend_HPP_
 #define Dh_DDMRM_math_LA_vector_extend_HPP_

 // ::math::linear::vector::extend<dimension_left_number, scalar_name, dimension_right_number>

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< ::math::type::size_type dimension_left_number, typename scalar_name, ::math::type::size_type dimension_right_number  >
        ::math::linear::vector::structure<scalar_name,dimension_left_number>
        extend( ::math::linear::vector::structure<scalar_name,dimension_right_number> const& right, scalar_name const& fill = scalar_name( 0 ) )
         {
          ::math::linear::vector::structure<scalar_name,dimension_left_number> result;
          for( ::math::type::size_type index = 0; index < std::min( dimension_left_number, dimension_right_number ); ++index )
           {
            result[ index ] = right[ index ];
           }

          for( ::math::type::size_type index = dimension_right_number; index < dimension_left_number; ++index )
           {
            result[ index ] = fill;
           }

          return result;
         }

      }
    }
  }

#endif
