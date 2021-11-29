#ifndef math_geometry_projective_camera_focus_orto3D
#define math_geometry_projective_camera_focus_orto3D

// ::math::geometry::projective::camera::focus::orto2d( f, origin, X, Y )

//#include <utility>



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          /*** Tactical look
                 |           ^
                 |          /|
                 |         / Y
                 |        /  |
                 |       /   +---X--->
                 |      /   /|      /
                 |     /   / |     /
            ----------*---*-+-----*--
                 |   /    /      /
                 F  /  /    /
                 | /
               (0,0)
          */
          template < typename scalar_name >
           bool
           orto2d
            (
              scalar_name                                                & focus
             ,::math::linear::vector::structure< scalar_name, 3 >        & origin //!< ( x, y, p )
             ,std::array< scalar_name, 2 >                          const& X      //!< ( projection , lengthX )
             ,std::array< scalar_name, 2 >                          const& Y      //!< ( projection , lengthY )
            )
            {
             auto const& Xp = X[0];
             auto const& Xl = X[1];
             auto const& Yp = Y[0];
             auto const& Yl = Y[1];

             auto      & Ox = origin[0];
             auto      & Oy = origin[1];
             auto const& Op = origin[2];

             //! F0 = (0,0) + t*( Op, focus );    y = focus/Op * x
             //! Fx = (0,0) + t*( Xp, focus );    y = focus/Xp * x
             //! Fy = (0,0) + t*( Yp, focus );    y = focus/Yp * x
             //! V  = (Ox,0) + t*( 0, 1 );        x = Ox;
             //! H  = (0,Oy) + t*( 1, 0 );        y  =Oy;
             //!
             //!
             //! ( F0 int V ) = ( Ox, Ox * focus/Op )
             //! ( F0 int H ) = ( Oy/(focus/Op), Oy )
             //! ( Fx int H ) = ( Oy/(focus/Xp), Oy )
             //! ( Fy int V ) = ( Ox, Ox * focus/Yp )
             //!
             //!
             //! || ( Fy int V ), ( F0 int V )|| = Yl --> ( Ox, Ox * focus/Yp ) - ( Ox, Ox* focus/Op ) = ( 0, Yl )
             //! Ox = Ox
             //! Yl = Ox * focus/Yp - Ox * focus/Op
             //! (1) = Ox * focus( 1/Yp - 1/Op );
             //!
             //! || ( Fx int H ), ( F0 int V )|| = Xl -->  ( Oy/(focus/Xp), Oy ) - ( Ox, Ox * focus/Op ) = ( Xl, 0 )
             //! (2)Xl = Oy/(focus/Xp) - Ox;
             //! (3)Oy = Ox * focus/Op
             //!
             //! || ( Fy int V ), ( F0 int H )|| = Yl;    ( Ox, Ox * focus/Yp  ) -  ( Oy/(focus/Op), Oy ) = ( 0, Yl )
             //! (4) Ox = Oy/(focus/Op);
             //! (5)Yl = Ox * focus/Yp - Oy;
             //!
             //! || ( Fx int H ), ( F0 int H )|| = Xl ;   ( Oy/(focus/Xp), Oy ) - ( Oy/(focus/Op), Oy ) = ( Xl, 0 );
             //! (6)Xl =  Oy/(focus/Xp) - Oy/(focus/Op)
             //!       = (Oy/focus)  ( 1 / Xp - 1 / Op );
             //!    Oy = Oy

             Ox = Xl*Op/ ( Xp- Op );
             Oy = Yl*Yp/ ( Op- Yp );

             focus       =  Op * (Oy/Ox);

             return true;
            }

         }
       }
     }
   }
 }

#endif
