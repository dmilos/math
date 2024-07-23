#ifndef math_geometry_projective_camera_focus_ellipse
#define math_geometry_projective_camera_focus_ellipse

// ::math::geometry::projective::camera::focus::ellipse( focus, center, minor, mayor );





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          template < typename scalar_name >
           bool
           ellipse
            (
               scalar_name & focus
             , ::math::linear::vector::structure<scalar_name,2>  const& center
             , scalar_name const &minor
             , scalar_name const &mayor
             // , scalar_name const &epsilon = 1e-6
            )
            {
             auto const& m =  minor;
             auto const& M =  mayor;
             auto const& x =  center[0];
             auto const& y =  center[1];

             //auto K1 = (m/M);
             //auto K2 = (x/y);
             //focus = 4 * x * x * K1*K1*( 1+K2*K2 )/( K2*K2*( 1-K1*K1 ) ) - m*m;
             //focus = scalar_name(0.5) * sqrt( fabs( focus ) );

             //focus = m * m * ( m*m- M*M  + scalar_name(4)*(x*x+y*y) ) /( M*M-m*m );
             //focus = scalar_name(0.5) * sqrt( fabs( focus ) );

             auto foci2 = M*M-m*m;

             //if( fabs( foci2 ) < epsilon )
             // {
             //  return false;
             // }

             focus = (x*x+y*y) / foci2 - scalar_name(0.25);
             focus = m * sqrt( fabs( focus ) );

             return true;
            }

         }
       }
     }
   }
 }

#endif
