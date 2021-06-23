#ifndef Dh_math_linear_affine_construct
 #define Dh_math_linear_affine_construct

 // ::math::linear::affine::construct<scalar_name,dimension_number>( result, target, source )
 // ::math::linear::affine::construct<scalar_name,dimension_number>( result, target, source )
 // ::math::linear::affine::construct<scalar_name,dimension_number>( result, target, source )
 // ::math::linear::affine::construct<scalar_name,dimension_number>( result, target, source )

#include "./transform.hpp"
#include "./structure.hpp"
#include "./system.hpp"
#include "./invert.hpp"
#include "./compose.hpp"




 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& target_param
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& source_param
         )
         { // point t,s; target( t ) = source( s ); t = target^-1( source( s ) );
          ::math::linear::affine::structure<scalar_name,dimension_number> target_invert;
          if( false == ::math::linear::affine::invert<scalar_name,dimension_number>( target_invert, target_param ) )
           {
            return false;
           }

          ::math::linear::affine::compose<scalar_name,dimension_number>( result, target_invert, source_param );
          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,2>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,2>, 3 > const& target
         )
         { // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,2> x, y;

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::affine::system( result, target[0], x, y );

          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,2>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,2>, 3 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,2>, 3 > const& source
         )
         {  // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,2> x, y;
          ::math::linear::affine::structure<scalar_name,2> fs, tt;

          ::math::linear::vector::subtraction( x, source[1], source[0] );
          ::math::linear::vector::subtraction( y, source[2], source[0] );
          ::math::linear::affine::system( tt, source[0], x, y );
          if( false == ::math::linear::affine::invert( fs, tt ) )
           {
            return false;
           }

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::affine::system( tt, target[0], x, y );

          ::math::linear::affine::compose( result, tt, fs );
          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,3>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 4 > const& target
         )
         { // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,3> x, y, z;

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::vector::subtraction( z, target[3], target[0] );
          ::math::linear::affine::system( result, target[0], x, y, z );

          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,3>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 4 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 4 > const& source
         )
         { // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,3> x, y, z;
          ::math::linear::affine::structure<scalar_name,3> fs, tt;

          ::math::linear::vector::subtraction( x, source[1], source[0] );
          ::math::linear::vector::subtraction( y, source[2], source[0] );
          ::math::linear::vector::subtraction( z, source[3], source[0] );
          ::math::linear::affine::system( tt, source[0], x, y, z );
          if( false == ::math::linear::affine::invert( fs, tt ) )
           {
            return false;
           }

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::vector::subtraction( z, target[3], target[0] );
          ::math::linear::affine::system( tt, target[0], x, y, z );

          ::math::linear::affine::compose( result, tt, fs );
          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,4>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,4>, 5 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,4>, 5 > const& source
         )
         { // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,4> x, y, z, t;
          ::math::linear::affine::structure<scalar_name,4> fs, tt;

          ::math::linear::vector::subtraction( x, source[1], source[0] );
          ::math::linear::vector::subtraction( y, source[2], source[0] );
          ::math::linear::vector::subtraction( z, source[3], source[0] );
          ::math::linear::vector::subtraction( t, source[4], source[0] );
          ::math::linear::affine::system( tt, source[0], x, y, z, t );
          if( false == ::math::linear::affine::invert( fs, tt ) )
           {
            return false;
           }

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::vector::subtraction( z, target[3], target[0] );
          ::math::linear::vector::subtraction( t, target[4], target[0] );
          ::math::linear::affine::system( tt, target[0], x, y, z, t );

          ::math::linear::affine::compose( result, tt, fs );
          return true;
         }

       template< typename scalar_name >
        bool construct
         (
           ::math::linear::affine::structure<scalar_name,4>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,4>, 5 > const& target
         )
         { // target[i] = result( source[i] )
          ::math::linear::vector::vector<scalar_name,4> x, y, z, t;

          ::math::linear::vector::subtraction( x, target[1], target[0] );
          ::math::linear::vector::subtraction( y, target[2], target[0] );
          ::math::linear::vector::subtraction( z, target[3], target[0] );
          ::math::linear::vector::subtraction( t, target[4], target[0] );
          ::math::linear::affine::system( result, target[0], x, y, z, t );

          return true;
         }

      }
    }
  }

#endif