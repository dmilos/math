#pragma once

#include <opencv2/opencv.hpp>


namespace Draw
 {


template < typename scalar_name>
 void line( cv::Mat & frame, ::math::geometry::direction::two<scalar_name,2> const& direction, cv::Scalar const& C = cv::Scalar(255,255,255) )
  {
   auto local = direction;
   ::math::geometry::interval::confine( local, { {(scalar_name)0,(scalar_name)0},{ (scalar_name)frame.cols,(scalar_name)frame.rows} } );
   auto const& A = local.first();
   auto const& B = local.second();
   cv::line( frame, cv::Point( (int)A[0], (int)A[1]), cv::Point( (int)B[0], (int)B[1] ), C );
  }

template < typename scalar_name>
 void line( cv::Mat & frame, ::math::geometry::direction::ABC2D<scalar_name> const& direction, cv::Scalar const& C = cv::Scalar(255,255,255 ) )
  {
   Draw::line( frame, ::math::geometry::direction::two<scalar_name, 2>( direction ), C );
  }


 }