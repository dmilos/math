#ifndef math_geometry_projective_camera_clip
#define math_geometry_projective_camera_clip

// ::math::geometry::projective::camera::frustum::clip( two, window, depth )
#include "../pinhole.hpp"
#include "./side.hpp"
#include "../../../plane/PL3DP3D.hpp"
#include "../../../interval/clip.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace frustum
         {

          template < typename scalar_name >
           struct scissors
            {
             public:
               typedef scalar_name scalar_type;
               typedef ::math::geometry::direction::two<      scalar_name, 3 >            trace_type;
               typedef ::math::geometry::interval::structure< scalar_name, 1 >            depth_type;
               typedef ::math::geometry::interval::structure< scalar_name, 2 >           window_type;

               typedef ::math::geometry::projective::camera::pinhole< scalar_name >     pinhole_type;
               typedef ::math::geometry::interval::scissors<scalar_name,2>                 mold_type;
               typedef ::math::geometry::direction::two<scalar_name,2>                    trail_type;
               typedef ::math::geometry::direction::parametric<scalar_name,3>        parametric_type;

             public:
               bool process( trace_type &output, trace_type const&input, window_type const& window, depth_type const& depth )
                {
                 auto f = ::math::geometry::projective::camera::frustum::side( input.first() , depth );
                 auto s = ::math::geometry::projective::camera::frustum::side( input.second(), depth );

                 if( 0 != f ) --f;
                 if( 0 != s ) --s;

                 int state = 4 * s + f;

                 switch( state )
                  {
                   case( 4 *0 + 0 ): return false;
                   case( 4 *2 + 2 ): return false;
                  }

                 output = input;
                 m_parametric = input;

                 switch( state )
                  {
                   case( 4 *2 + 0 ): 
                     if( true == ::math::geometry::plane::intersect( m_far, pinhole_type::forward(), depth[1], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.second(), m_parametric.origin(), m_far, m_parametric.direction() );
                      } // no break
                   case( 4 *1 + 0 ): 
                     if( true == ::math::geometry::plane::intersect( m_near, pinhole_type::forward(), depth[0], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.first(), m_parametric.origin(), m_near, m_parametric.direction() ); 
                      } goto label_scissors;
                   default: break;
                  }

                 switch( state )
                  {
                   case( 4 *0 + 2 ): 
                     if( true == ::math::geometry::plane::intersect(  m_far, pinhole_type::forward(), depth[1], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.second(), m_parametric.origin(), m_far, m_parametric.direction() );
                      } // no break
                   case( 4 *1 + 2 ): 
                     if( true == ::math::geometry::plane::intersect( m_near, pinhole_type::forward(), depth[0], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.first(), m_parametric.origin(), m_near, m_parametric.direction() );
                      } goto label_scissors;
                   default: break;
                  }

                 switch( state )
                  {
                   case( 4 *0 + 1 ): 
                     if( true == ::math::geometry::plane::intersect( m_far, pinhole_type::forward(), depth[1], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.second(), m_parametric.origin(), m_far, m_parametric.direction() ); 
                      }goto label_scissors;
                   case( 4 *2 + 1 ): 
                     if( true == ::math::geometry::plane::intersect( m_far, pinhole_type::forward(), depth[1], m_parametric ) )
                      {
                       ::math::linear::vector::combine( output.second(), m_parametric.origin(), m_far, m_parametric.direction() );
                      }goto label_scissors;
                   default: break;
                  }

                 label_scissors:
                 m_semi.first()  = pinhole_type::project( output.first()  );
                 m_semi.second() = pinhole_type::project( output.second() );
                 if( 1 != this->m_mold.process( m_trail, m_semi, window ) )
                  {
                   return false;
                  }

                 m_parametric = output;
                 ::math::linear::vector::combine( output.first(),  m_parametric.origin(), this->m_mold.m_near, m_parametric.direction() );
                 ::math::linear::vector::combine( output.second(), m_parametric.origin(), this->m_mold.m_far,  m_parametric.direction() );

                 return true;
                }

             public:
               trail_type const& trail() const
                {
                 return m_trail; 
                }
             private:
               trail_type m_trail;

             private:
               mold_type   m_mold; //!< not correct
               parametric_type m_parametric;
               trail_type m_semi;
               scalar_type m_near; //!< not correct
               scalar_type m_far;  //!< not correct
            };

          template < typename scalar_name >
           bool
           clip
            (
              ::math::geometry::direction::two< scalar_name, 3 >           & two
             ,::math::geometry::interval::structure<scalar_name, 2>   const& window
             ,::math::geometry::interval::structure<scalar_name, 1 >  const& depth
            )
            {
             ::math::geometry::projective::camera::frustum::scissors<scalar_name> scissors;
             return scissors.process( two, two, window, depth );
            }

         }
       }
     }
   }
 }

#endif
