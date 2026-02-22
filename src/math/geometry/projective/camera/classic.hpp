#ifndef math_geometry_projective_camera_classic
#define math_geometry_projective_camera_classic

// ::math::geometry::projective::camera::classic<scalar_name, size_name = std::size_t >( resolution, focus )

#include <cmath>

#include "../../../linear/vector/vector.hpp"
#include "../../../geometry/interval/interval.hpp"
#include "../../../function/clamper.hpp"

#include "./pinhole.hpp"
#include "./a2f.hpp"



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
         class classic
          { // resolution, window, focus
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::linear::vector::structure< scalar_type , 2 >          uv_type;
             typedef ::math::linear::vector::point< scalar_type , 3 >         point3d_type;
             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;

             typedef ::math::geometry::interval::structure<scalar_name,2>      window_type;

             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

             explicit classic( )
              :m_focus(1)
              ,m_window{ { scalar_type(-1), scalar_type(-1) }, { scalar_type(+1), scalar_type(+1) } }
              ,m_resolution{ 1, 1 }
              {
              }

           public:
             classic( size_type const& width, size_type const& height, scalar_type const& F = 1)
              :m_focus( F )
              ,m_window{ { scalar_type(-1), scalar_type(-1) }, { scalar_type(+1), scalar_type(+1) } }
              ,m_resolution{ width, height }
              {
               }

             explicit classic( resolution_type const& resolution, scalar_type const& F = 1 )
              :m_focus( F )
              ,m_window{ { scalar_type(-1), scalar_type(-1) }, { scalar_type(+1), scalar_type(+1) } }
              ,m_resolution( resolution )
              {
              }

           public:
             template< typename number_name >
              vector_type< number_name > xy( uv_type const& uv )const //!< convert display to pixel
               {
                vector_type< number_name > result;
                auto X = ( uv[0] - m_window[0][0] ) / ( m_window[1][0] - m_window[0][0] );
                auto Y = ( uv[1] - m_window[0][1] ) / ( m_window[1][1] - m_window[0][1] );
                Y = scalar_type(1) - Y;
                result[0] = (number_name)( X * m_resolution[0] );
                result[1] = (number_name)( Y * m_resolution[1] );
                return result;
               }

             template< typename number_name >
              vector_type< number_name > principal()const //!<
               {
                return this->template xy<number_name>( {0,0} );
               }

           public:
             template< typename number_name >
              uv_type uv( vector_type< number_name > const& xy )const  //!< convert pixel to display
               {
                uv_type result;
                scalar_type U = xy[0] / scalar_type( m_resolution[0] );
                scalar_type V = xy[1] / scalar_type( m_resolution[1] );
                V = scalar_type( 1 ) - V;
                result[0] = m_window[0][0] + U * ( m_window[1][0] - m_window[0][0] );
                result[1] = m_window[0][1] + V * ( m_window[1][1] - m_window[0][1] );
                return result;
               }

           public:
             template< typename number_name/*, size_name axis = 1*/ >
              vector_type< number_name > projectXY( point3d_type const& xyz )const //!< convert world to pixel
               {
                return this->template xy<number_name>( this->projectUV ( xyz ) );
               }

           public:
             uv_type projectUV( point3d_type const& xyz )const //!< convert world to UV
              {
               auto result = pinhole_type::project( xyz );
               ::math::linear::vector::scale( result, this->focus() );
               return result;
              }

           public:
             scalar_type const& focus()const
              {
               return this->m_focus;
              }
              void focus( scalar_type const& F )
              {
               m_focus = F;
               return ;
              }

           private:
             scalar_type     m_focus;

           public:
             void window( window_type const& W ) //!< expect positive numbers
              {
               m_window = W;
              }
             window_type const& window()const
              {
               return m_window;
              }

             scalar_type aspect()const //!< pixel aspect ratio
              {
               scalar_type X = (this->m_window[1][0]-this->m_window[0][0])/ this->resolution()[0];
               scalar_type Y = (this->m_window[1][1]-this->m_window[0][1])/ this->resolution()[1];
               auto result = X / Y;
               return result;
              }

             bool aspect( scalar_type const& A, bool const& prefer_width = true )
              {
               switch( prefer_width )
                {
                 case( true ):
                  {
                   scalar_type X = (this->m_window[1][0]-this->m_window[0][0])/ this->resolution()[0];
                   scalar_type Y = X * this->resolution()[1];
                   this->m_window[0][1] = - Y/( A*scalar_type(2) );
                   this->m_window[1][1] = + Y/( A*scalar_type(2) );
                  }return true;
                 case( false ):
                  {
                   scalar_type Y = (this->m_window[1][1]-this->m_window[0][1])/ this->resolution()[1];
                   scalar_type X = Y * this->resolution()[0];
                   this->m_window[0][1] = - A*X/scalar_type(2);
                   this->m_window[1][1] = + A*X/scalar_type(2);
                  }return true;
                }
               return false;
              }

           private:
             window_type m_window;

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
               }
           private:
             resolution_type m_resolution;

           public:
             scalar_type left_angle() const
              {
               return atan2( m_window[0][0], this->m_focus );
              }
             scalar_type right_angle() const
              {
               return atan2( m_window[1][0], this->m_focus );
              }

             scalar_type down_angle() const
              {
               return atan2( m_window[0][1], this->m_focus );
              }
             scalar_type up_angle() const
              {
               return atan2( m_window[1][1], this->m_focus );
              }

             scalar_type horizontal() const
              {
               scalar_type L = fabs( left_angle() );
               scalar_type R = fabs( right_angle() );
               return  L + R ;
              }

             bool horizontal( scalar_type const angle )
              {
               scalar_type aspect = this->m_resolution[0] / scalar_type(this->m_resolution[1] );
               this->m_window[0][0] = -1;
               this->m_window[1][0] = +1;
               this->m_window[0][1] = this->m_window[0][0] / aspect;
               this->m_window[1][1] = this->m_window[1][0] / aspect;
               this->m_focus = ::math::geometry::projective::camera::a2f( angle, scalar_name(2) );
               return  true;
              }

             scalar_type vertical() const
              {
               scalar_type D = fabs( down_angle() );
               scalar_type U = fabs( up_angle() );
               return  D + U ;
              }
          };

       }
     }
   }
 }

#endif
