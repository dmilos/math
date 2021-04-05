#ifndef math_geometry_plane_noNd
#define math_geometry_plane_noNd

// ::math::geometry::plane::noNd<scalar_name, dimension_number>

#include "../../linear/vector/structure.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {
         
      template
       <
         typename scalar_name
       >
       class no3d;


      template
       <
         typename scalar_name = double
        ,unsigned dimension_number = 3
       >
       class noNd // normal _dot_ ( point - normal ) = 0
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_name,dimension_number>   point_type;
           typedef ::math::linear::vector::vector<scalar_name,dimension_number>  vector_type;

           noNd()
            {
            }

           noNd( point_type const& origin, point_type const& normal )
            :m_origin( origin )
            ,m_normal( normal )
            {
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
        private:
          point_type m_origin;

        public:
          point_type const& normal()const
           {
            return m_normal;
           }
          point_type & normal()
           {
            return m_normal;
           }
        private:
          point_type m_normal;
        };

     }
   }
 }

#endif

