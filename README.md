# Miscellaneous mathematical structures and function

### Status:
- Some kind of Beta.

### Description
 - Yet another c++ library with various mathematical structures and function.

### Key features:
 - Headers only
  - One file to include to start the fun
  - Primitives: circle, direction, ellipse, interval, plane, quadric, tetrahedron, triangle
  - Function:
    - vector, matrix, affine operation
    - distances, intersections between primitives
  - No external dependence, out of the box ready.
  - etc.

### Code sample
```c++

#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  ::math::linear::vector::point<double,2>   point{100,100};
  ::math::geometry::direction::parametric<double,2>   direction({ 5,5}, { 1,2});

  ::math::geometry::ellipse::base2D<double>     b{ 20, 30 };
  ::math::geometry::ellipse::simple2D<double>   s{ {10, 15}, 20, 30   };
  ::math::geometry::ellipse::general2D<double>  g{ {10, 15}, 20, 30, ::math::geometry::deg2rad( 60 ) };

  // Convert from one representation to another
   g = g;  g= s;   g = b;
           s = s;  s = b;

  ::math::geometry::ellipse::distance( b, point );
  ::math::geometry::ellipse::distance( s, point );
  ::math::geometry::ellipse::distance( g, point );

  double l0, l1;

  ::math::geometry::ellipse::intersect( l0, l1, b, direction );
  ::math::geometry::ellipse::intersect( l0, l1, s, direction );
  ::math::geometry::ellipse::intersect( l0, l1, g, direction );

  cin.get();
  return EXIT_SUCCESS;
 }

```

### Install:
1. Clone this Repository: \
  Examples:
    - Windows : git clone https://github.com/dmilos/math.git c:\my-work-folder\my-git-folder\math
    - Linux   : git clone https://github.com/dmilos/math.git /home/my-user-name/my-work-folder/my-git-folder/math
2. Inform compiler where to find headers: \
  Examples:
   - MSVC : /Ic:\my-work-folder\my-git-folder\math\src
   - gcc  : -I/home/my-user-name/my-work-folder/my-git-folder/math/src

### Content in details:
  - complex
    - quaternion
      * quaternion arithmetic
  - function
      * N dimensional Lebesgue/Z functions
  - geometry
    - circle
      * Different circle structures, intersections with direction
    - direction
      * Direction structures and manipulation
    - ellipse
      * Ellipse structures and manipulation
    - interval
      * Interval structures and manipulation
    - plane
      * Plane structures and manipulation
    - projective
      * Epipolar functions.
    - quadric
      * create quadric from circle and ellipse
    - tetrahedron
      * Calculate volume
    - triangle
      * Calculate area
  - grammar
  - linear
   - affine
      * Affine structure and manipulation ( addition, subtraction, compose, etc. )
   - homography
      * Make and transform functions
   - matrix
       * Matrix structure and manipulation ( addition, subtraction, compose, etc. )
   - vector
      * Vector manipulation
  - logic
      * Empty so far
  - polynomial
      * Polynomial manipulation
  - random
      * Sobol and vdc functions
  - statistic
      * Gaussian, average, count.

### Tested against:
  - GCC 12.4.0
  - MSVC 2022 (17.4.4)

