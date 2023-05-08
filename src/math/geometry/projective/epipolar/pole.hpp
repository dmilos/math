#ifndef math_geometry_projective_epipolar_pole
#define math_geometry_projective_epipolar_pole

// ::math::geometry::projective::epipolar::pole<scalar_name, size_name = std::size_t >

#include "../camera/mobile.hpp"
#include "../../../linear/affine/transform.hpp"
#include "../../../linear/homography/structure.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         struct pole //!< calculate epipoles in homogeneous of camera plane. Epipole can be in infinity.
          {
           public:
             typedef std::size_t   size_type;
             typedef scalar_name scalar_type;

             typedef ::math::linear::vector::point<scalar_name,3>         point_type;
             typedef ::math::linear::vector::point<scalar_name,3>   homogeneous_type;

             typedef ::math::linear::affine::structure< scalar_name, 3 >       affine_type;
             typedef ::math::linear::homography::structure<scalar_name,2>  homography_type;

             typedef ::math::geometry::projective::camera::mobile< scalar_name, size_name > mobile_type;

             typedef ::math::geometry::projective::epipolar::pole<scalar_name,size_name> this_type;

           public:
             static homogeneous_type & left( homogeneous_type & result, affine_type const& left_to_local, point_type const& right_eye/* in world coord */ )
              {
               return ::math::linear::affine::transform( result, left_to_local, right_eye );
              }

             static homogeneous_type & right( homogeneous_type & result, affine_type const& right_to_local, point_type const& left_eye /* in world coord */ )
              {
               return ::math::linear::affine::transform( result, right_to_local, left_eye );
              }

             static homogeneous_type & left( homogeneous_type & result, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
              {
               return this_type::left( result, sinister.to_local(), dexter.to_world().vector() );
              }

             static homogeneous_type & right( homogeneous_type & result, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
              {
               return this_type::right( result, dexter.to_local(), sinister.to_world().vector() );
              }

             static homogeneous_type & self( homogeneous_type & result/* left/right */, homography_type const& fundamental /* left2right/right2left */ )
              {
               auto const& a0 = fundamental[0][0];  auto const& b0 = fundamental[0][1];  auto const c0 = - fundamental[0][2]; //!< Cramer's! Constant is negative
               auto const& a1 = fundamental[1][0];  auto const& b1 = fundamental[1][1];  auto const c1 = - fundamental[1][2]; //!< Cramer's! Constant is negative

               result[0] =  c0 * b1 - b0 * c1;
               result[1] =  a0 * c1 - c0 * a1;
               result[2] =  a0 * b1 - b0 * a1;
               return result;
              }
          };

       }
     }
   }
 }

#endif
