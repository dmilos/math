#ifndef math_geometry_projective_camera_focus_semi
#define math_geometry_projective_camera_focus_semi

// ::math::geometry::projective::camera::focus::semi(  )

#include "../../../../linear/vector/structure.hpp"
#include "../../../../linear/vector/dot.hpp"
#include "../../../../statistic/average.hpp"


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
           class semi1D //!< any distance from 2D optical to image plane.
            {    //! TODO delete
             public:

               typedef scalar_name   scalar_type;
               typedef ::math::linear::vector::structure< scalar_name, 2 >  point_type;
               typedef ::math::geometry::direction::ABC2D<scalar_name>       ABC2D_type;

               semi1D(  )
                {
                 m_scale.push(5); m_scaleA = 5;
                 m_focus.push(0.5); m_focusA = 0.5;
                }

             public:

               bool process(  scalar_type const& semi_focusA, scalar_name const& distanceA
                             ,scalar_type const& semi_focusB, scalar_name const& distanceB  )
                {
                 auto F = m_focus.value();
                 m_scale.push( sqrt( fabs(semi_focusA*semi_focusA - semi_focusB*semi_focusB ) / fabs( distanceA*distanceA -distanceB*distanceB ) ) );
                 auto S = m_scale.value();
                 m_focus.push( sqrt( fabs( semi_focusA * semi_focusA -distanceA*distanceA*S*S ) ) );
                 m_focus.push( sqrt( fabs( semi_focusB * semi_focusB -distanceB*distanceB*S*S ) ) );

                 m_scaleA += ( sqrt( fabs(semi_focusA*semi_focusA - semi_focusB*semi_focusB ) / fabs( distanceA*distanceA -distanceB*distanceB ) ) );
                 m_scaleA /=2;
                 S = m_scaleA;
                 m_focusA +=( sqrt( fabs( semi_focusA * semi_focusA -distanceA*distanceA*S*S ) ) );
                 m_focusA +=( sqrt( fabs( semi_focusB * semi_focusB -distanceB*distanceB*S*S ) ) );
                 m_focusA /=3;
                 return true;
                }

               bool process(  scalar_type const& semi_focusA, scalar_name const& distanceA
                             ,scalar_type const& semi_focusB, scalar_name const& distanceB 
                             ,scalar_type const& semi_focusC, scalar_name const& distanceC 
                 )
                {
                 return true;
                }

             public:
               void reset ( scalar_type const & F, scalar_type const& S )
                { 
                  m_focus.reset(F,1); 
                  m_scale.reset(S,1); 
                }
               //scalar_type focus()const{ return m_focus.value(); }
               //scalar_type scale()const{ return m_scale.value(); }
               scalar_type focus()const{ return m_focusA; }
               scalar_type scale()const{ return m_scaleA; }

             private:
               ::math::statistic::average<scalar_type,1, std::size_t >  m_scale;
               ::math::statistic::average<scalar_type,1, std::size_t >  m_focus;
               scalar_type m_focusA;
               scalar_type m_scaleA;

             public:
               point_type m_principal;
            };

         }
       }
     }
   }
 }

#endif
