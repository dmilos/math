#ifndef math_concentric_ellipse_pair_find
#define math_concentric_ellipse_pair_find
// ::math::geometry::ellipse::CEPF<scalar_name>


#include <vector>
#include <utility>

#include "../../geometry/rad2deg.hpp"
#include "../../geometry/deg2rad.hpp"

#include "./distance.hpp"

#include "./general2d.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace ellipse
      {

       template< typename scalar_name >
        struct CEPF //!< Find two concentric ellipse
         {
          public:
            typedef scalar_name scalar_type;
            typedef std::size_t size_type;
            typedef ::math::geometry::ellipse::general2D<scalar_type>  ellipse_type;
            typedef std::vector< ellipse_type > container_type;
            typedef std::pair< size_type, size_type> pair_type;
            typedef std::vector<pair_type> couple_type;

            CEPF()
             {
              m_small_angle =  ::math::geometry::rad2deg( 6 );
             }

            static bool containe( ellipse_type const& left, ellipse_type const& right )
             {
              auto m_angle = ::math::geometry::rad2deg<scalar_type>( 6 );
              if( 0 < ::math::geometry::ellipse::distance( left, right.center() ) )
               {
                return false;
               }
              if( 0 < ::math::geometry::ellipse::distance( right, left.center() ) )
               {
                return false;
               }

              auto angle = ::math::geometry::rad2deg ( fabs( right.rotation()-  left.rotation() ) );
              if( ( m_small_angle < angle ) && ( angle < ( 180 - m_small_angle ) ) )
               {
                return false;
               }

              return true;
             }

            size_type process( container_type const & container )
             {
              m_couple.clear();
              for( size_type f=0 ; f < container.size(); ++f )
               for( size_type s=f+1 ; s < container.size(); ++s )
                {
                 if( false == containe( container[f], container[s] ) )
                  {
                   continue;
                  }
                 m_couple.push_back( {f,s} );
                }
              return m_couple.size();
             }
          public:
            couple_type const& result(){ return m_couple; }
          private:
            couple_type m_couple;
          private:
            scalar_type m_small_angle;
         };


  } } }

#endif
