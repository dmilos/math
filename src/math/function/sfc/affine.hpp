#ifndef math_function_sfc_affine
#define math_function_sfc_affine

// ::math::function::sfc::direct( result, center, corner, x )
// ::math::function::sfc::invert( result, center, corner, x )

#include "../../linear/vector/structure.hpp"


namespace math
 {
  namespace function
   {
    namespace sfc   //!< space filling curve
    {

     template < typename scalar_name >
      void direct
       (
         ::math::linear::affine::structure<scalar_name, 2 >   & result
        ,::math::linear::vector::point<scalar_name,2 >    const& lo  //!< leading corner
        ,::math::linear::vector::point<scalar_name, 2 >   const& hi  //!< oposite corner
        ,::math::linear::vector::vector<scalar_name, 2 >  const& size  //! cublet size 
        ,::math::linear::vector::vector<scalar_name, 2 >          x  //!< WARNING must be scaled
       )
       { // any to zero-cube
        typedef ::math::linear::vector::point<scalar_name,2> vector_type;

        static vector_type zero{ 0, 0 };
        static vector_type one{ 1, 1 };
        static vector_type X{ 1, 0 };

        ::math::linear::vector::addition( x, lo );
        ::math::linear::affine::construct( result, { lo, x, hi }, { zero, X, one } );
       }

     template < typename scalar_name >
      void invert
       (
         ::math::linear::affine::structure<scalar_name, 2 >   & result
        ,::math::linear::vector::point<scalar_name,2 >    const& lo  //!< leading corner
        ,::math::linear::vector::point<scalar_name, 2 >   const& hi  //!< oposite corner
        ,::math::linear::vector::vector<scalar_name, 2 >  const& size  //! cublet size 
        ,::math::linear::vector::vector<scalar_name, 2 >         x //!< WARNING must be scaled
       )
       { // zero-cube to any
        typedef ::math::linear::vector::point<scalar_name,2> vector_type;

        static vector_type zero{ 0, 0 };
        static vector_type one{ 1, 1 };
        static vector_type X{ 1, 0 };
        //static vector_type Y{ 0.0, 1.0 };
        //vector_type y;

        ::math::linear::vector::addition( x, lo );
        ::math::linear::affine::construct( result, { zero, X, one }, { lo, x, hi } );
      }

    template < typename scalar_name >
     void direct
      (
        ::math::linear::affine::structure<scalar_name, 3 >   & result
       ,::math::linear::vector::point<scalar_name,3 >    const& lo  //!< leading corner
       ,::math::linear::vector::point<scalar_name, 3 >   const& hi  //!< oposite corner
       ,::math::linear::vector::vector<scalar_name, 3 >  const& size  //! cublet size 
       ,::math::linear::vector::vector<scalar_name, 3>       x //!< WARNING must be scaled
       ,::math::linear::vector::vector<scalar_name, 3>        y //!< WARNING must be scaled
      )
      {  // big to small
       typedef ::math::linear::vector::point<scalar_name, 3> vector_type;

       static vector_type zero{ 0, 0, 0 };
       static vector_type one{ 1, 1, 1 };
       static vector_type X{ 1, 0, 0 };
       static vector_type Y{ 0, 1, 0 };

       ::math::linear::vector::addition( x, lo );
       ::math::linear::vector::addition( y, lo );
       ::math::linear::affine::construct( result, { lo, x, y, hi }, { zero, X, Y, one } );
     }

    template < typename scalar_name >
     void invert
      (
        ::math::linear::affine::structure<scalar_name, 3 >   & result
       ,::math::linear::vector::point<scalar_name,3 >    const& lo  //!< leading corner
       ,::math::linear::vector::point<scalar_name, 3 >   const& hi  //!< oposite corner
       ,::math::linear::vector::vector<scalar_name, 3 >  const& size  //! cublet size 
       ,::math::linear::vector::vector<scalar_name, 3>       x //!< WARNING must be scaled
       ,::math::linear::vector::vector<scalar_name, 3>       y //!< WARNING must be scaled
      )
      {  // small to big
       typedef ::math::linear::vector::point<scalar_name, 3> vector_type;

       static vector_type zero{ 0, 0, 0 };
       static vector_type one{ 1, 1, 1 };
       static vector_type X{ 1, 0, 0 };
       static vector_type Y{ 0, 1, 0 };

       ::math::linear::vector::addition( x, lo );
       ::math::linear::vector::addition( y, lo );
       ::math::linear::affine::construct( result, { zero, X, Y, one }, { lo, x, y, hi } );
     }
     }
   }
 }

#endif
