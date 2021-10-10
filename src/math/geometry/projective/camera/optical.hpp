#ifndef math_geometry_projective_camera_optical
#define math_geometry_projective_camera_optical

// ::math::geometry::projective::camera::optical<scalar_name, size_name = std::size_t >

#include <cmath>
#include <tuple>

#include "../../../linear/vector/vector.hpp"
#include "../../../geometry/interval/interval.hpp"

#include "./d2hv.hpp"
#include "./ha2d.hpp"
#include "./ha2v.hpp"
#include "./hv2d.hpp"
#include "./va2d.hpp"
#include "./va2h.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         class optical //!< TODO rename to digital
          {
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::linear::vector::structure< scalar_type , 2 >          uv_type;
             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;

             typedef ::math::geometry::interval::structure<scalar_name,2>      window_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

             explicit optical( scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ) )
              :m_resolution{ 1, 1 }
              ,m_pixelAR( 1 )
              {
               this->diagonalFV( DFoV );
               //this->window();
              }

             optical( size_type const& width, size_type const& height, scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ), scalar_type const& pAR = 1 )
              :m_resolution{ width, height }
              ,m_pixelAR( pAR )
              {
               this->diagonalFV( DFoV );
               //this->window();
              }

             optical( resolution_type const& resolution, scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ), scalar_type const& pAR = 1 )
              :m_resolution{ resolution }
              ,m_pixelAR( pAR )
              {
               this->diagonalFV( DFoV );
               //this->window();
              }

             //!!! Qube camera([-1,-1]x[1,1]) to display(pixel)
             // (0,0) ->( -1, -1 ) ; (m_resolution[0],m_resolution[1]) ->( +1, +1 ) ;
             template< typename number_name >
              vector_type< number_name > xy( uv_type const& uv )const
               {
                vector_type< number_name > xy;

                size_type max = std::max<size_type>( m_resolution[0], m_resolution[1] );
                size_type min = std::min<size_type>( m_resolution[0], m_resolution[1] );

                scalar_type x = uv[0];
                scalar_type y = uv[1];

                x  /= tan( m_maxFV / 2 );
                y  /= tan( m_maxFV / 2 );

                x  += scalar_type(1);
                y  += scalar_type(1);

                x  *= max;
                y  *= max;

                x  -= max - m_resolution[0];
                y  -= max - m_resolution[1];

                x  /= scalar_type(2);
                y  /= scalar_type(2);

              //x  = x;
                y  = m_resolution[1] - y ;

              //x *= scalar_type(1);
                y *= m_pixelAR;

                xy[0] = number_name( x );
                xy[1] = number_name( y );

                return xy;
               }

              //!!! display(pixel) to cube camera([-1,-1]x[1,1])
              //! ( -1, -1 ) -> (0,0) ; ( +1, +1 ) -> (m_resolution[0],m_resolution[1]);
              template< typename number_name >
               uv_type uv( vector_type< number_name > const& xy )const
                {
                 uv_type result;
                 scalar_type max = scalar_type( std::max<size_type>( m_resolution[0], m_resolution[1] ) );
                 scalar_type min = scalar_type( std::min<size_type>( m_resolution[0], m_resolution[1] ) );

                 scalar_type & u = result[0];
                 scalar_type & v = result[1];

                 u = scalar_type( xy[0] );
                 v = scalar_type( xy[1] );

               //u /= scalar_type(1);
                 v /= m_pixelAR ;

               //u = u;
                 v = m_resolution[1] - v;

                 u *= scalar_type(2);
                 v *= scalar_type(2);

                 u += max-m_resolution[0];
                 v += max-m_resolution[1];

                 u /= max;
                 v /= max;

                 u -= scalar_type(1);
                 v -= scalar_type(1);

                 u *= tan( m_maxFV / 2 );
                 v *= tan( m_maxFV / 2 );

                 return result;
                }

           public:
              void FV( scalar_type const& hFV, scalar_type const& vFV )
              {
               m_horizontalFV = hFV;
               m_verticalFV   = vFV;
               m_diagonalFV   = ::math::geometry::projective::camera::hv2d( m_horizontalFV, m_verticalFV );
               m_maxFV        = std::max( this->m_horizontalFV, this->m_verticalFV );
               m_pixelAR      = tan( this->horizontalFV() / scalar_type(2) ) / tan( this->verticalFV()   / scalar_type(2) );
               return ;
              }

           public:
             scalar_type const& diagonalFV()const
              {
               return this->m_diagonalFV;
              }
             void diagonalFV( scalar_type const& DFoV )
              {
               m_diagonalFV = DFoV;
               std::tie( this->m_horizontalFV, this->m_verticalFV ) = ::math::geometry::projective::camera::d2hv<scalar_type>( m_diagonalFV, scalar_type( this->m_resolution[0] ), scalar_type( this->m_resolution[1] ) ) ;
               m_maxFV = std::max( this->m_horizontalFV, this->m_verticalFV );
              }
           private:
             scalar_type     m_diagonalFV;

           public:
             scalar_type const& horizontalFV()const{ return this->m_horizontalFV; }
             void horizontalFV( scalar_type const& fv )
              {
               scalar_type aspect = m_resolution[0]/(scalar_type)m_resolution[1];
               m_horizontalFV = fv;
               m_diagonalFV = ::math::geometry::projective::camera::ha2d<scalar_type>( m_horizontalFV, aspect );
               m_verticalFV = ::math::geometry::projective::camera::ha2v<scalar_type>( m_horizontalFV, aspect );
               m_maxFV = std::max( m_horizontalFV, m_verticalFV );
              }
           private:
             scalar_type     m_horizontalFV;

           public:
             scalar_type const& verticalFV()const{ return m_verticalFV; }
             void verticalFV( scalar_type const& fv )
              {
               scalar_type aspect = m_resolution[0]/(scalar_type)m_resolution[1];
               m_verticalFV  = fv;
               m_diagonalFV   = ::math::geometry::projective::camera::va2d<scalar_type>( m_verticalFV, aspect );
               m_horizontalFV = ::math::geometry::projective::camera::va2h<scalar_type>( m_verticalFV, aspect );
               m_maxFV = std::max( m_horizontalFV, m_verticalFV );
              }
           private:
             scalar_type     m_verticalFV;

           private:
             scalar_type     m_maxFV;

           public:
             window_type const& window()const
              { // On demand value
               m_window[1][0] = tan( this->horizontalFV() / scalar_type(2) );  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = tan( this->verticalFV()   / scalar_type(2) );  m_window[0][1] = -m_window[1][1];
               return m_window;
              }
           private:
             mutable window_type m_window;
           public:
             resolution_type const& resolution()const
              {
               return m_resolution; 
              }
             void resolution( size_type const& width, size_type const& height )
              {
               this->resolution( resolution_type{ width, height } );
              }

             void resolution( resolution_type const& resolution )
              {
               this->m_resolution = resolution;
               this->diagonalFV( m_diagonalFV );
              }
           private:
             resolution_type m_resolution;

           public:
             scalar_type const& pixelAR()const{ return m_pixelAR; }
             void pixelAR( scalar_type const& pAR )
              {
               m_pixelAR = pAR;
              }
           private:
             scalar_type     m_pixelAR;
          };

       }
     }
   }
 }

#endif
