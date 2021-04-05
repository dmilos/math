#ifndef math_topology_sico_delaunay
#define math_topology_sico_delaunay

// ::math::topology::sico::delaunay<data_name>

#include <vector>
#include <array>
#include "../../../linear/vector/distance.hpp"
#include "../../../geometry/circle/inside.hpp"
#include "../../../geometry/circle/construct.hpp"
#include "../property/point.hpp"
#include "./nng.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

     template
       <
         typename   scalar_name
        ,typename     data_name //!< Essentially whatever. Copyable
       >
       typename ::math::topology::sico::structure<data_name>::size_type
       delaunay2 //!< Delaunay Triangulation
       (
         ::math::topology::sico::structure<data_name>       & result
       )
       {
        typedef typename ::math::topology::sico::structure<data_name>::size_type size_type;

        ::math::topology::sico::NNG<scalar_name,2,data_name>( result );

        for( size_type a=0; a < result.size(1); ++a )
         {
          auto const& simplex = result.simplex( 1, a );
          auto const& A = simplex.face()[0];
          auto const& B = simplex.face()[1];

          auto const & first   = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( A ) );
          auto const & second  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( B ) );
          for( size_type C =0; C < result.size(0); ++C )
           {
            if( A == C ) continue;
            if( B == C ) continue;
            auto const & third  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( C ) );

            ::math::geometry::circle::simple<scalar_name,2> circle;
            if( false == ::math::geometry::circle::construct( circle, first, second, third ) )
             {
              continue;
             }
            bool flag = true;
            for( size_type T =0; T < result.size(0); ++T )
             {
              if( T == A ) continue;
              if( T == B ) continue;
              if( T == C ) continue;
              auto const & test  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( T ) );
              if( true == ::math::geometry::circle::inside<scalar_name>( circle, test ) )
               {
                flag = false;
                break;
               }
             }

            if( true == flag )
             {
              auto b = result.push( data_name{}, { A, C } );
              auto c = result.push( data_name{}, { A, B } );
              result.push( data_name{}, { a, b, c } );
            }
           }
         }

        return result.size();
       }

     template
       <
         typename   scalar_name
        ,typename     data_name //!< Essentially whatever. Copyable
       >
       typename ::math::topology::sico::structure<data_name>::size_type delaunay3 //!< Delaunay Triangulation
       (
         ::math::topology::sico::structure<data_name>       & result
       )
       {
        typedef typename ::math::topology::sico::structure<data_name>::size_type size_type;

        ::math::topology::sico::NNG<scalar_name,3,data_name>( result );

        for( size_type a=0; a < result.size(1); ++a )
         {
          auto const& simplex = result.simplex( 1, a );
          auto const& A = simplex.face()[0];
          auto const& B = simplex.face()[1];

          auto const & first   = ::math::topology::sico::property::point<scalar_name,3>( result.vertex( A ) );
          auto const & second  = ::math::topology::sico::property::point<scalar_name,3>( result.vertex( B ) );
          for( size_type C =0; C < result.size(0); ++C )
           {
            if( A == C ) continue;
            if( B == C ) continue;
            for( size_type D =0; D < result.size(0); ++D )
             {
              if( A == D ) continue;
              if( C == D ) continue;
              if( B == D ) continue;

              auto const & third  = ::math::topology::sico::property::point<scalar_name,3>( result.vertex( C ) );
              auto const & fourth = ::math::topology::sico::property::point<scalar_name,3>( result.vertex( D ) );

              ::math::geometry::circle::simple<scalar_name,3> circle;
              if( false == ::math::geometry::circle::construct( circle, first, second, third, fourth ) )
               {
                continue;
               }

              bool flag = true;
              for( size_type T = 0; T < result.size(0); ++T )
               {
                if( T == A ) continue;
                if( T == B ) continue;
                if( T == C ) continue;
                if( T == D ) continue;
                auto const & test  = ::math::topology::sico::property::point<scalar_name,3>( result.vertex( T ) );
                if( true == ::math::geometry::circle::inside<scalar_name>( circle, test ) )
                 {
                  flag = false;
                  break;
                 }
               }

              if( true == flag )
               {
                auto a = result.push( data_name{}, { A, B } );
                auto b = result.push( data_name{}, { A, C } );
                auto c = result.push( data_name{}, { A, D } );
                auto d = result.push( data_name{}, { B, C } );
                auto e = result.push( data_name{}, { B, D } );
                auto f = result.push( data_name{}, { C, D } );

                auto s0 = result.push( data_name{}, { a, b, d } );  // ABC
                auto s1 = result.push( data_name{}, { b, c, f } );  // ACD
                auto s2 = result.push( data_name{}, { a, c, e } );  // ABD
                auto s3 = result.push( data_name{}, { d, e, f } );  // BCD

                result.push( data_name{}, { s0, s1, s2, s3 } );
               }
              }
           }
         }

        return result.size();
       }

     }
   }
 }

#endif
