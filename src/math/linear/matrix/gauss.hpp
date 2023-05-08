#ifndef Dh_math_linear_matrix_gauss
 #define Dh_math_linear_matrix_gauss

 // ::math::linear::matrix::gauss<scalar_name,width_number,height_number>

#include "../vector/vector.hpp"
#include "./structure.hpp"
#include "../../algorithm/index.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template
        <
          typename scalar_name
        >
        ::math::type::size_type gauss
         (
           scalar_name                   * input
          ,::math::type::size_type         width_number
          ,::math::type::size_type         height_number
          ,scalar_name              const& epsilon  = 1e-6
         )
         {
          typedef ::math::type::size_type size_type;
          typedef scalar_name scalar_type;
          typedef std::array< ::math::type::size_type, 2> size2d_type;

          size2d_type size2d{ width_number, height_number };
          ::math::type::size_type square_number = ( width_number < height_number ? width_number : height_number );
          std::vector<bool> flag( square_number, false ); //!< TODO alloc on stack not on heap

          size_type rank = 0;

           bool have=true;
           while( true == have )
            {
             size_type best_i=0;
             size_type best_j=0;
             auto index_bestI_bestJ = ::math::algorithm::index( size2d, size2d_type{best_i, best_j } );
             scalar_type best_C = input[ index_bestI_bestJ ];

             have = false;
             for( size_type j=0; j < square_number; j++ )
              {
               if( true == flag[j] )
                {
                 continue;
                }
               for( size_type i=0; i < square_number; i++ )
                {
                 auto ji_index = math::algorithm::index( size2d, size2d_type{ i, j } );
                 if( false == have )
                  {
                   best_C = input[ ji_index ];
                   best_i = i;
                   best_j = j;
                   have = true;
                   continue;
                  }
                 if( fabs( best_C ) <= fabs( input[ ji_index ] ) )
                  {
                   best_C = input[ ji_index ];
                   best_i = i;
                   best_j = j;
                   have = true;
                  }
                }
              }

             if( false == have )
              {
               break;
              }

             if( (- epsilon < best_C ) && ( best_C < epsilon ) )
              {
               break;
              }

             if( best_i != best_j )
              {
               for( size_type i=0; i< width_number; i++ )
                {
                 auto A_index = math::algorithm::index( size2d, size2d_type{ i, best_i } );
                 auto B_index = math::algorithm::index( size2d, size2d_type{ i, best_j } );

                 std::swap( input[ A_index ], input[ B_index ] );
                }

               best_j = best_i;
              }

             flag[best_j] = true;
             rank++;

             for( size_type i=0; i < width_number; i++ )
              {
               auto A_index = math::algorithm::index( size2d, size2d_type{ i, best_j } );
               input[ A_index ]  /= best_C;
              }

             for( size_type j=0; j < height_number; j++ )
              {
               if( best_j == j ) { continue; }
               scalar_type local = input[ math::algorithm::index( size2d, size2d_type{ best_i, j  } ) ];

               for( size_type i=0; i < width_number; i++ )
                {
                 auto ji_index   = math::algorithm::index( size2d, size2d_type{ i, j } );
                 auto best_index = math::algorithm::index( size2d, size2d_type{ i, best_j } );
                 input[ ji_index ]  += - input[ best_index ]  * local;
                }
              }
            }

          return rank;
         }

       template
        <
          typename scalar_name
         ,::math::type::size_type width_number
         ,::math::type::size_type height_number
        >
        ::math::type::size_type gauss
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & input
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          return ::math::linear::matrix::gauss<scalar_name>( input[0].data(), width_number, height_number, epsilon );
         }

       template
        <
          typename scalar_name
        >
        ::math::type::size_type gauss
         (
           ::math::linear::matrix::block<scalar_name>      & input
          ,::math::type::size_type                           width_number
          ,::math::type::size_type                           height_number
          ,scalar_name                                const& epsilon  = 1e-6
         )
         {
          return ::math::linear::matrix::gauss( input.data(), width_number, height_number, epsilon );
         }
      }
    }
  }

#endif
