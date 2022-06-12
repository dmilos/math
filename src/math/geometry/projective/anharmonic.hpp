#ifndef math_geometry_projective_anharmonic
#define math_geometry_projective_anharmonic

// ::math::geometry::projective::anharmonic::value( A, B, C, D )
// ::math::geometry::projective::anharmonic::D( A, B, C, coefficient )



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace anharmonic //!< cross-ratio, double-ratio
       {

       template<  typename scalar_name >
        scalar_name value  //!< calculate
         (
           scalar_name const& A //!< position on real line
          ,scalar_name const& B //!< position on real line
          ,scalar_name const& C //!< position on real line
          ,scalar_name const& D //!< position on real line
         )
         {
          scalar_name dividend = ( A - C ) * ( B - D );
          scalar_name divisor  = ( B - C ) * ( A - D );

          return dividend / divisor;
         }

       template<  typename scalar_name >
        scalar_name value  //!< calculate
         (
           scalar_name const& a //!< length of line
          ,scalar_name const& b //!< length of line
          ,scalar_name const& c //!< length of line
         )
         {
          scalar_name dividend = ( a + b ) * ( b + c );
          scalar_name divisor  = ( a + b + c ) * b;

          return dividend / divisor;
         }


       template<  typename scalar_name >
        scalar_name infinity  //!< calculate when D is in infinity
         (
           scalar_name const& A //!< position on real line
          ,scalar_name const& B //!< position on real line
          ,scalar_name const& C //!< position on real line
         )
         {
          scalar_name dividend = ( A - C );
          scalar_name divisor  = ( B - C );

          return dividend / divisor;
         }

       template<  typename scalar_name >
        scalar_name a  //!< solve anharmonic where a is unknown
         (
           scalar_name const& b //!< length of BC
          ,scalar_name const& c //!< length of CD
          ,scalar_name const& coefficient
         )
         {
          scalar_name dividend =  b*(b+c)*(coefficient-1);
          scalar_name divisor  = b+c-coefficient*b;

          return dividend / divisor;
         }

       template<  typename scalar_name >
        scalar_name b  //!< solve anharmonic where b is unknown
         (
           scalar_name const& a //!< length of AB
          ,scalar_name const& c //!< length of CD
          ,scalar_name const& coefficient
          ,scalar_name const& epsilon = 1e-6
         )
         {
          scalar_name a2 = 1 - coefficient;
          scalar_name a1 = (a+c)*( 1-coefficient);
          scalar_name a0 = a*c;
          if( ( -epsilon < a2  ) && ( a2 < +epsilon ) ) return -1;
          scalar_name D = a1*a1 - 4 * a2 * a0;

          scalar_name result;
          if( D < -epsilon )
           {
            return -1;
           }
          if( D < +epsilon )
           {
            result = - a1 / ( 2 * a2 );
            if( +epsilon < result ) return result;
            return -1;
           }
          D = sqrt( D );
          result = (- a1 - D ) / ( 2 * a2 );
          if( +epsilon < result ) return result;
          result = (- a1 + D ) / ( 2 * a2 );
          if( +epsilon < result ) return result;

          return -1;
         }

       template<  typename scalar_name >
        scalar_name c  //!< solve anharmonic where c is unknown
         (
           scalar_name const& a //!< length of AB
          ,scalar_name const& b //!< length of BC
          ,scalar_name const& coefficient
         )
         {
          scalar_name dividend =  b*(b+a)*(coefficient-1);
          scalar_name divisor  = b+a-coefficient*b;

          return dividend / divisor;
         }

       template<  typename scalar_name >
        scalar_name A  //!< solve anharmonic where A is unknown
         (
           scalar_name const& B //!< position on real line
          ,scalar_name const& C //!< position on real line
          ,scalar_name const& D //!< position on real line
          ,scalar_name const& coefficient
         )
         {
          scalar_name bc = C-B;
          scalar_name bd = D-B;

          scalar_name dividend = bd*bc*( coefficient - 1 );
          scalar_name divisor  = bd - coefficient * bc;

          return B - dividend / divisor;
         }

       template<  typename scalar_name >
        scalar_name B  //!< solve anharmonic  where B is unknown
         (
           scalar_name const& A //!< position on real line
          ,scalar_name const& C //!< position on real line
          ,scalar_name const& D //!< position on real line
          ,scalar_name const& coefficient
         )
         {
          scalar_name ac = C-A;
          scalar_name cd = D-C;
          scalar_name ad = D-A;

          scalar_name dividend = ac*cd ;
          scalar_name divisor  = coefficient * ad - ac;

          return C - dividend / divisor;
         }

       template
         <
          typename scalar_name = double
         >
        scalar_name C  //!< solve anharmonic where C is unknown
         (
           scalar_name const& A //!< position on real line
          ,scalar_name const& B //!< position on real line
          ,scalar_name const& D //!< position on real line
          ,scalar_name const& coefficient
         )
         {
          scalar_name ab = B-A;
          scalar_name bd = D-B;
          scalar_name ad = D-A;

          scalar_name dividend = ab*bd;
          scalar_name divisor  = coefficient * ad - bd;

          return B + dividend / divisor;
         }


       template<  typename scalar_name >
        scalar_name D  //!< solve anharmonic_D ratio
         (
           scalar_name const& A //!< position on real line
          ,scalar_name const& B //!< position on real line
          ,scalar_name const& C //!< position on real line
          ,scalar_name const& coefficient
         )
         {
          scalar_name ab = B-A;
          scalar_name bc = C-B;
          scalar_name ac = C-A;

          scalar_name dividend = ac*bc*( 1 - coefficient );
          scalar_name divisor  = coefficient * bc - ac;

          return C + dividend / divisor;
         }

       }
     }
   }
 }

#endif
