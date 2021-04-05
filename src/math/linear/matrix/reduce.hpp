#ifndef Dh_math_linear_matrix_reduce
 #define Dh_math_linear_matrix_reduce

 // ::math::linear::matrix::reduce<scalar_name,width_number,height_number>( m );

#include "./structure.hpp"
#include "../vector/structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        unsigned
        reduce
         (
          ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m
          ,scalar_name const& epsilon = 1e-9
         )
         { // preserve row position( do not swap). do not rescale row.
          typedef unsigned size_type;
          typedef scalar_name scalar_type;
          size_type rank = 0;
          ::math::linear::vector::structure<bool,height_number> used{ false };

           bool have=true;
           while( true == have )
            {
             size_type best_i=0;
             size_type best_j=0;
             scalar_type best_C=m[best_i][best_j];

             have = false;
             for( size_type j=0; j < height_number; j++ )
              {
               if( true == used[j] )
                {
                 continue;
                }
               for( size_type i=0; i < width_number; i++ )
                {
                 if( false == have )
                  {
                   best_C = m[j][i];
                   best_i = i;
                   best_j = j;
                   have = true;
                   continue;
                  }
                 if( fabs( best_C ) <= fabs( m[j][i] ) )
                  {
                   best_C = m[j][i];
                   best_i = i;
                   best_j = j;
                   have = true;
                   continue;
                  }
                }
              }

             if( false == have )
              {
               break;
              }

             if( (- epsilon < best_C ) && ( best_C < epsilon ) )
              {
               return rank;
              }

             used[best_j] = true;
             rank ++;

             for( size_type j=0; j < height_number; j++ )
              {
               if( best_j == j ) { continue; }

               scalar_type coefficient = - m[j][best_i] / best_C;

               for( size_type i=0; i< width_number; i++ )
                {
                 m[j][i]  += m[ best_j ][ i ]  * coefficient;
                }
              }
            }
          return rank;
         }

      }
    }
  }

#endif
