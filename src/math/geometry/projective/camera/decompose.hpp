#ifndef math_geometry_projective_camera_decompose
#define math_geometry_projective_camera_decompose

// ::math::geometry::projective::camera::decompose( P )

#include "../../../linear/matrix/row.hpp"
#include "../../../linear/matrix/load.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
        class decompose
         {   // p. 157,  Hartley & Zisserman,  Multiple View Geometry in Computer Vision SE
          public:
            typedef  ::math::linear::matrix::structure<scalar_name,4,3>    matrix4x3_type;
            typedef  ::math::linear::matrix::structure<scalar_name,3,3>    matrix3x3_type;
            typedef  ::math::linear::vector::structure<scalar_name,3> vector3_type;

          public:
            decompose( matrix4x3_type const& P )
             {
              m_M[0][0] = P[0][0];  m_M[1][0] = P[1][0];  m_M[2][0] = P[2][0];
              m_M[0][1] = P[0][1];  m_M[1][1] = P[1][1];  m_M[2][1] = P[2][1];
              m_M[0][2] = P[0][2];  m_M[1][2] = P[1][2];  m_M[2][2] = P[2][2];
              ::math::linear::matrix::row( m_m3, m_M, 2 );
              ::math::linear::matrix::column( m_p4, P, 3 );
             }

            matrix3x3_type const& M()const
             {
              return m_M;
             }

            vector3_type const& center()const
             {
              return m_C;
             }

            vector3_type const& center( bool const& recalc = true ) //!< camera center
             {
              ::math::linear::matrix::invert( m_iM, m_M );
              ::math::linear::matrix::transform( m_C, m_iM, m_p4 );
              ::math::linear::vector::negate( m_C );
              return m_C;
             }

            vector3_type const& ray( bool const& recalc = true )//!< principal axis
             {
              m_det = ::math::linear::matrix::determinant( m_M );
              ::math::linear::vector::scale( m_v, m_det, m_m3 );
              return m_v;
             }

            vector3_type const& x0()const //!< principal point
             {
              return m_x0;
             }
            vector3_type const& x0( bool const& recalc = true )//!< principal point
             {
              ::math::linear::matrix::transform( m_x0, m_M, m_m3 );
              ::math::linear::vector::homogenize( m_x0 );
              return m_x0;
             }

            static vector3_type x0( matrix3x3_type const & K )//!< principal point
             {
              vector3_type result;
              ::math::linear::vector::load( result, K[0][2], K[1][2], K[2][2] );
              ::math::linear::vector::homogenize( result );
              return result;
             }

            bool process()
             {
              auto a = m_M[2][2];
              auto b = m_M[2][1];
              auto d = sqrt( a*a + b*b );
              m_cX = -a/d;
              m_sX = +b/d;
              ::math::linear::matrix::load( m_Qx, { 1, 0, 0 }, { 0, m_cX, -m_sX}, { 0, m_sX, m_cX }  );

              ::math::linear::matrix::multiply( m_K, m_M, m_Qx );

              a = m_K[2][2];
              b = m_K[2][0];
              d = sqrt( a*a + b*b );
              m_cY = +a/d;
              m_sY = +b/d;
              ::math::linear::matrix::load( m_Qy, { m_cY, 0, m_sY }, { 0, 1, 0}, { -m_sY, 0, m_cY }  );

              ::math::linear::matrix::multiply( m_temp, m_K, m_Qy );

              a = m_temp[1][1];
              b = m_temp[1][0];
              d = sqrt( a*a + b*b );
              m_cZ = -a/d;
              m_sZ = +b/d;
              ::math::linear::matrix::load( m_Qz, { m_cZ, -m_sZ, 0 }, { m_sZ, m_cZ, 0 }, { 0, 0, 1 }  );

              ::math::linear::matrix::multiply( m_K, m_temp, m_Qz );
              ::math::linear::matrix::scale( m_K, scalar_name(1)/m_K[2][2] );

              ::math::linear::matrix::multiply( m_temp, m_Qy, m_Qx );
              ::math::linear::matrix::multiply( m_R, m_Qz, m_temp );
              return true;
             }

            matrix3x3_type const& K()const //!< camera matrix
             {
              return m_K;
             }
            matrix3x3_type const& R()const //!< rotation matrix
             {
              return m_R;
             }
            matrix3x3_type const& rotation()const //!< rotation matrix
             {
              return m_R;
             }

            matrix3x3_type const& Qx()const{ return m_Qx; }
            matrix3x3_type const& QY()const{ return m_Qx; }
            matrix3x3_type const& QZ()const{ return m_Qx; }
            vector3_type   const& p4()const{ return m_p4; }

          public:
            matrix3x3_type m_R;  //!< rotation matrix
            matrix3x3_type m_K;  //!< camera matrix

            scalar_name  m_det;   //!< det(M)
            vector3_type m_C;     //!< camera center
            vector3_type m_v;     //!< axis vector
            vector3_type m_x0;    //!< principal point
            matrix3x3_type m_M, m_iM;

            matrix3x3_type m_Qx, m_Qy, m_Qz;
            scalar_name m_cX, m_sX, m_cY, m_sY, m_cZ, m_sZ;
          private:
            vector3_type m_p4;
            vector3_type m_m3;
            matrix3x3_type m_temp;
         };

       }
     }
   }
 }

#endif
