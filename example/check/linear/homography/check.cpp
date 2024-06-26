#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

#include "math/math.hpp"

template< typename scalar_name, math::type::size_t width_number, math::type::size_t height_number >
 void monic( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
  {
   scalar_name maximal = fabs( m[0][0] );
   for( unsigned j=0; j< width_number; j++ )
    {
     for( unsigned i=0; i< height_number; i++ )
      {
       maximal = std::max<scalar_name>( fabs( m[j][i] ), maximal );
      }
    }

   // if( maximal < epsilon  ) return;
   for( unsigned j=0; j< width_number; j++ )
    {
     for( unsigned i=0; i< height_number; i++ )
      {
        m[j][i] /= maximal;
      }
    }
  }

template< typename scalar_name, math::type::size_t width_number, math::type::size_t height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m, std::string const& comment = "" )
  {
   std::cout << comment << "{" ;
   for( unsigned j=0; j< width_number; j++ )
    {
     std::cout << std::endl << "    ";
     for( unsigned i=0; i< height_number; i++ )
      {
       std::cout << "" << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
   std::cout << std::endl;
   std::cout << "}" << std::endl;
  }

template< typename scalar_name, math::type::size_t dimension_number >
 void print ( ::math::linear::vector::structure<scalar_name,dimension_number> const& v )
  {
   std::cout << "{" ;

   for( unsigned i=0; i< dimension_number; i++ )
    {
     std::cout << "" << std::setw(10) << std::fixed << v[i] << ", ";
    }

   std::cout << "}" ;
  }


template< typename scalar_name, math::type::size_t dimesion_number>
 void apply
  (
    ::math::linear::homography::structure<scalar_name,dimesion_number> const& m
   ,::math::linear::vector::structure<scalar_name,dimesion_number>     const& v
  )
 {
  ::math::linear::vector::structure<scalar_name,dimesion_number> r;

  ::math::linear::homography::transform( r, m, v );
   print( v ); std::cout << " == >> "; print( r ); std::cout << " ; "; ;
 }

void hg1()
 {
  std::cout << " --- 1D --- "   << std::endl;
  typedef ::math::linear::homography::structure<double,1>  homography1_type;

  homography1_type h1;

  ::math::linear::homography::construct<double>( h1, 0.5, 1.0 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.4, 1.0 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.5, 1.0 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.6, 1.0 );
  print( h1 );
 }
 
void hg1_definition()
 {
  std::cout << " --- 2D ---   By definition ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,1>  homography2_type;
  typedef ::math::geometry::direction::parametric<double, 2>  direction_type;
  typedef ::math::linear::vector::structure< double, 2 >  point_type;


  homography2_type result;
  point_type center{0,0};
  direction_type target( { 0,1 }, {1,0} );
  direction_type source( { 0,1 }, {1,0} );

  ::math::linear::homography::construct( result, source );
  ::math::linear::homography::construct_invert( result, source );
  ::math::linear::homography::construct( result, target, source );
  ::math::linear::homography::construct( result, center, target, source );
 }

void hg2_single_specific()
 { // DONE
  typedef ::math::linear::homography::structure<double,2>  homography2_type;
  homography2_type h2;

  std::cout << " --- 2D ---   Single point direct----- "   << std::endl;

  ::math::linear::homography::construct<double>( h2, {1,1} );
  print( h2, " ID " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0.5,0.5} );
  print( h2, " {0.5,0.5} " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {1,2}  );
  print( h2, " (1,2) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {2,1}  );
  print( h2, " (2,1) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {2,2}  );
  print( h2, " (2,2) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  std::cout << " --- 2D ---   Single point invert ----- "   << std::endl;
  ::math::linear::homography::construct_invert<double>( h2, {1,1} );
  print( h2, " ID " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {0.4,0.4} );
  print( h2, " {0.4,0.4} " );
  std::cout << "    "; apply<double,2>( h2, { 0.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 1.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.0, 1.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.4, 0.4 } ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {0.5,0.5} );
  print( h2, " {0.5,0.5} " );
  std::cout << "    "; apply<double,2>( h2, { 0.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 1.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.0, 1.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.5, 0.5 } ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {0.6,0.6} );
  print( h2, " {0.6,0.6} " );
  std::cout << "    "; apply<double,2>( h2, { 0.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 1.0, 0.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.0, 1.0 } ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, { 0.6, 0.6 } ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {1,2}  );
  print( h2, " (1,2) " );
  std::cout << "    "; apply<double,2>( h2, {1,2} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {2,1}  );
  print( h2, " (2,1) " );
  std::cout << "    "; apply<double,2>( h2, {2,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct_invert<double>( h2, {2,2}  );
  print( h2, " (2,2) " );
  std::cout << "    "; apply<double,2>( h2, {2,2 } ); std::cout << std::endl;std::cout << std::endl;

 }

void hg2_simple()
 {
  std::cout << " --- 2D ---   Simple ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,2>  homography2_type;

  homography2_type h2;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {1,1} );
  print( h2, "M - ID" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::constructA<double>( h2, {0,0}, {1,0}, {0,1}, {1,1} );
  print( h2, "A - ID"  );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {0.5,0.5} );
  print( h2,"M - 0.5" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::constructA<double>( h2, {0,0}, {1,0}, {0,1}, {0.5,0.5} );
  print( h2,"A - 0.5" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {0.95,0.95} );
  print( h2,"M - 0.95" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::constructA<double>( h2, {0,0}, {1,0}, {0,1}, {0.95,0.95} );
  print( h2,"A - 0.95" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {0.1,0.1} );
  print( h2,"M - 0.1" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;

  ::math::linear::homography::constructA<double>( h2, {0,0}, {1,0}, {0,1}, {0.1,0.1} );
  print( h2,"A - 0.1" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {2,1} );
  print( h2,"M - {2,1}" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::constructA<double>( h2, {0,0}, {1,0}, {0,1}, {2,1} );
  print( h2,"A - {2,1}" );
  std::cout << "    "; apply<double,2>( h2, {0,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {0,1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl; std::cout << std::endl;
 }

void hg2_single_direct_brute()
 {
  std::cout << " --- 2D ---   Single direct brute ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,2>  homography3_type;

  homography3_type h2;

  std::size_t total = 0;
  std::size_t fail = 0;

  for( double y = -1; y < 2;  y += 0.01 )
  for( double x = -1; x < 2;  x += 0.01 )
   {
    ++total;
    ::math::linear::homography::construct( h2, { x, y } );

    ::math::linear::vector::structure<double,2> r;

    ::math::linear::homography::transform( r, h2, {0,0} );
    if( 0.00001 < fabs (r[0] - 0 ) )
     {  ++fail;
      std::cout << "P: "<< x << ","<< y << " _00_0_ " << r[0] << ", "<<  r[1] <<std::endl;
     }
    if( 0.00001 < fabs (r[1] - 0 ) )
     { ++fail;
      std::cout << "P: "<< x << ","<< y << " _00_1_ " << r[0] << ", "<<  r[1] <<std::endl;
     }

    ::math::linear::homography::transform( r, h2, {1,0} );
    if( 0.00001 < fabs (r[0] - 1 ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _10_0_ "<< r[0] << ", "<<  r[1] <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _10_1_ "<< r[0] << ", "<<  r[1] <<std::endl;*/ }

    ::math::linear::homography::transform( r, h2, {0,1} );
    if( 0.00001 < fabs (r[0] - 0 ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _01_0_ "<< r[0] << ", "<<  r[1] <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _01_1_ "<< r[0] << ", "<<  r[1] <<std::endl; */ }

    ::math::linear::homography::transform( r, h2, { 1, 1 } );
    if( 0.00001 < fabs (r[0] - x ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _xy_0_ "<< r[0] << ", "<<  r[1] <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - y ) )
     { ++fail; /*std::cout << "P: "<< x << ","<< y << " _xy_1_ "<< r[0] << ", "<<  r[1] <<std::endl; */ }
  }

  std::cout << "total: " << total << "; " << "fail:" << fail <<"; " << 100 * (double)fail/(double)total <<std::endl;
  h2 = h2;
 }

void hg2_single_invert_brute()
 {
  std::cout << " --- 2D ---   Single invert brute ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,2>  homography3_type;

  homography3_type h2;

  std::size_t total = 0;
  std::size_t fail = 0;

  for( double y = -1; y < 2;  y += 0.01 )
  for( double x = -1; x < 2;  x += 0.01 )
   {
    ++total;
    ::math::linear::homography::construct_invert( h2, { x, y } );

    ::math::linear::vector::structure<double,2> r;

    ::math::linear::homography::transform( r, h2, {0,0 } );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_0 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_1 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h2, {1,0 } );
    if( 0.00001 < fabs (r[0] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h2, {0,1 } );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h2, {0,0 } );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h2, {x,y } );
    if( 0.00001 < fabs (r[0] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
  }

  std::cout << "total: " << total << "; " << "fail:" << fail <<"; " << 100 * (double)fail/(double)total <<std::endl;
  h2 = h2;
 }

void hg2_complete()
 {
  std::cout << " --- 2D ---   Complete ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,2>  homography2_type;

  homography2_type h2;

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {1,1} );
  print( h2, " ... , (1,1) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {1,2} );
  print( h2, " ... , (1,2) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {2,1} );
  print( h2, " ... , (2,1) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {2,2} );
  print( h2, " ... , (2,2) " );
  std::cout << "    "; apply<double,2>( h2, {1,1} ); std::cout << std::endl;std::cout << std::endl;
 }

void hg2_definition()
 {
  std::cout << " --- 2D ---   By definition ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,2>  homography2_type;
  typedef ::math::geometry::plane::parametric3d< double >  plane_type;
  typedef ::math::linear::vector::structure< double, 3 >  point_type;


  homography2_type result;
  point_type center{ 0,0,0 };
  plane_type plane{ {0,0,1},{1,0,0}, {0,1,0} };
  plane_type source{ {0,0,1},{1,0,0}, {0,1,0} };
  plane_type target{ {0,0,1},{1,0,0}, {0,1,0} };

  ::math::linear::homography::construct( result, plane );
  ::math::linear::homography::construct_invert( result, plane );
  ::math::linear::homography::construct( result, target, source );
  ::math::linear::homography::construct( result, center, target, source );
 }

void hg3_single_direct_brute()
 {
  std::cout << " --- 3D ---   Single direct brute ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;
  std::size_t total = 0;
  std::size_t fail  =0 ;

  for( double z = -2; z < 2;  z += 0.01 )
  for( double y = -2; y < 2;  y += 0.01 )
  for( double x = -2; x < 2;  x += 0.01 )
   {
    ++total;
    ::math::linear::homography::construct( h3, { x, y, z } );

    ::math::linear::vector::structure<double,3> r;

    ::math::linear::homography::transform( r, h3, {0,0,0} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_0 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_1 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_2 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {1,0,0} );
    if( 0.00001 < fabs (r[0] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {0,1,0} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {0,0,1} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 1 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {1,1,1} );
    if( 0.00001 < fabs (r[0] - x ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - y ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - z ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
  }
  std::cout << "total: " << total << "; " << "fail:" << fail <<"; " << 100 * (double)fail/(double)total << std::endl;
 }

void hg3_single_invert_brute()
 {
  std::cout << " --- 3D ---   Single invert brute ----- "   << std::endl;
  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;
  std::size_t total = 0;
  std::size_t fail  =0 ;

  for( double z = -2; z < 2;  z += 0.01 )
  for( double y = -2; y < 2;  y += 0.01 )
  for( double x = -2; x < 2;  x += 0.01 )
   {
    ++total;
    ::math::linear::homography::construct_invert( h3, { x, y, z } );

    ::math::linear::vector::structure<double,3> r;

    ::math::linear::homography::transform( r, h3, {0,0,0} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_0 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_1 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _000_2 " << r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {1,0,0} );
    if( 0.00001 < fabs (r[0] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _100_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {0,1,0} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _010_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {0,0,1} );
    if( 0.00001 < fabs (r[0] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 0 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 1 ) ){ ++fail; /* std::cout << "P: "<< x << ","<< y << "," << z << " _001_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }

    ::math::linear::homography::transform( r, h3, {x,y,z} );
    if( 0.00001 < fabs (r[0] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_0 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[1] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_1 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
    if( 0.00001 < fabs (r[2] - 1 ) ){ ++fail; /*std::cout << "P: "<< x << ","<< y << "," << z << " _xyz_2 "<< r[0] << ", "<<  r[1] << ", "<<  r[2]  <<std::endl; */ }
  }
  std::cout << "total: " << total << "; " << "fail:" << fail <<"; " << 100 * (double)fail/(double)total << std::endl;
 }

void hg3_single()
 {
  std::cout << " --- 3D ---   Single direct ----- "   << std::endl;

  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;

  ::math::linear::homography::construct( h3, { 1, 1, 1 } );
  print( h3, "  --- { 1, 1, 1 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct( h3, { 1, 2, 3 } );
  print( h3, "  --- { 1, 2, 3 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl;

  ::math::linear::homography::construct( h3, { 3, 2, 1 } );
  print( h3, "  --- { 3, 2, 1 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl;

  ::math::linear::homography::construct( h3, { 0.5, 0.5, 0.5 } );
  print( h3, "  --- { 0.5, 0.5, 0.5 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl;

  std::cout << " --- 3D ---   Single invert ----- "   << std::endl;

  ::math::linear::homography::construct_invert( h3, { 1, 1, 1 } );
  print( h3, "  --- { 1, 1, 1 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct_invert( h3, { 1, 2, 3 } );
  print( h3, "  --- { 1, 2, 3 } " );
  std::cout << "    "; apply<double,3>( h3, {1, 2, 3} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct_invert( h3, { 3, 2, 1 } );
  print( h3, "  --- { 3, 2, 1 } " );
  std::cout << "    "; apply<double,3>( h3, {3, 2, 1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct_invert( h3, { 0.5, 0.5, 0.5 } );
  print( h3, "  --- { 0.5, 0.5, 0.5 } " );
  std::cout << "    "; apply<double,3>( h3, { 0.5, 0.5, 0.5 } ); std::cout << std::endl; std::cout << std::endl;
 }

void hg3_simple()
 {
  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;
  std::cout << " --- 3D ---   Simple ----- "   << std::endl;

  ::math::linear::homography::construct(
    h3
         ,{ 0, 0, 0 }
         ,{ 1, 0, 0 }
         ,{ 0, 1, 0 }
         ,{ 0, 0, 1 }
         ,{ 1, 1, 1 }
        );
  monic(h3); print( h3, "ID" );
  std::cout << "    "; apply<double,3>( h3, {0, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 1, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 0, 1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;

  ::math::linear::homography::construct(
    h3
         ,{ 0, 0, 0 }
         ,{ 1, 0, 0 }
         ,{ 0, 1, 0 }
         ,{ 0, 0, 1 }
         ,{ 1, 2, 3 }
        );
  monic(h3); print( h3, "{1,2,3}" );
  std::cout << "    "; apply<double,3>( h3, {0, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 1, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 0, 1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;
 }

void hg3_complete()
 {
  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;


  typedef  ::math::linear::vector::point<double,3> point3_type;

  std::cout << " --- 3D ---   Complete ----- "   << std::endl;
  ::math::linear::homography::construct<double>(
    h3, { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 2, 3 }
      , { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 2, 3 }
        );
  monic(h3); print( h3, "ID{1,2,3}" );
  std::cout << "    "; apply<double,3>( h3, {0, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 1, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 0, 1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;

   ::math::linear::homography::construct<double>(
    h3, { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 1, 1 }
      , { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 1, 1 }
        );
  monic(h3); print( h3, "ID{1,1,1}" );
  std::cout << "    "; apply<double,3>( h3, {0, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 0, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 1, 0} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {0, 0, 1} ); std::cout << std::endl;
  std::cout << "    "; apply<double,3>( h3, {1, 1, 1} ); std::cout << std::endl; std::cout << std::endl;
 }

void retarget()
 {
  ::math::linear::homography::structure<double,2>  result;
  ::math::linear::homography::structure<double,2>  H     ;
  ::math::geometry::interval::structure<double,2>  target;
  ::math::geometry::interval::structure<double,2>  source;
  ::math::geometry::interval::structure<double,2>  domain;
  ::math::geometry::interval::structure<double,2>  codomain;

  ::math::linear::homography::retarget( result, H, target, source );
  ::math::linear::homography::retarget( result, H, target, source );
  ::math::linear::homography::retarget( result, H, target, domain, source );
  ::math::linear::homography::retarget( result, H, target, codomain, domain, source );

  ::math::linear::homography::recodomain( result, H, target );
  ::math::linear::homography::recodomain( result, H, target, codomain );
  ::math::linear::homography::redomain( result, H, source );
  ::math::linear::homography::redomain( result, H, domain, source );

 }

int main( int argc, char*argv[] )
 {
  hg1_definition();
  hg2_definition();
  std::cout << " ------------- 1 -----------" << std::endl; hg1();
  std::cout << " ------------- 2 -----------" << std::endl; hg2_single_specific(); hg2_simple(); hg2_complete(); hg2_single_direct_brute(); hg2_single_invert_brute();
  std::cout << " ------------- 3 -----------" << std::endl; hg3_single();          hg3_simple(); hg3_complete(); hg3_single_direct_brute(); hg3_single_invert_brute();

  //{
  // ::math::linear::homography::structure<double,15>   m15;
  // ::math::linear::homography::zero<double,15>( m15 );
  //}

  //std::cin.get();
  return 0;
 }