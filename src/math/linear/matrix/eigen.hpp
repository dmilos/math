#ifndef Dh_math_linear_matrix_eigen
 #define Dh_math_linear_matrix_eigen

 // ::math::linear::matrix::eigen::data<scalar_name,width_number,height_number>
 // ::math::linear::matrix::eigen::algoritham<scalar_name,width_number,height_number>

#include "../../polynomial/quadric/solve.hpp"
#include "../../polynomial/cubic/solve.hpp"


#include "./structure.hpp"
#include "./scale.hpp"
#include "./subtraction.hpp"
#include "./multiply.hpp"
#include "./addition.hpp"

#include "../../linear/vector/structure.hpp"

#include "../../linear/vector/length.hpp"
#include "../../linear/vector/fill.hpp"
#include "../../linear/vector/scale.hpp"
#include "../../linear/vector/load.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {
       namespace eigen
        {

         template< typename scalar_name, ::math::type::size_type dimension_number >
          class data
           {
            public:

              typedef scalar_name scalar_type;
              typedef ::math::type::size_type   size_type;

              typedef ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> matrix_type;
              typedef ::math::linear::vector::structure<scalar_name,dimension_number> vector_type;

              data(){ this->m_count=0; this->m_epsilon = 1e-10; }

           public:
              scalar_type   const& epsilon()const{ return this->m_epsilon; }
              scalar_type        & epsilon()     { return this->m_epsilon; }
            protected:
              scalar_type m_epsilon;

           public:
              vector_type   const&   value()const{ return this->m_value;   }
              matrix_type   const&  vector()const{ return this->m_vector;  }
              size_type     const&   count()const{ return this->m_count;   }
            protected:
              vector_type m_value;
              matrix_type m_vector;
              size_type   m_count;
           };

         template< typename scalar_name, ::math::type::size_type dimension_number >
          class algoritham
           : public ::math::linear::matrix::eigen::data< scalar_name, dimension_number >
           {
            public:
              typedef scalar_name scalar_type;
              typedef ::math::linear::matrix::eigen::data< scalar_name, dimension_number > data_type;

              typedef typename data_type::matrix_type  matrix_type;
              typedef typename data_type::vector_type  vector_type;

              bool process( matrix_type const& )
               {
                return 0;
               }

           };

         template< typename scalar_name >
          class algoritham< scalar_name, 2 >
           : public ::math::linear::matrix::eigen::data< scalar_name, 2 >
           {  //! https://en.wikipedia.org/wiki/Eigenvalue_algorithm#2.C3.972_matrices
            public:
              typedef scalar_name scalar_type;

              typedef ::math::linear::matrix::eigen::data< scalar_name, 2 > data_type;

              typedef typename data_type::size_type      size_type;
              typedef typename data_type::vector_type  vector_type;
              typedef typename data_type::matrix_type  matrix_type;

              size_type process( matrix_type const&m )
               {
                static matrix_type s_I{ 1,0, 0,1 };

                scalar_type const& a_00 = m[0][0];
                scalar_type const& a_01 = m[0][1];
                scalar_type const& a_10 = m[1][0];
                scalar_type const& a_11 = m[1][1];

                scalar_type coefficient[ 3 ] =
                 {
                   a_00*a_11-a_01*a_10
                  ,(-a_11-a_00)
                  , 1
                 };

                this->m_count = ::math::polynomial::quadric::solve::general<scalar_name>( this->m_value.data(), coefficient, this->m_epsilon );

                if( 0 == this->m_count )
                 {
                  return false;
                 }

                matrix_type tmp;
                if( 1 == this->m_count )
                 {
                  ::math::linear::matrix::scale( tmp, this->m_value[0], s_I );
                  ::math::linear::matrix::subtraction( tmp, m, tmp );
                  ::math::linear::vector::load<scalar_type>( this->m_vector[0], tmp[0][0], tmp[1][0] );
                  ::math::linear::vector::length<scalar_type>( this->m_vector[0], 1 );
                  return this->m_count;
                 }

                ::math::linear::matrix::scale( tmp, this->m_value[1], s_I );
                ::math::linear::matrix::subtraction( tmp, m, tmp );
                ::math::linear::vector::load<scalar_type>( this->m_vector[0], tmp[0][0], tmp[1][0] );
                ::math::linear::vector::length<scalar_type>( this->m_vector[0], 1 );

                ::math::linear::matrix::scale( tmp, this->m_value[0],  s_I );
                ::math::linear::matrix::subtraction( tmp, m, tmp );
                ::math::linear::vector::load<scalar_type>( this->m_vector[1], tmp[0][0], tmp[1][0] );
                ::math::linear::vector::length<scalar_type>( this->m_vector[1], 1 );

                return this->m_count;
               }

           };

         template< typename scalar_name >
          class algoritham< scalar_name, 3 >
           : public ::math::linear::matrix::eigen::data< scalar_name, 3 >
           {
            public:
              typedef scalar_name scalar_type;
              typedef ::math::linear::matrix::eigen::data< scalar_name, 3 > data_type;

              typedef typename data_type::size_type      size_type;
              typedef typename data_type::matrix_type  matrix_type;
              typedef typename data_type::vector_type  vector_type;

              typedef ::math::linear::matrix::eigen::algoritham< scalar_name, 3 > this_type;

              size_type process( matrix_type const&m )
               {
                scalar_type const& a_00 = m[0][0];
                scalar_type const& a_01 = m[0][1];
                scalar_type const& a_02 = m[0][2];

                scalar_type const& a_10 = m[1][0];
                scalar_type const& a_11 = m[1][1];
                scalar_type const& a_12 = m[1][2];

                scalar_type const& a_20 = m[2][0];
                scalar_type const& a_21 = m[2][1];
                scalar_type const& a_22 = m[2][2];

                scalar_type coefficient[ 4 ] =
                 {
                   -(a_00*a_11-a_01*a_10)*a_22-(a_02*a_10-a_00*a_12)*a_21-(a_01*a_12-a_02*a_11)*a_20
                  ,-((-a_11-a_00)*a_22+a_12*a_21+a_02*a_20-a_00*a_11+a_01*a_10)
                  ,-(a_22+a_11+a_00)
                  ,1
                 };

                int count = ::math::polynomial::cubic::solve::general<scalar_type>( this->m_value.data(), coefficient, this->m_epsilon );

                if( 0 == count )
                 {
                  return this->m_count = count;
                 }

                if( 1 == count )
                 {
                  static matrix_type s_I{ 1,0,0, 0,1,0, 0,0,1 };

                  coefficient[0] = - coefficient[0] / this->m_value[0];
                  coefficient[1] =  coefficient[2] + this->m_value[0];
                  coefficient[2] = 1;

                  matrix_type tmp0, tmp1, tmp2;

                 ::math::linear::matrix::multiply( tmp0, m,  m );
                 ::math::linear::matrix::scale( tmp1, coefficient[1],  m );
                 ::math::linear::matrix::scale( tmp2, coefficient[0], s_I );
                 ::math::linear::matrix::addition( tmp0, tmp1 );
                 ::math::linear::matrix::addition( tmp0, tmp2 );

                  extract( this->m_vector[0], tmp0, this->m_epsilon );

                  return this->m_count = count;
                 }

                if( -3 == count )
                 { // TODO
                  this->m_vector[0]={1,0,0};
                  this->m_vector[1]={0,1,0};
                  this->m_vector[2]={0,0,1};
                  return this->m_count = - count;
                 }

                this_type::make( this->m_vector[0], m, this->m_value[1] , this->m_value[2], this->m_epsilon );
                this_type::make( this->m_vector[1], m, this->m_value[0] , this->m_value[2], this->m_epsilon );
                this_type::make( this->m_vector[2], m, this->m_value[0] , this->m_value[1], this->m_epsilon );

                if( 2 == count )
                 {
                  return this->m_count = count;
                 }

                if( -2 == count )
                 {
                  // TODO
                  return this->m_count = - count;
                 }

                return this->m_count = count;
               }

             private:
              static bool extract( vector_type & result, matrix_type const& tmp, scalar_type const& epsilon )
               {
                vector_type v[3]=
                 {
                   tmp[0][0], tmp[1][0], tmp[2][0]
                  ,tmp[0][1], tmp[1][1], tmp[2][1]
                  ,tmp[0][2], tmp[1][2], tmp[2][2]
                 };
                scalar_type l[3] =
                 {
                   ::math::linear::vector::length( v[0] )
                  ,::math::linear::vector::length( v[1] )
                  ,::math::linear::vector::length( v[2] )
                 };

                ::math::type::size_type index =0;
                if( l[index] < l[1] ){ index = 1; }
                if( l[index] < l[2] ){ index = 2; }

                if( l[index] < epsilon )
                 {
                  return false;
                 }

                ::math::linear::vector::scale( result, scalar_type(1)/l[index], v[index] );

                return true;
               }

              static bool make( vector_type & result, matrix_type const& m, scalar_type const& alpha0 , scalar_type const& alpha1, scalar_type const& epsilon )
               {
                static matrix_type s_I{ 1,0,0, 0,1,0, 0,0,1 };
                matrix_type tmp0, tmp1, tmp2;

                ::math::linear::matrix::scale( tmp1, alpha0,  s_I );
                ::math::linear::matrix::subtraction( tmp1, m, tmp1 );
                ::math::linear::matrix::scale( tmp2, alpha1,  s_I );
                ::math::linear::matrix::subtraction( tmp2, m, tmp2 );
                ::math::linear::matrix::multiply( tmp0, tmp2, tmp1 );

                return this_type::extract( result, tmp0, epsilon );
               }

           };

        }
      }
    }
  }

#endif



/*
[
 [[-(sqrt(DELTA)-a_11-a_00)/2,(sqrt(DELTA)+a_11+a_00)/2],
  [1,1]],
 [[[1,-(sqrt(DELTA)-a_11+a_00)/(2*a_01)]],[[1,(sqrt(DELTA)+a_11-a_00)/(2*a_01)]]]


]*/