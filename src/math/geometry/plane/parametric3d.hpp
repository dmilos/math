#ifndef math_geometry_plane_parametric3d
#define math_geometry_plane_parametric3d

// ::math::geometry::plane::parametric3d<scalar_name>

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/cross.hpp"
#include "../../linear/vector/length.hpp"
#include "../../linear/vector/inferior.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template < typename scalar_name >
       class ABCD3D;

      template < typename scalar_name >
       class parametric3d;

      template < typename scalar_name >
       class three;

      template
       <
         typename scalar_name = double
       >
       class parametric3d // p = m_origin + u * m_X + v * m_Y;
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::structure<scalar_name,2>  uv_type;
           typedef ::math::linear::vector::structure<scalar_name,3>  point3d_type, point_type;

           typedef ::math::geometry::plane::ABCD3D<scalar_name>              ABCD3D_type;
           typedef ::math::geometry::plane::no3d<scalar_name>                  no3d_type;
           typedef ::math::geometry::plane::parametric3d<scalar_name>  parametric3d_type, this_type;
           typedef ::math::geometry::plane::three<scalar_name>                three_type;

         public:
           parametric3d( )
            {
             // do nothing;
            }

           parametric3d( point_type const& origin, point_type const& X, point_type const& Y )
            :m_origin( origin )
            ,m_X( X )
            ,m_Y( Y )
            {
            }

         public:
           explicit parametric3d( ABCD3D_type const& abcd )
            {
              *this = abcd;
            }

           explicit parametric3d( no3d_type const& no )
            {
              *this = no;
            }

           explicit parametric3d( three_type const& three )
            {
              *this = three;
            }

         public:
           this_type &operator=( ABCD3D_type const& abcd )
            {
             no3d_type no3d;
             no3d = abcd;
             *this = no3d;

             point_type normal;
             point_type origin;
             if(false){
             ::math::linear::vector::load( normal, abcd.A(), abcd.B(), abcd.C() );
             scalar_type dot= ::math::linear::vector::dot( normal, normal ) ;
             scalar_type lambda = -abcd.D()/ dot;
             ::math::linear::vector::scale( this->m_origin, lambda, normal );
             }
             return *this;
            }

           this_type &operator=( no3d_type const& no )
            {
             this->m_origin = no.origin();

             point_type axis; ::math::linear::vector::fill( axis, 0 );
             axis[ ::math::linear::vector::inferior( no.normal() ).first ] = scalar_type( 1 );

             ::math::linear::vector::cross( this->m_Y, no.normal(), axis );
             ::math::linear::vector::length( this->m_Y, scalar_type(1) );

             ::math::linear::vector::cross( this->m_X, this->m_Y, no.normal() );
             ::math::linear::vector::length( this->m_X, scalar_type(1) );

             return *this;
            }

           this_type & operator=( three_type const& three )
            {
             this->origin() = three.p();
             ::math::linear::vector::subtraction( this->x(), three.q(), three.p() );
             ::math::linear::vector::subtraction( this->y(), three.r(), three.p() );
             return *this;
            }

         public:
           void normalize()
            {
             point_type normal;
             ::math::linear::vector::cross( normal, this->x(), this->y() );
             *this = parametric3d( no3d_type( this->m_origin, normal ) );
            }

         public:
           point_type  point( uv_type const& uv )const
            {
             point_type result;
             ::math::linear::vector::combine( result, this->origin(), uv[0], this->x(), uv[1], this->y() );
             return result;
            }

           point_type  point( scalar_type const& u, scalar_type const& v )const
            {
             point_type result;
             ::math::linear::vector::combine( result, this->origin(),     u, this->x(),     v, this->y() );
             return result;
            }

         public:
           point_type const& origin()const
            {
             return m_origin;
            }
           point_type & origin()
            {
             return m_origin;
            }
           void origin( point_type const& O )
            {
             m_origin = O;
            }

         private:
           point_type m_origin;

         public:
           point_type const& x()const
            {
             return m_X;
            }
           point_type & x()
            {
             return m_X;
            }
           void x( point_type const& X )
            {
             m_X = X;
            }

         private:
           point_type m_X;

         public:
           point_type const& y()const
            {
             return m_Y;
            }
           point_type & y()
            {
             return m_Y;
            }
           void y( point_type const& Y )
            {
             m_Y = Y;
            }

         private:
           point_type m_Y;

        };

     }
   }
 }

#endif

