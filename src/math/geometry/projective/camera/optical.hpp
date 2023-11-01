#ifndef math_geometry_projective_camera_optical
#define math_geometry_projective_camera_optical

// ::math::geometry::projective::camera::optical<scalar_name, size_name = std::size_t >( resolution, DFoV, pixelAR )

#include <cmath>
#include <tuple>

#include "../../../linear/vector/vector.hpp"
#include "../../../geometry/interval/interval.hpp"
#include "../../../function/clamper.hpp"


#include "./d2hv.hpp"
#include "./ha2d.hpp"
#include "./ha2v.hpp"
#include "./hv2d.hpp"
#include "./va2d.hpp"
#include "./va2h.hpp"
#include "./a2w.hpp"
#include "./w2a.hpp"


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
         class optical //!< TODO rename to digital;
          {
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::linear::vector::structure< scalar_type , 2 >          uv_type;
             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;

             typedef ::math::geometry::interval::structure<scalar_name,2>      window_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

             explicit optical( scalar_type const& DFoV = 2 * std::atan( std::sqrt(2) ) )
              :m_resolution{ 1, 1 }
              {
               this->diagonalFV( DFoV );
               //this->window();
              }

           public:
             optical( size_type const& width, size_type const& height, scalar_type const& DFoV = 2 * std::atan( std::sqrt(2) ) )
              :m_resolution{ width, height }
              {
               this->diagonalFV( DFoV );
               //this->window();
              }

             explicit optical( resolution_type const& resolution, scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ) )
              :m_resolution{ resolution }
              {
               this->diagonalFV( DFoV );
               //this->window( );
              }

           public:
             //!!! Cube camera([-1,-1]x[1,1]) to display(pixel)
             // (0,0) <- ( -1, -1 ) ; (m_resolution[0],m_resolution[1]) <-( +1, +1 ) ;
             template< typename number_name >
              vector_type< number_name > xy( uv_type const& uv )const //!< convert display to pixel
               {
                vector_type< number_name > result;
                auto X = math::function::any_to_any<scalar_type>( uv[0], m_window[0][0], m_window[1][0], scalar_type(0), scalar_type( m_resolution[0] ) );
                auto Y = math::function::any_to_any<scalar_type>( uv[1], m_window[0][1], m_window[1][1], scalar_type( m_resolution[1] ), scalar_type(0) );
                result[0] = (number_name)X;
                result[1] = (number_name)Y;
                return result;
               }

           public:
              //!!! display(pixel) to cube camera([-1,-1]x[1,1])
              //! ( -1, -1 ) -> (0,0) ; ( +1, +1 ) -> (m_resolution[0],m_resolution[1]);
              template< typename number_name >
               uv_type uv( vector_type< number_name > const& xy )const  //!< convert pixel to display
                {
                 uv_type result;
                 auto U = math::function::any_to_any<scalar_type>( scalar_type( xy[0]), scalar_type(0), scalar_type( m_resolution[0] ), m_window[0][0], m_window[1][0] );
                 auto V = math::function::any_to_any<scalar_type>( scalar_type( xy[1]), scalar_type( m_resolution[1] ), scalar_type(0), m_window[0][1], m_window[1][1] );
                 result[0] = U; 
                 result[1] = V;
                 return result;
                }

           public:
              void FV( scalar_type const& horizontalFV, scalar_type const& verticalFV )
              {
               m_horizontalFV = horizontalFV;
               m_verticalFV   = verticalFV;
               m_diagonalFV   = ::math::geometry::projective::camera::hv2d( m_horizontalFV, m_verticalFV );
               m_window[1][0] = ::math::geometry::projective::camera::a2w( this->horizontalFV()  );  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = ::math::geometry::projective::camera::a2w( this->verticalFV()    );  m_window[0][1] = -m_window[1][1];
               m_pixelAR      =  ( m_resolution[0] / ( m_window[1][0] - m_window[0][0] ) ) /( m_resolution[1] / ( m_window[1][1] - m_window[0][1] ) );
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
               m_window[1][0] = ::math::geometry::projective::camera::a2w( this->horizontalFV() );  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = ::math::geometry::projective::camera::a2w( this->verticalFV()   );  m_window[0][1] = -m_window[1][1];
               m_pixelAR      =  ( m_resolution[0] / ( m_window[1][0] - m_window[0][0] ) ) /( m_resolution[1] / ( m_window[1][1] - m_window[0][1] ) );
              }
           private:
             scalar_type     m_diagonalFV;

           public:
             scalar_type const& horizontalFV()const
              {
               return this->m_horizontalFV; 
              }
             void horizontalFV( scalar_type const& fv )
              {
               scalar_type aspect = m_resolution[0]/(scalar_type)m_resolution[1];
               m_horizontalFV = fv;
               m_verticalFV = ::math::geometry::projective::camera::ha2v<scalar_type>( m_horizontalFV, aspect );
               m_diagonalFV = ::math::geometry::projective::camera::ha2d<scalar_type>( m_horizontalFV, aspect );
               m_window[1][0] = ::math::geometry::projective::camera::a2w( this->horizontalFV() );  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = ::math::geometry::projective::camera::a2w( this->verticalFV()   );  m_window[0][1] = -m_window[1][1];
               m_pixelAR      =  ( m_resolution[0] / ( m_window[1][0] - m_window[0][0] ) ) /( m_resolution[1] / ( m_window[1][1] - m_window[0][1] ) );
              }
           private:
             scalar_type     m_horizontalFV;

           public:
             scalar_type const& verticalFV()const{ return m_verticalFV; }
             void verticalFV( scalar_type const& fv )
              {
               scalar_type aspect = m_resolution[0]/(scalar_type)m_resolution[1];
               m_verticalFV  = fv;
               m_horizontalFV = ::math::geometry::projective::camera::va2h<scalar_type>( m_verticalFV, aspect );
               m_diagonalFV   = ::math::geometry::projective::camera::va2d<scalar_type>( m_verticalFV, aspect );
               m_window[1][0] = ::math::geometry::projective::camera::a2w( this->horizontalFV() );  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = ::math::geometry::projective::camera::a2w( this->verticalFV()   );  m_window[0][1] = -m_window[1][1];
               m_pixelAR      =  ( m_resolution[0] / ( m_window[1][0] - m_window[0][0] ) ) /(  m_resolution[1] / ( m_window[1][1] - m_window[0][1] ) );
              }
           private:
             scalar_type     m_verticalFV;

           public:
             void window( uv_type const& new_window ) //!< expect positive numbers
              {
               m_window[1][0] = new_window[0];  m_window[0][0] = -m_window[1][0];
               m_window[1][1] = new_window[1];  m_window[0][1] = -m_window[1][1];

               m_horizontalFV = ::math::geometry::projective::camera::w2a( m_window[1][0] );
               m_verticalFV   = ::math::geometry::projective::camera::w2a( m_window[1][1] );
               m_diagonalFV   = ::math::geometry::projective::camera::hv2d( m_horizontalFV, m_verticalFV );
               m_pixelAR      =  ( m_resolution[0] / ( m_window[1][0] - m_window[0][0] ) ) /(  m_resolution[1] / ( m_window[1][1] - m_window[0][1] ) );
              }
             window_type const& window()const
              {
               return m_window;
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
               this->diagonalFV( m_diagonalFV );
              }
           private:
             resolution_type m_resolution;

           public:
             scalar_type const& pixelAR()const
              {
               return m_pixelAR;
              }
             // No point! void pixelAR( scalar_type const& pAR )
             // No point!  {
             // No point!   m_pixelAR = pAR;
             // No point! 
             // No point!  }
           private:
             scalar_type     m_pixelAR;
          };

       }
     }
   }
 }

#endif
