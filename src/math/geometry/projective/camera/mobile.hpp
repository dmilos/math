#ifndef math_geometry_projective_camera_mobile
#define math_geometry_projective_camera_mobile

// ::math::geometry::projective::camera::mobile< scalar_name >

#include "./pinhole.hpp"
#include "./optical.hpp"
#include "../../../linear/vector/structure.hpp"
#include "../../../linear/affine/affine.hpp"


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
        class mobile
         {
          public:
            typedef scalar_name  scalar_type;

            typedef ::math::linear::vector::structure< scalar_type , 2 >                 uv_type, point2d_type;
            typedef ::math::linear::vector::point< scalar_type , 3 >                              point3d_type;
            typedef ::math::linear::affine::structure< scalar_name, 3 >                            affine_type;

            typedef ::math::geometry::projective::camera::pinhole<scalar_name>                    pinhole_type;
            typedef ::math::geometry::projective::camera::optical<scalar_name,size_name>          optical_type, digital_type;

            template< typename number_name >
             using vector2d_type = ::math::linear::vector::structure< number_name, 2 >;

          public:
            mobile()
             {
              // purposly empty
             }

            explicit mobile( digital_type const& digital )
             : m_digital( digital )
             {
              this->to_world( ::math::linear::affine::id<scalar_type, 3>() );
             }

          public:
            point3d_type pointUV( uv_type const& uv )const 
             { //!< Accept coordinates in UV, return point in world space
              point3d_type result; ::math::linear::matrix::transform( result, m_2world.matrix(), pinhole_type::reproject( uv ) );
              return result;
             }

            template< typename number_name > // Accept coordinates in pixel s, return point in world space
            point3d_type pointXY( vector2d_type< number_name > const& xy )const 
             { //!< Accept coordinates in XY image, return point in world space
              point3d_type result; this->pointUV( m_digital.template uv<number_name>( xy ) );
              return result;
             }

            template< typename number_name > 
             point3d_type rayXY( vector2d_type< number_name > const& xy )const
              { // Accept coordinates in pixel s, return direction in world space
               return this->rayUV( m_digital.template uv<number_name>( xy ) );
              }

            point3d_type rayUV( uv_type const& uv )const 
             { //!< Accept coordinates in UV, return direction of line in world space
              point3d_type result = this->pointUV( uv );
              ::math::linear::vector::subtraction( result, this->to_world().vector() );
              return result;
             }

            uv_type projectUV( point3d_type const& point3d )const
             { // accept point in world space return UV coordinates
              point3d_type local;
              ::math::linear::affine::transform( local, m_2local, point3d );
              return pinhole_type::project( local );
             }

            template< typename number_name > 
             vector2d_type< number_name > projectXY( point3d_type const& point3d )const
              { //! accept point in world space return pixel coordinates
               return m_digital.template xy<number_name>( this->projectUV( point3d ) );
              }

            template< typename number_name > 
             vector2d_type< number_name > project( point3d_type const& point3d )const //!< obsolete
              { //! accept point in world space return pixel coordinates
               return this->template projectXY<number_name>( point3d );
              }

          public:
            digital_type const& optical()const{ return m_digital; }
            digital_type      & optical( ){ return m_digital; }
          private:
            digital_type m_digital;

          public:
            affine_type const& to_world()const{ return m_2world; }
            void               to_world( affine_type const& w )
             {
              m_2world = w;
              ::math::linear::affine::invert( m_2local, m_2world );
             }
          private:
            affine_type m_2world;

          public:
            affine_type const& to_local()const{ return m_2local; }
            void               to_local( affine_type const& w )
             {
              m_2local = w;
              ::math::linear::affine::invert( m_2world, m_2local );
             }
          private:
            affine_type m_2local;
         };

       }
     }
   }
 }

#endif
