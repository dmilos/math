#ifndef math_geometry_interval_intersect_hpp_
 #define math_geometry_interval_intersect_hpp_

// ::math::geometry::interval::intersect( result, left, right )
// ::math::geometry::interval::intersect( result, right )
// ::math::geometry::interval::intersect_check( left, right )
// ::math::geometry::interval::intersect_weak( result, left, right )
// ::math::geometry::interval::intersect_weak( left, right )
// ::math::geometry::interval::intersect( result, box, parametric, epsilon    = 1e-12 )

#include <limits>
#include <tuple>

#include "./structure.hpp"

#include "../direction/parametric.hpp"




 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template < typename scalar_name,::math::type::size_type dimension_number >
        bool
        intersect
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            if(  left.m_corner[1][index] < right.m_corner[0][index] ) return false;
            if( right.m_corner[1][index] <  left.m_corner[0][index] ) return false;

            result.m_corner[0][index] = std::max<scalar_name>( left.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( left.m_corner[1][index], right.m_corner[1][index] );
           }

          return true;
         }

       template < typename scalar_name,::math::type::size_type dimension_number >
        bool
        intersect
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            if( result.m_corner[1][index] < right.m_corner[0][index] ) return false;
            if( right.m_corner[1][index] <  result.m_corner[0][index] ) return false;

            result.m_corner[0][index] = std::max<scalar_name>( result.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( result.m_corner[1][index], right.m_corner[1][index] );
           }

          return true;
         }

       template < typename scalar_name,::math::type::size_type dimension_number >
        bool
        intersect_check
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            if( left.m_corner[1][index] < right.m_corner[0][index] ) return false;
            if( right.m_corner[1][index] <  left.m_corner[0][index] ) return false;
           }

          return true;
         }

       template < typename scalar_name,::math::type::size_type dimension_number >
        void
        intersect_weak
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            result.m_corner[0][index] = std::max<scalar_name>( left.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( left.m_corner[1][index], right.m_corner[1][index] );
           }
         }

       template < typename scalar_name,::math::type::size_type dimension_number >
        void
        intersect_weak
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            result.m_corner[0][index] = std::max<scalar_name>( result.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( result.m_corner[1][index], right.m_corner[1][index] );
           }
         }

       template < typename scalar_name,::math::type::size_type dimension_number >
        bool
        intersect
         (
            std::tuple< unsigned, scalar_name, unsigned, scalar_name >                 & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number>    const& box
          ,::math::geometry::direction::parametric<scalar_name, dimension_number> const& parametric
          ,scalar_name                                                            const& epsilon    = 1e-12
          )
         { // TODO make structure 
          typedef ::math::linear::vector::point<scalar_name, dimension_number> coord_type;

          //typedef std::tuple< unsigned, scalar_name, unsigned, scalar_name > result_type;

          auto & Ir_entrace = std::get<0>( result );  Ir_entrace = 1;
          auto & Ir_near    = std::get<1>( result );  Ir_near =  -std::numeric_limits<scalar_name>::max();
          auto & Ir_exit    = std::get<2>( result );  Ir_exit = 2;
          auto & Ir_far     = std::get<3>( result );  Ir_far =  std::numeric_limits<scalar_name>::max();

          auto const& direction = parametric.direction();
          auto const& origin    = parametric.origin();

          //using namespace ::math::linear::vector;
          coord_type I_lo; ::math::linear::vector::subtraction( I_lo, box.lo(), origin );
          coord_type I_hi; ::math::linear::vector::subtraction( I_hi, box.hi(), origin );

          unsigned     I_lo_side  ;
          scalar_name  I_lo_lambda;
          unsigned     I_hi_side  ;
          scalar_name  I_hi_lambda;

          for( int I_proj=0; I_proj < (int)dimension_number ; I_proj++ )
           {
            if( epsilon < direction[ I_proj ] )
             {
              I_lo_lambda = I_lo[ I_proj ] / direction[ I_proj ];
              I_hi_lambda = I_hi[ I_proj ] / direction[ I_proj ];
              I_lo_side = 2*I_proj+1;
              I_hi_side = 2*I_proj+2;
              goto L_intersect;
             }

            if( direction[ I_proj ] < -epsilon )
             {
              I_lo_lambda  = I_hi[ I_proj ] / direction[ I_proj ];
              I_hi_lambda  = I_lo[ I_proj ] / direction[ I_proj ];
              I_lo_side = 2 * I_proj+2;
              I_hi_side = 2 * I_proj+1;
              goto L_intersect;
             }

            if( ( scalar_name( 0 ) < I_lo[ I_proj ] ) || ( I_hi[ I_proj ] < scalar_name( 0 ) ) )
             {
              return false;
             }

            I_lo_lambda = -std::numeric_limits<scalar_name>::max();
            I_hi_lambda =  std::numeric_limits<scalar_name>::max();


            L_intersect:

             if( Ir_near  < I_lo_lambda ) { Ir_near = I_lo_lambda; Ir_entrace = I_lo_side; }
             if( I_hi_lambda < Ir_far   ) { Ir_far  = I_hi_lambda; Ir_exit    = I_hi_side; }

             if( Ir_far  < Ir_near  )
              {
               return false;
              }
           }

          return true;
         }

      }
    }
  }

#endif
