#ifndef Dh_math_linear_matrix_gauss
 #define Dh_math_linear_matrix_gauss

 // ::math::linear::matrix::gauss<scalar_name,width_number,height_number>

#include "../vector/vector.hpp"
#include "./structure.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

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
          typedef ::math::type::size_type size_type;
          typedef scalar_name scalar_type;

          const ::math::type::size_type square = ( width_number<height_number ? width_number : height_number );
          ::math::linear::vector::structure< bool,( width_number<height_number ? width_number : height_number ) > flag{false};

          size_type rank = 0;

           bool have=true;
           while( true == have )
            {
             size_type best_i=0;
             size_type best_j=0;
             scalar_type best_C= input[best_i][best_j];

             have = false;
             for( size_type j=0; j < square; j++ )
              {
               if( true == flag[j] )
                {
                 continue;
                }
               for( size_type i=0; i < square; i++ )
                {
                 if( false == have )
                  {
                   best_C = input[j][i];
                   best_i = i;
                   best_j = j;
                   have = true;
                   continue;
                  }
                 if( fabs( best_C ) <= fabs( input[j][i] ) )
                  {
                   best_C = input[j][i];
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
                 std::swap( input[best_i][i], input[best_j][i] );
                }

               best_j = best_i;
              }

             flag[best_j] = true;
             rank++;

             for( size_type i=0; i < width_number; i++ )
              {
               input[best_j][i]  /= best_C;
              }

             for( size_type j=0; j < height_number; j++ )
              {
               if( best_j == j ) { continue; }
               scalar_type local = input[j][best_i];

               for( size_type i=0; i< width_number; i++ )
                {
                 input[j][i]  += - input[ best_j ][ i ]  * local;
                }
              }
            }

          return rank;
         }

      }
    }
  }

#endif
