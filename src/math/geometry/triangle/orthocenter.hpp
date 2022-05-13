#ifndef math_geometry_triangle_orthocenter_hpp_
 #define math_geometry_triangle_orthocenter_hpp_

 // ::math::geometry::triangle::orthocenter( result, a, b, c )
 // ::math::geometry::triangle::orthocenter<double>



#include "./structure.hpp"
#include "./area.hpp"
#include "../direction/abc.hpp"
#include "../direction/two.hpp"






 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template< typename scalar_name >
        struct  orthocenter
         {
          public:
            typedef ::math::linear::vector::structure< scalar_name, 2 >          point_type;
            typedef ::math::linear::vector::structure< scalar_name, 3 >    homography_type;
            typedef ::math::geometry::direction::ABC2D<scalar_name>  direction_type;
          public:
            bool
            process
             (
               ::math::linear::vector::structure< scalar_name, 2 >          &   result_param
              ,::math::geometry::triangle::structure< scalar_name, 2 > const& triangle_param
              ,scalar_name const& epsilon = 1e-6
             )
             {
              m_A = { triangle_param[0][0], triangle_param[0][1], 1 }; 
              m_B = { triangle_param[1][0], triangle_param[1][1], 1 }; 
              m_C = { triangle_param[2][0], triangle_param[2][1], 1 };
              m_a = ::math::geometry::direction::two<scalar_name,2>( triangle_param[1], triangle_param[2] ); m_a.normalize();
              m_b = ::math::geometry::direction::two<scalar_name,2>( triangle_param[0], triangle_param[2] ); m_b.normalize();
              m_c = ::math::geometry::direction::two<scalar_name,2>( triangle_param[0], triangle_param[1] ); m_c.normalize();

              m_aT.A() = m_a.B(); m_aT.B() = -m_a.A(); m_aT.C( { m_A[0], m_A[1] } );
              m_bT.A() = m_b.B(); m_bT.B() = -m_b.A(); m_bT.C( { m_B[0], m_B[1] } );
              m_cT.A() = m_c.B(); m_cT.B() = -m_c.A(); m_cT.C( { m_C[0], m_C[1] } );

              ::math::linear::vector::cross( m_oA, m_bT.array(), m_cT.array() ); //!< homography coordinate
              ::math::linear::vector::cross( m_oB, m_aT.array(), m_cT.array() ); //!< homography coordinate
              ::math::linear::vector::cross( m_oC, m_aT.array(), m_bT.array() ); //!< homography coordinate

              if( fabs( m_oA[2] ) < epsilon ) return false;
              if( fabs( m_oB[2] ) < epsilon ) return false;
              if( fabs( m_oC[2] ) < epsilon ) return false;

              m_oA[0] /= m_oA[2]; m_oA[1] /= m_oA[2]; m_oA[2] /= m_oA[2];
              m_oB[0] /= m_oB[2]; m_oB[1] /= m_oB[2]; m_oB[2] /= m_oB[2];
              m_oC[0] /= m_oC[2]; m_oC[1] /= m_oC[2]; m_oC[2] /= m_oC[2];

              // debug m_d0 = ::math::linear::vector::distance( m_oA, m_oB );
              // debug m_d1 = ::math::linear::vector::distance( m_oA, m_oC );
              // debug m_d2 = ::math::linear::vector::distance( m_oB, m_oC );
              result_param[0] = m_oA[0];
              result_param[1] = m_oA[1];
              return true;
             }

            bool process
             (
               ::math::linear::vector::structure< scalar_name, 2 >         &   result_param
              ,::math::geometry::direction::ABC2D<scalar_name>        const& a
              ,::math::geometry::direction::ABC2D<scalar_name>        const& b
              ,::math::geometry::direction::ABC2D<scalar_name>        const& c
              ,scalar_name const& epsilon = 1e-6
             )
             {
              m_a = a; m_b = b; m_c = c;

              ::math::linear::vector::cross( m_A, m_b.array(), m_c.array() );
              ::math::linear::vector::cross( m_B, m_a.array(), m_c.array() );
              ::math::linear::vector::cross( m_C, m_a.array(), m_b.array() );

              m_aT.A() = m_A[2] * m_a.B(); m_aT.B() = m_A[2] * -m_a.A(); m_aT.C() = -( m_a.B() * m_A[0] - m_a.A() * m_A[1] ); m_aT.normalize();
              m_bT.A() = m_B[2] * m_b.B(); m_bT.B() = m_B[2] * -m_b.A(); m_bT.C() = -( m_b.B() * m_B[0] - m_b.A() * m_B[1] ); m_bT.normalize();
              m_cT.A() = m_C[2] * m_c.B(); m_cT.B() = m_C[2] * -m_c.A(); m_cT.C() = -( m_c.B() * m_C[0] - m_c.A() * m_C[1] ); m_cT.normalize();

              ::math::linear::vector::cross( m_oA, m_bT.array(), m_cT.array() ); //!< homography coordinate
              ::math::linear::vector::cross( m_oB, m_aT.array(), m_cT.array() ); //!< homography coordinate
              ::math::linear::vector::cross( m_oC, m_aT.array(), m_bT.array() ); //!< homography coordinate

              if( fabs( m_oA[2] ) < epsilon ) return false;
              if( fabs( m_oB[2] ) < epsilon ) return false;
              if( fabs( m_oC[2] ) < epsilon ) return false;

              m_oA[0] /= m_oA[2]; m_oA[1] /= m_oA[2]; m_oA[2] /= m_oA[2];
              m_oB[0] /= m_oB[2]; m_oB[1] /= m_oB[2]; m_oB[2] /= m_oB[2];
              m_oC[0] /= m_oC[2]; m_oC[1] /= m_oC[2]; m_oC[2] /= m_oC[2];

              // debug m_d0 = ::math::linear::vector::distance( m_oA, m_oB );
              // debug m_d1 = ::math::linear::vector::distance( m_oA, m_oC );
              // debug m_d2 = ::math::linear::vector::distance( m_oB, m_oC );
              result_param[0] = m_oA[0];
              result_param[1] = m_oA[1];
              return true;
             }

          //private:
            direction_type  m_a, m_b, m_c;
            homography_type m_A,  m_B,  m_C;  //!< homography coordinate
            direction_type  m_aT, m_bT, m_cT;
            homography_type m_oA, m_oB, m_oC;  //!< homography coordinate
            // debug scalar_name m_d0, m_d1, m_d2;
        };

     }
   }
 }

#endif
