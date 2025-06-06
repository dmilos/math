#ifndef math_geometry_plane_ABCD3D
#define math_geometry_plane_ABCD3D

// ::math::geometry::plane::ABCD3D<scalar_name>
#include <array>
#include "../../linear/vector/structure.hpp"





namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template < typename scalar_name >
       class ABCD3D;

      //template< typename scalar_name >
      //  class no3d;

      template < typename scalar_name >
       class parametric3d;

      template < typename scalar_name >
       class three;

      template
       <
         typename scalar_name = double
       >
       class ABCD3D // A * x  +  B * y+  C * y  +  D = 0
        {
         public:

           typedef unsigned      size_type;
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::structure<scalar_name,3>  point3d_type, point_type, vector3d_type;
           typedef std::array<scalar_type,4> array_type;

           typedef ::math::geometry::plane::ABCD3D<scalar_name>              ABCD3D_type, this_type;
           typedef ::math::geometry::plane::no3d<scalar_name>                  no3d_type;
           typedef ::math::geometry::plane::parametric3d<scalar_name>  parametric3d_type;
           typedef ::math::geometry::plane::three<scalar_name>                three_type;

         public:
           explicit ABCD3D( scalar_type const& A=0, scalar_type const& B=0, scalar_type const& C=0, scalar_type const& D=0 )
            :m_A(A)
            ,m_B(B)
            ,m_C(C)
            ,m_D(D)
            {
            }

           explicit ABCD3D( array_type const& array )
            :m_A( array[0] )
            ,m_B( array[1] )
            ,m_C( array[2] )
            ,m_D( array[2] )
            {
            }

         public:
           explicit ABCD3D( no3d_type const& no3d )
            {
             *this = no3d;
            }

           explicit ABCD3D( parametric3d_type const& parametric )
            {
             *this = parametric;
            }

           explicit ABCD3D( three_type const& three )
            {
             *this = three;
            }

         public:
           this_type & operator=( no3d_type const& no3d )
            {
             this->A() = no3d.normal()[0];
             this->B() = no3d.normal()[1];
             this->C() = no3d.normal()[2];
             this->D() = - ::math::linear::vector::dot( no3d.normal(), no3d.origin() );
             return *this;
            }

           this_type & operator=( parametric3d_type const& parametric )
            {
             vector3d_type normal;
            ::math::linear::vector::cross( normal, parametric.x(), parametric.y() );

             this->A() = normal[0];
             this->B() = normal[1];
             this->C() = normal[2];
             this->D() = - ::math::linear::vector::dot( normal, parametric.origin() );

             return *this;
            }

           this_type & operator=( three_type const& three )
            {
             vector3d_type x; ::math::linear::vector::subtraction( x, three.q(), three.p() );
             vector3d_type y; ::math::linear::vector::subtraction( y, three.r(), three.p() );

             vector3d_type normal; ::math::linear::vector::cross( normal, x, y );

             this->A() = normal[0];
             this->B() = normal[1];
             this->C() = normal[2];
             this->D() = - ::math::linear::vector::dot( normal, three.p() );

             return *this;
            }

         public:
           void set( array_type const& array )
            {
             this->A() = array[0];
             this->B() = array[1];
             this->C() = array[2];
             this->D() = array[3];
            }

           template< unsigned index_number >
            scalar_type const& get()const
             {
             switch( index_number )
              {
               default:
               case( 0 ): return this->A();
               case( 1 ): return this->B();
               case( 2 ): return this->C();
               case( 3 ): return this->D();
              }
             }

           scalar_type const& operator[]( size_type const& index )const
            {
             switch( index )
              {
               default:
               case( 0 ): return this->A();
               case( 1 ): return this->B();
               case( 2 ): return this->C();
               case( 3 ): return this->D();
              }
            }

           this_type  normalize()const
            {
             this_type result;
             scalar_type E = sqrt( this->A() * this->A()  +  this->B() * this->B()  +  this->C() * this->C() );
             result.A() = this->A() / E;
             result.B() = this->B() / E;
             result.C() = this->C() / E;
             result.D() = this->C() / E;
             return result;
            }

           this_type & normalize()
            {
             scalar_type E = sqrt( this->A() * this->A()  +  this->B() * this->B()  +  this->C() * this->C() );
             this->A() /= E;
             this->B() /= E;
             this->C() /= E;
             this->D() /= E;
             return *this;
            }

        public:
          scalar_type const& A()const{ return m_A; }
          scalar_type      & A()     { return m_A; }
          scalar_type const& B()const{ return m_B; }
          scalar_type      & B()     { return m_B; }
          scalar_type      & C()     { return m_C; }
          scalar_type const& C()const{ return m_C; }
          scalar_type      & D()     { return m_D; }
          scalar_type const& D()const{ return m_D; }
        private:
           // A * x  +  B * y+  C * y  +  D = 0
           scalar_type m_A, m_B, m_C, m_D; //!< convert to array_type
        };

     }
   }
 }

#endif

