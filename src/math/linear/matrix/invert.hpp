#ifndef Dh_math_linear_matrix_invert
 #define Dh_math_linear_matrix_invert

 // ::math::linear::matrix::invert<scalar_name,dimension_number>

#include "../vector/vector.hpp"
#include "./structure.hpp"
#include "./one.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned dimension_number >
        bool invert
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      & result
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> const& m
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          typedef unsigned size_type;
          typedef scalar_name scalar_type;
          ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> tmp{ m };
          ::math::linear::vector::structure<bool,dimension_number> flag{false};
          //size_type count = 0;
          ::math::linear::matrix::one( result );

           bool have=true;
           while( true == have )
            {
             size_type best_i=0;
             size_type best_j=0;
             scalar_type best_C=tmp[best_i][best_j];

             have = false;
             for( size_type j=0; j < dimension_number; j++ )
              {
               if( true == flag[j] )
                {
                 continue;
                }
               for( size_type i=0; i < dimension_number; i++ )
                {
                 if( false == have )
                  {
                   best_C = tmp[j][i];
                   best_i = i;
                   best_j = j;
                   have = true;
                   continue;
                  }
                 if( fabs( best_C ) <= fabs( tmp[j][i] ) )
                  {
                   best_C = tmp[j][i];
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
               return false;
              }

             if( best_i != best_j )
              {
               for( size_type i=0; i< dimension_number; i++ )
                {
                 std::swap(    tmp[best_i][i],     tmp[best_j][i] );
                 std::swap( result[best_i][i],  result[best_j][i] );
                }

               best_j = best_i;
              }

             flag[best_j] = true;
             //count++;

             for( size_type i=0; i < dimension_number; i++ )
              {
                  tmp[best_j][i]  /= best_C;
               result[best_j][i]  /= best_C;
              }

             for( size_type j=0; j < dimension_number; j++ )
              {
               if( best_j == j ) { continue; }
               scalar_type local = tmp[j][best_i];

               for( size_type i=0; i< dimension_number; i++ )
                {
                    tmp[j][i]  += -    tmp[ best_j ][ i ]  * local;
                 result[j][i]  += - result[ best_j ][ i ]  * local;
                }
              }
            }

          return true;
         }

       template
        <
          typename scalar_name
        >
        bool invert
         (
           ::math::linear::matrix::structure<scalar_name,2,2>      & result
          ,::math::linear::matrix::structure<scalar_name,2,2> const& m
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          scalar_name d = m[0][0]*m[1][1] - m[1][0]*m[0][1];

          if( fabs( d ) < epsilon )
           {
            return false;
           }

          result[ 0 ][ 0 ] =   m[ 1 ][ 1 ]/ d; result[ 0 ][ 1 ] = - m[ 0 ][ 1 ]/ d;
          result[ 1 ][ 0 ] = - m[ 1 ][ 0 ]/ d; result[ 1 ][ 1 ] =   m[ 0 ][ 0 ]/ d;

          return true;
         }


       template
        <
          typename scalar_name
        >
        bool invert
         (
           ::math::linear::matrix::structure<scalar_name,3,3>      & result
          ,::math::linear::matrix::structure<scalar_name,3,3> const& m
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          scalar_name d, a00, a01, a02;

          a00 =  m[ 1 ][ 1 ] * m[ 2 ][ 2 ] -  m[ 1 ][ 2 ] * m[ 2 ][ 1 ];
          a01 =  m[ 1 ][ 0 ] * m[ 2 ][ 2 ]  - m[ 1 ][ 2 ] * m[ 2 ][ 0 ];
          a02 =  m[ 1 ][ 0 ] * m[ 2 ][ 1 ] -  m[ 1 ][ 1 ] * m[ 2 ][ 0 ];

          d =  m[ 0 ][ 0 ] * a00
             - m[ 0 ][ 1 ] * a01
             + m[ 0 ][ 2 ] * a02;

          if( fabs( d ) < epsilon )
           {
            return false;
           }

          result[ 0 ][ 0 ] = a00 / d;
          result[ 0 ][ 1 ] = ( m[ 0 ][ 2 ] * m[ 2 ][ 1 ] -  m[ 0 ][ 1 ] * m[ 2 ][ 2 ] ) / d;
          result[ 0 ][ 2 ] = ( m[ 0 ][ 1 ] * m[ 1 ][ 2 ] -  m[ 0 ][ 2 ] * m[ 1 ][ 1 ] ) / d;

          result[ 1 ][ 0 ] = -a01 / d;
          result[ 1 ][ 1 ] = ( m[ 0 ][ 0 ] * m[ 2 ][ 2 ] -  m[ 0 ][ 2 ] * m[ 2 ][ 0 ] ) / d;
          result[ 1 ][ 2 ] = ( m[ 0 ][ 2 ] * m[ 1 ][ 0 ] -  m[ 0 ][ 0 ] * m[ 1 ][ 2 ] ) / d;

          result[ 2 ][ 0 ] = a02 / d ;
          result[ 2 ][ 1 ] = ( m[ 0 ][ 1 ] * m[ 2 ][ 0 ] -  m[ 0 ][ 0 ] * m[ 2 ][ 1 ] ) / d;
          result[ 2 ][ 2 ] = ( m[ 0 ][ 0 ] * m[ 1 ][ 1 ] -  m[ 0 ][ 1 ] * m[ 1 ][ 0 ] ) / d;

          return true;
         }

       template
        <
          typename scalar_name
        >
        bool invert
         (
           ::math::linear::matrix::structure<scalar_name,4,4>      & result
          ,::math::linear::matrix::structure<scalar_name,4,4> const& left
          ,scalar_name const& epsilon = 1e-6
         )
         {
          auto s0 = left[ 0 ][ 0 ] * left[ 1 ][ 1 ] - left[ 1 ][ 0 ] * left[ 0 ][ 1 ];
          auto s1 = left[ 0 ][ 0 ] * left[ 1 ][ 2 ] - left[ 1 ][ 0 ] * left[ 0 ][ 2 ];
          auto s2 = left[ 0 ][ 0 ] * left[ 1 ][ 3 ] - left[ 1 ][ 0 ] * left[ 0 ][ 3 ];
          auto s3 = left[ 0 ][ 1 ] * left[ 1 ][ 2 ] - left[ 1 ][ 1 ] * left[ 0 ][ 2 ];
          auto s4 = left[ 0 ][ 1 ] * left[ 1 ][ 3 ] - left[ 1 ][ 1 ] * left[ 0 ][ 3 ];
          auto s5 = left[ 0 ][ 2 ] * left[ 1 ][ 3 ] - left[ 1 ][ 2 ] * left[ 0 ][ 3 ];

          auto c5 = left[ 2 ][ 2 ] * left[ 3 ][ 3 ] - left[ 3 ][ 2 ] * left[ 2 ][ 3 ];
          auto c4 = left[ 2 ][ 1 ] * left[ 3 ][ 3 ] - left[ 3 ][ 1 ] * left[ 2 ][ 3 ];
          auto c3 = left[ 2 ][ 1 ] * left[ 3 ][ 2 ] - left[ 3 ][ 1 ] * left[ 2 ][ 2 ];
          auto c2 = left[ 2 ][ 0 ] * left[ 3 ][ 3 ] - left[ 3 ][ 0 ] * left[ 2 ][ 3 ];
          auto c1 = left[ 2 ][ 0 ] * left[ 3 ][ 2 ] - left[ 3 ][ 0 ] * left[ 2 ][ 2 ];
          auto c0 = left[ 2 ][ 0 ] * left[ 3 ][ 1 ] - left[ 3 ][ 0 ] * left[ 2 ][ 1 ];

          auto d = (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);

          if( fabs( d ) < epsilon )
           {
            return false;
           }

          result[0 ][ 0] = ( left[1 ][ 1] * c5 - left[1 ][ 2] * c4 + left[1 ][ 3] * c3) / d;
          result[0 ][ 1] = (-left[0 ][ 1] * c5 + left[0 ][ 2] * c4 - left[0 ][ 3] * c3) / d;
          result[0 ][ 2] = ( left[3 ][ 1] * s5 - left[3 ][ 2] * s4 + left[3 ][ 3] * s3) / d;
          result[0 ][ 3] = (-left[2 ][ 1] * s5 + left[2 ][ 2] * s4 - left[2 ][ 3] * s3) / d;

          result[1 ][ 0] = (-left[1 ][ 0] * c5 + left[1 ][ 2] * c2 - left[1 ][ 3] * c1) / d;
          result[1 ][ 1] = ( left[0 ][ 0] * c5 - left[0 ][ 2] * c2 + left[0 ][ 3] * c1) / d;
          result[1 ][ 2] = (-left[3 ][ 0] * s5 + left[3 ][ 2] * s2 - left[3 ][ 3] * s1) / d;
          result[1 ][ 3] = ( left[2 ][ 0] * s5 - left[2 ][ 2] * s2 + left[2 ][ 3] * s1) / d;

          result[2 ][ 0] = ( left[1 ][ 0] * c4 - left[1 ][ 1] * c2 + left[1 ][ 3] * c0) / d;
          result[2 ][ 1] = (-left[0 ][ 0] * c4 + left[0 ][ 1] * c2 - left[0 ][ 3] * c0) / d;
          result[2 ][ 2] = ( left[3 ][ 0] * s4 - left[3 ][ 1] * s2 + left[3 ][ 3] * s0) / d;
          result[2 ][ 3] = (-left[2 ][ 0] * s4 + left[2 ][ 1] * s2 - left[2 ][ 3] * s0) / d;

          result[3 ][ 0] = (-left[1 ][ 0] * c3 + left[1 ][ 1] * c1 - left[1 ][ 2] * c0) / d;
          result[3 ][ 1] = ( left[0 ][ 0] * c3 - left[0 ][ 1] * c1 + left[0 ][ 2] * c0) / d;
          result[3 ][ 2] = (-left[3 ][ 0] * s3 + left[3 ][ 1] * s1 - left[3 ][ 2] * s0) / d;
          result[3 ][ 3] = ( left[2 ][ 0] * s3 - left[2 ][ 1] * s1 + left[2 ][ 2] * s0) / d;

          return true;
         }

      }
    }
  }

#endif
