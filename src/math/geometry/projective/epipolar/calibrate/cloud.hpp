#ifndef math_geometry_projective_camera_calibrate_cloud
#define math_geometry_projective_camera_calibrate_cloud

// ::math::geometry::projective::camera::calibrate( alpha, h_scale, v_scale )

//#include <utility>

#include "../../../../linear/affine/affine.hpp"
#include "../../../../linear/vector/structure.hpp"
#include "../../../plane/parametric3d.hpp"
#include "../../../../statistic/average.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace calibrate
         {

          template < typename scalar_name >
           class cloud
            {
             public:
               typedef std::size_t size_type;
               typedef scalar_name scalar_type;
               typedef ::math::linear::vector::point<  scalar_name, 3 > point_type;
               typedef ::math::linear::vector::vector< scalar_name, 3 > vector_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

               typedef ::math::geometry::plane::parametric3d<scalar_name> parametric_type;
               typedef std::pair< point_type, point_type > pair_type;
               typedef std::vector< pair_type > cloud_type;


               static scalar_type check( affine_type & to_right, cloud_type const& cloud )
                {
                 ::math::statistic::average<scalar_name> radius;

                 point_type right;
                 for( auto const& pair : cloud )
                  {
                   ::math::linear::affine::transform( right, to_right, pair.first );

                   radius.push( ::math::linear::vector::distance( pair.second, right ) );
                  }
                 return radius.value();
                }

               static bool correct( affine_type & to_right, cloud_type const& cloud, scalar_type const& radius )
                {
                 size_type  count=0;
                 std::array< point_type, 4 > right;
                 std::array< point_type, 4 > left;

                 return false;
                }

               static bool process( affine_type & to_right, cloud_type const& cloud )
                {
                 size_type  count=0;
                 std::array< point_type, 4 > right;
                 std::array< point_type, 4 > left;

                 std::array<size_type, 4 > index={ 3, 2, 1, 0 };
                 bool result = false;
                 do
                  {
                   right[0] = cloud[ index[0] ].first ;  right[0] = cloud[ index[1] ].first;  right[0] = cloud[ index[2] ].first;  right[0] = cloud[ index[3] ].first;
                   left[0]  = cloud[ index[0] ].second;  left[0]  = cloud[ index[1] ].second; left[0]  = cloud[ index[2] ].second; left[0]  = cloud[ index[3] ].second;
                   result = ::math::linear::affine::construct( to_right, right, left );
                   if( true == result )
                    {
                     break;
                    }
                  }
                 while( math::algorithm::next_combination( index.begin(), index.end(), cloud.size() ) );

                 if( false == result )
                  {
                   return false;
                  }
                 ++count;

                 affine_type  current;
                 while( math::algorithm::next_combination( index.begin(), index.end(), cloud.size() ) )
                 {
                  right[0] = cloud[ index[0] ].first;   right[0] = cloud[ index[1] ].first;  right[0] = cloud[ index[2] ].first;  right[0] = cloud[ index[3] ].first;
                  left[0]  = cloud[ index[0] ].second;   left[0] = cloud[ index[1] ].second; left[0]  = cloud[ index[2] ].second; left[0]  = cloud[ index[3] ].second;
                  if( false == ::math::linear::affine::construct( current, right, left ) )
                   {
                    continue;
                   }
                  ::math::linear::affine::addition( to_right, current );
                  ++count;
                 }
                ::math::linear::affine::scale( to_right, scalar_name(1) / count );
                return true;
               }
            };

         }
       }
     }
   }
 }

#endif
