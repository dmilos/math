#ifndef math_polynomial_interpolate_quadric_fit_HPP0_
 #define math_polynomial_interpolate_quadric_fit_HPP0_

 // ::math::polynomial::solve::quadric::fit<scalar_name>.caruana( coefficient, sample )
 // ::math::polynomial::solve::quadric::fit<scalar_name>.hongwei( coefficient, sample )

#include "../../linear/vector/vector.hpp"
#include "../../linear/matrix/invert.hpp"
#include "../../linear/matrix/multiply.hpp"

 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

      template
       <
        typename scalar_name = double
       >
       struct fit // fit along Y axis in form y = c[0] + c[1]*x + c[2] * x^2
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_name,2>    point2d_type;
           typedef ::math::linear::vector::point<scalar_name,3>    point3d_type;
           typedef ::math::linear::matrix::structure<scalar_name,3,3>    matrix_type;

           typedef std::array<scalar_name, 3>    quadric_type;

           typedef std::vector< point2d_type > cloud_type;

           bool caruana( quadric_type & Q, cloud_type const& cloud, scalar_type const& epsilon = 1e-5 )
            {
             ::math::linear::matrix::zero( m_matrix );
             ::math::linear::vector::fill( m_free, 0 );

             for( auto const& sample : cloud )
              {
               auto Y1 = sample[1];
               if( ( -epsilon < Y1 ) && ( Y1 < epsilon ) ) continue;

               auto X1 = sample[0];
               auto X2 = X1 * sample[0];
               auto X3 = X2 * sample[0];
               auto X4 = X3 * sample[0];

               m_matrix[0][0] += X2;  m_matrix[0][1] += X3; m_matrix[0][2] += X4;
               m_matrix[1][0] += X1;  m_matrix[1][1] += X2; m_matrix[1][2] += X3;
               m_matrix[2][0] += 1;   m_matrix[2][1] += X1; m_matrix[2][2] += X2;

               m_free[0] += X2 * Y1;
               m_free[1] += X1 * Y1;
               m_free[2] +=      Y1;
              }

             // TODO find fabs(max) and normalize    m_matrix and  m_free

             if( false == ::math::linear::matrix::invert( m_invert,m_matrix ) )
              {
               return false;
              }

             ::math::linear::matrix::transform( Q, m_invert, m_free );
             return true;
            }

           bool hongwei( quadric_type & Q, cloud_type const& cloud, scalar_type const& epsilon = 1e-5 )
            {
             ::math::linear::matrix::zero( m_matrix );
             ::math::linear::vector::fill( m_free, 0 );

             for( auto const& sample : cloud )
              {
               auto Y1 = sample[1];
               if( ( -epsilon < Y1 ) && ( Y1 < epsilon ) ) continue;

               auto Y2 = Y1 * sample[1];

               auto X1 = sample[0];
               auto X2 = X1 * sample[0];
               auto X3 = X2 * sample[0];
               auto X4 = X3 * sample[0];

               m_matrix[0][0] += Y2 * X2;  m_matrix[0][1] += Y2 * X3; m_matrix[0][2] += Y2 * X4;
               m_matrix[1][0] += Y2 * X1;  m_matrix[1][1] += Y2 * X2; m_matrix[1][2] += Y2 * X3;
               m_matrix[2][0] += Y2;       m_matrix[2][1] += Y2 * X1; m_matrix[2][2] += Y2 * X2;

               m_free[0] += Y2 * X2 * Y1;
               m_free[1] += Y2 * X1 * Y1;
               m_free[2] += Y2 *      Y1;
              }

             // TODO find fabs(max) and normalize    m_matrix and  m_free

             if( false == ::math::linear::matrix::invert( m_invert,m_matrix ) )
              {
               return false;
              }

             ::math::linear::matrix::transform( Q, m_invert, m_free );
             return true;
            }

          private:
            matrix_type m_matrix, m_invert;
            point3d_type m_free;

       };



      }
    }
  }

#endif
