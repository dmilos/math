#ifndef math_geometry_projective_camera_align
#define math_geometry_projective_camera_align

// ::math::geometry::projective::epipolar::align<scalar>;

#include "../camera/mobile.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template < typename scalar_name >
         struct align
          {
           public:
             typedef scalar_name   scalar_type;
             typedef ::math::linear::affine::structure<  scalar_name, 3 > affine_type;

             typedef ::math::geometry::projective::camera::mobile< scalar_name >               mobile_type;
             typedef std::vector<mobile_type>               system_type;

             align()
              {
               math::linear::affine::id( m_id );
              }
           public:
             void process
              (
                mobile_type  & sinister,  mobile_type  & dexter
              )
              {
               m_toLocal = sinister.to_local();
               math::linear::affine::compose( m_tmp, m_toLocal, dexter.to_world( ) );
               dexter.to_world( m_tmp );
               sinister.to_world( m_id );
              }

             void process
              (
                system_type  & system
              )
              {
               m_toLocal = system[0].to_local();

               for( unsigned right_index=0; right_index < system.size(); ++right_index )
                {
                 auto & dexter = system[right_index];
                 math::linear::affine::compose( m_tmp, m_toLocal, dexter.to_world( ) );
                 dexter.to_world( m_tmp );
               }
              }

            private:
              affine_type m_tmp;
              affine_type m_toLocal;
              affine_type m_id;
          };

       }
     }
   }
 }

#endif
