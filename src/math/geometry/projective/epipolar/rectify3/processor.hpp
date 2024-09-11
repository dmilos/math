#ifndef math_geometry_projective_epipolar_rectify3_processor
#define math_geometry_projective_epipolar_rectify3_processor

// ::math::geometry::projective::epipolar::rectify3::processor<double>

//#include <utility>


#include "../../camera/optical.hpp"
#include "./pole.hpp"
#include "./recenter.hpp"
#include "./retarget.hpp"

#include "../../../../linear/homography/redomain.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace rectify3
         {

          template < typename scalar_name >
          class processor
           {
            public:
              typedef scalar_name scalar_type;

              typedef ::math::linear::vector::point<scalar_type,2>     point_type;
              typedef ::math::linear::homography::structure<scalar_type, 2>     homography_type;
              typedef ::math::geometry::projective::camera::mobile<scalar_type >            camera_type;

              //!< top of all functions.
              bool process( camera_type const& sinister, camera_type const& dexter )
               {
                m_rectificator.process( sinister.to_world(), dexter.to_world() );

                m_rectificator.left(  hL, sinister, dexter );

                m_retargetL.process( hL, sinister.optical().window(), sinister.optical().resolution() );
                m_recenterL.process( hL, sinister.optical().resolution(), 2 );

                interval_type  displayL{ { 0, (scalar_type)sinister.optical().resolution()[1] }, { (scalar_type)sinister.optical().resolution()[0], 0 } };
                ::math::linear::homography::redomain( m_tmp, hL, displayL, sinister.optical().window() );
                ::math::linear::matrix::invert( m_L_s2i, m_tmp );

                m_rectificator.right( hR, sinister, dexter );
                m_retargetR.process( hR, dexter.optical().window(), dexter.optical().resolution() );
                m_recenterR.process( hR, dexter.optical().resolution(), 2  );

                interval_type  displayR{ { 0, (scalar_type)dexter.optical().resolution()[1] }, { (scalar_type)dexter.optical().resolution()[0], 0 } };
                ::math::linear::homography::redomain( m_tmp, hR, displayR, dexter.optical().window() );
                ::math::linear::matrix::invert( m_R_s2i, m_tmp );
                return true;
               }

              homography_type const& left() const
               {
                return hL;
               }
              homography_type const& right() const
               {
                return hR;
               }

              point_type  left_image2screen( point_type const& image ) const
               {
                point_type result;
                ::math::linear::homography::transform( result, m_L_s2i, image );
                return result;
               }

              point_type  right_image2screen( point_type const& image ) const
               {
                point_type result;
                ::math::linear::homography::transform( result, m_R_s2i, image );
                return result;
               }

           private:
              typedef ::math::geometry::interval::structure<scalar_type, 2>           interval_type;

              typedef ::math::geometry::projective::epipolar::rectify3::pole<scalar_type>       pole_type;
              typedef ::math::geometry::projective::epipolar::rectify3::retarget<scalar_type>   retarget_type;
              typedef ::math::geometry::projective::epipolar::rectify3::recenter<scalar_type>   recenter_type;

            pole_type m_rectificator;
            retarget_type m_retargetL, m_retargetR;
            recenter_type m_recenterL, m_recenterR;

            homography_type     hL, hR,  m_L_s2i;
            homography_type              m_R_s2i;
            homography_type m_tmp;
          };

         }
       }
     }
   }
 }

#endif
