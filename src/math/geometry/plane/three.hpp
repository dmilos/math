#ifndef math_geometry_plane_three
#define math_geometry_plane_three

// ::math::geometry::plane::three<scalar_name>
#include <array>
#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/inferior.hpp"




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
       class three
        {
         public:

           typedef unsigned      size_type;
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::structure<scalar_name,3>  point3d_type, point_type;
           typedef std::array<scalar_type,4> array_type;

           typedef ::math::geometry::plane::ABCD3D<scalar_name>              ABCD3D_type;
           typedef ::math::geometry::plane::no3d<scalar_name>                  no3d_type;
           typedef ::math::geometry::plane::parametric3d<scalar_name>  parametric3d_type;
           typedef ::math::geometry::plane::three<scalar_name>                three_type, this_type;

         public:
           explicit three()
            {
             // do nothing;
            }
           explicit three( point3d_type const& p0, point3d_type const& p1, point3d_type const& p2 )
            {
             m_point[0] = p0;
             m_point[1] = p1;
             m_point[2] = p2;
            }

         public:
           explicit three( ABCD3D_type const& no3d )
            {
             *this = no3d;
            }

           explicit three( no3d_type const& no3d )
            {
             *this = no3d;
            }

           explicit three( parametric3d_type const& parametric )
            {
             *this = parametric;
            }

         public:
           this_type & operator=( ABCD3D_type const& abcd  )
            {// TODO
             no3d_type no3d { abcd };
             *this = no3d;
             return *this;
            }

           this_type & operator=( no3d_type const& no3d )
            { // TODO check
             this->p() = no3d.origin(); 
             ::math::linear::vector::addition( this->q(), no3d.origin(), no3d.normal() );
             point3d_type axis; ::math::linear::vector::fill( axis, 0 );
             axis[ ::math::linear::vector::inferior(  no3d.normal() ).first ] = 1;
             point3d_type tmp; ::math::linear::vector::cross( tmp, no3d.normal(), axis );
             ::math::linear::vector::cross( this->r(), no3d.normal(), tmp );
             ::math::linear::vector::addition( this->r(), no3d.origin() );
             return *this; 
            }

           this_type & operator=( parametric3d_type const& parametric )
            {
             this->p() = parametric.origin();
             ::math::linear::vector::addition( this->q(), parametric.origin(), parametric.x() );
             ::math::linear::vector::addition( this->r(), parametric.origin(), parametric.y() );
             return *this;
            }

         public:
           point_type const& p()const{ return m_point[0]; }
           point_type      & p()     { return m_point[0]; }
           point_type const& q()const{ return m_point[1]; }
           point_type      & q()     { return m_point[1]; }
           point_type const& r()const{ return m_point[2]; }
           point_type      & r()     { return m_point[2]; }

           //void set( std::array<vector3_type,3> const& a )
           // {
           //  //this->p() = array[0];
           //  //this->q() = array[1];
           //  //this->r() = array[2];
           // }

           template< unsigned index_number >
            point3d_type const& get()const
             {
              return m_point[index_number];
             }

           point3d_type const& operator[]( size_type const& index )const
            {
             return m_point[ index ];
            }

        private:
           point3d_type m_point[3];
        };

     }
   }
 }

#endif
