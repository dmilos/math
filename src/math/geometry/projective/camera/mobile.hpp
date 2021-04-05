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

            mobile()
             {
              // purposly empty
             }

            explicit mobile( digital_type const& digital )
             : m_digital( digital )
             {
              this->to_world( ::math::linear::affine::id<scalar_type, 3>() );
             }

            template< typename number_name > // Accept coordinates in pixels, return direction in world space
             point3d_type rayXY( vector2d_type< number_name > const& xy )const
              {
               return this->rayUV( m_digital.template uv<number_name>( xy ) );
              }

            // Accept coordinates in uv, return direction in world space
            point3d_type rayUV( uv_type const& uv )const
             {
              point3d_type local = pinhole_type::reproject( uv );
              point3d_type direction;
              ::math::linear::matrix::transform( direction, m_2world.matrix(), local );
              ::math::linear::vector::subtraction( direction, this->to_world().vector() );
              return direction;
             }

            template< typename number_name >// accept point in world space return pixel coordinates
              vector2d_type< number_name > project( point3d_type const& point3d )const
               {
                point3d_type local;
                ::math::linear::affine::transform( local, m_2local, point3d );
                auto uv = ::math::geometry::projective::camera::pinhole< scalar_type >::project( local );
                return m_digital.template xy<number_name>( uv );
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
