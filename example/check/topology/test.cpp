#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "math/topology/topology.hpp"
#include "./SVG.hpp"

 template< typename data_type >
 void print( ::math::topology::sico::structure<data_type> const& sico  )
  {
   std::cout << "{ " << std::endl;
   for( size_t dimension=0; dimension < sico.size(); ++dimension )
    {
     std::cout << "    " <<dimension << ": | " << sico.size(dimension) << " | = ";
     std::cout << "[ ";

     for( size_t index=0; index < sico.size(dimension); ++index )
      {
       std::cout << index << "< ";
       for( size_t face=0; face < sico.simplex(dimension,index).face().size(); ++face )
        {
         std::cout << sico.simplex(dimension,index).face()[face] <<",";
        }
       std::cout << "> ";
      }
     std::cout << " ] "<< std::endl;
    }
   std::cout << "}" << std::endl;
  }
 
template< typename data_type >
 void print_new( ::math::topology::sico::structure<data_type> const& sico  )
  {
   std::cout << "{ " << std::endl;
   for( size_t dimension=0; dimension < sico.size(); ++dimension )
    {
     std::cout << "    " <<dimension << ": | " << sico.size(dimension) << " | = ";
     std::cout << "[ ";

     for( size_t index=0; index < sico.size(dimension); ++index )
      {
       std::cout << "[" << index << "] < ";
       std::cout << "!( ";
       for( size_t face=0; face < sico.simplex(dimension,index).face().size(); ++face )
        {
         std::cout << sico.simplex(dimension,index).face()[face] <<",";
        }
       std::cout << " ) ";
       std::cout << "^( ";
       for( size_t cell=0; cell < sico.simplex(dimension,index).cell().size(); ++cell )
        {
         std::cout << sico.simplex(dimension,index).cell()[cell] <<",";
        }
       std::cout << " ) ";
       std::cout << "> ";

      }
     std::cout << " ] "<< std::endl;
    }
   std::cout << "}" << std::endl;
  }

template < typename data_name >
void print( std::vector<data_name> const& v )
 {
  std::cout << "[ ";
  for( auto const& e : v )
   {
    std::cout << e <<", ";
   }
  std::cout << "]" << std::endl;
 }

template < typename data_name >
void print( std::vector<std::vector<data_name>> const& v )
 {
  int dimension=0;
  std::cout << "{ ";
  for( auto const& e : v )
   {
    std::cout << std::endl;
    std::cout << "    " << dimension++ << ": " ;
    std::cout << "|" << v.size() << "| = " ;
    std::cout << "    [" ;
    for( auto const& d : e )
     {
      std::cout << d <<", ";
     }
     std::cout << "]";
   }
    std::cout << std::endl;
  std::cout << "}" << std::endl;
 }

 template< typename  scalar_name >
  void SVGx
   (
     std::string const& filename
    , typename ::math::topology::sico::intersect_struct<std::array<scalar_name,2> >::result_type  const  & result
    ,::math::topology::sico::structure<std::array<scalar_name,2> >       const& left
    ,::math::topology::sico::structure<std::array<scalar_name,2 > >       const& right
   )
 {
  typedef std::array<scalar_name,2> data_t;
  typedef  ::math::topology::sico::structure<data_t > structure_type;

  structure_type left_new;
  structure_type right_new;
  for( std::size_t dimension=0; dimension < 1; ++dimension )
   {
    for( std::size_t index=0; index < result[0].first.size(); ++index )
     {
      auto const & simplex = left.simplex( dimension, result[dimension].first[index] );
      left_new.push( simplex.data(), {} );
     }
    for( std::size_t index=0; index < result[0].second.size(); ++index )
     {
      auto const & simplex = right.simplex( dimension, result[dimension].second[index] );
      right_new.push( simplex.data(), {} );
     }
   }

  for( std::size_t dimension=1; dimension < std::min( left.size(), result.size() ); ++dimension )
   {
    for( std::size_t index=0; index < result[dimension].first.size(); ++index )
     {
      auto const & simplex = left.simplex( dimension, result[dimension].first[index] );
      typename structure_type::face_type face_new;
      auto const& low = result[dimension-1].first;
      for( auto const& face_index: simplex.face() )
       {
        face_new.push_back( std::find( low.begin(), low.end(), face_index ) - low.begin()   );
       }
      left_new.push( simplex.data(), face_new );
     }
   }

  for( std::size_t dimension=1; dimension < std::min( right.size(), result.size() ); ++dimension )
   {
    for( std::size_t index=0; index < result[dimension].second.size(); ++index )
     {
      auto const & simplex = right.simplex( dimension, result[dimension].second[index] );
      typename structure_type::face_type face_new;
      auto const& low = result[dimension-1].second;
      for( auto const& face_index: simplex.face() )
       {
        face_new.push_back( std::find( low.begin(), low.end(), face_index ) - low.begin() );
       }
      right_new.push( simplex.data(), face_new );
     }
   }

  SVG<float,data_t> svg;
  {
                                                                       auto s1 = svg.save( left_new );
    svg.m_move[0] = 1 * svg.m_scale;  svg.m_move[1] =0;                auto s2 = svg.save( right_new );
    svg.m_move[0] = 0;                svg.m_move[1] = 1 * svg.m_scale; auto s3 = svg.save( left );
    svg.m_move[0] = 1 * svg.m_scale;  svg.m_move[1] = 1 * svg.m_scale; auto s4 = svg.save( right );

    svg.save( filename, s1 + s2 + s3 + s4 );
  }

 }

template< typename data_name >
 void make_tetraedar( ::math::topology::sico::structure<data_name> & sico )
 {
   std::cout << __FUNCTION__ << std::endl;
   sico.clear();
   sico.push(data_name{}, {});  // New point
   sico.push(data_name{}, {});  // New point
   sico.push(data_name{}, {});  // New point
   sico.push(data_name{}, {});  // New point

   sico.push(data_name{}, {0,1});  // 0 - line
   sico.push(data_name{}, {0,2});  // 1 - line
   sico.push(data_name{}, {0,3});  // 2 -line

   sico.push(data_name{}, {1,2});  // 3 -line
   sico.push(data_name{}, {1,3});  // 4 -line
   sico.push(data_name{}, {2,3});  // 5 -line

   sico.push(data_name{}, {0,1,3}); // triangle
   sico.push(data_name{}, {1,2,5}); // triangle
   sico.push(data_name{}, {3,4,5}); // triangle
   sico.push(data_name{}, {0,2,4}); // triangle

   sico.push( data_name{}, {0,1,2,3} ); // tetra
 }

template< typename scalar_name >
 void make_random_square( ::math::topology::sico::structure<std::array<scalar_name,2>> & sico, size_t const& count )
 {
   std::cout << __FUNCTION__ << std::endl;
  sico.clear();
  for( std::size_t i=0; i < count; ++i )
   {
    sico.push( {scalar_name ( rand()/(double)RAND_MAX), scalar_name( rand()/(double)RAND_MAX )} , {} );
   }
  ::math::topology::sico::delaunay2<scalar_name>( sico );
 }

void hyper_point( ::math::topology::sico::structure<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::std::vector<size_t> r;
  ::math::topology::sico::hyper_point( r, 3, 0, sico );  print( r );
 }

void concatenate( ::math::topology::sico::structure<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::structure<float> r;
  ::math::topology::sico::concatenate( r, sico, sico );
 }

void vertex( ::math::topology::sico::structure<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::std::vector<size_t> r;
  ::math::topology::sico::vertex( r, 3, 0, sico ); print( r );
  ::math::topology::sico::vertex( r, 2, 4, sico ); print( r );
  ::math::topology::sico::vertex( r, 0, 4, sico ); print( r );
}

void find( ::math::topology::sico::structure<float> const& needle, ::math::topology::sico::structure<float> const& haystack  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::structure<float> position;
  //::math::topology::sico::find( position, needle, haystack );
  print( position );
 }

void erase( ::math::topology::sico::structure<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::structure<float> copy = sico ;
  print( copy );
  copy = sico; std::cout<< "this::erase(0,0): " ;copy.erase(0,0);  print( copy );
  copy = sico; std::cout<< "this::erase(0,1): " ;copy.erase(0,1);  print( copy );
  copy = sico; std::cout<< "this::erase(1,0): " ;copy.erase(1,0);  print( copy );
 }

void trim( ::math::topology::sico::structure<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::structure<float> copy = sico ;
  print( copy );
  copy = sico; std::cout<< "this::trim(6): " ;copy.trim(6);  print( copy );
  copy = sico; std::cout<< "this::trim(5): " ;copy.trim(5);  print( copy );
  copy = sico; std::cout<< "this::trim(4): " ;copy.trim(4);  print( copy );
  copy = sico; std::cout<< "this::trim(3): " ;copy.trim(3);  print( copy );
  copy = sico; std::cout<< "this::trim(1): " ;copy.trim(2);  print( copy );
  copy = sico; std::cout<< "this::trim(1): " ;copy.trim(1);  print( copy );
  copy = sico; std::cout<< "this::trim(0): " ;copy.trim(0);  print( copy );
}

void closur( ::math::topology::sico::structure<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::vector<std::size_t > > closure;
  print( sico );
  ::math::topology::sico::closure( closure, 0, 1, sico ); print( closure );
  ::math::topology::sico::closure( closure, 1, 0, sico ); print( closure );
  ::math::topology::sico::closure( closure, 2, 0, sico ); print( closure );
  ::math::topology::sico::closure( closure, 3, 0, sico ); print( closure );
 }

void star( ::math::topology::sico::structure<float> & sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t >                r0;
  std::vector< std::vector< std::size_t > > rX;
  print( sico );
  ::math::topology::sico::star <float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::star <float>( rX, 0, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 1, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 2, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 3, 0, sico ); print( rX );
}

void star2( ::math::topology::sico::structure<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t > l;
  ::math::topology::sico::star( l, 1, 0, sico ); print( l );
  ::math::topology::sico::star( l, 1, 1, sico ); print( l );
  ::math::topology::sico::star( l, 1, 2, sico ); print( l );
  ::math::topology::sico::star( l, 1, 3, sico ); print( l );
  ::math::topology::sico::star( l, 2, 3, sico ); print( l );
}

void link( ::math::topology::sico::structure<float> & sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t >                r0;

  ::math::topology::sico::link<float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 1, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 2, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 3, 0, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 1, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 2, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 3, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 3, sico ); print( r0 );
}

void intersect( void )
{
  typedef std::array<float,2> data_t;
  ::math::topology::sico::structure< data_t > left, right;

  left.push( {0,0}, {} );
  left.push( {0,1}, {} );
  left.push( {1,0}, {} );
  left.push( {1,2}, {} );

  left.push( {0,0}, {0,1} );
  left.push( {0,0}, {0,2} );
  left.push( {0,0}, {1,2} );
  //left.push( {0,0}, {2,3} );

  right.push( {0,0}, {} );
  right.push( {0,1}, {} );
  right.push( {1,0}, {} );
  //right.push( {1,2}, {} );
  right.push( {0,0}, {0,1} );
  right.push( {0,0}, {0,2} );
  right.push( {0,0}, {1,2} );

  //make_tetraedar( left );
  //make_tetraedar( right );

  ::math::topology::sico::intersect_struct<float>::result_type result;
//::math::topology::sico::intersect( result, left, right );  SVGx( "intersect-simple.svg", result, left, right );
                                 
 make_random_square( left, 24 ); print_new( left ); 
 make_random_square( right, 24 );  print_new( right );

 ::math::topology::sico::intersect( result, left, right ); SVGx( "intersect-rand-2-result-A.svg",result, left, right );
 ::math::topology::sico::intersect( result, right, left ); SVGx( "intersect-rand-2-result-B.svg",result, right, left );

// ::math::topology::sico::intersect( result, left, left ); SVGx( "intersect-rand-self.svg",result, left, left );
}


void NNG()
 {
  std::cout << __FUNCTION__ << std::endl;

  typedef std::array<float,2> data_type;
  ::math::topology::sico::structure<data_type>   sico;

  sico.push( {0,0}, {} );
  sico.push( {0,1}, {} );
  sico.push( {1,0}, {} );
  sico.push( {1,3}, {} );

  ::math::topology::sico::NNG<float,2,data_type>( sico );
  print( sico );
 }

void delaunay()
 {
  std::cout << __FUNCTION__ << std::endl;

  typedef std::array<double,2> data_type;
  ::math::topology::sico::structure<data_type>   sico;

  sico.push( {0,0}, {} );
  sico.push( {1,0}, {} );
  sico.push( {0,2}, {} );
  sico.push( {1,3}, {} );

  ::math::topology::sico::delaunay2<double>( sico );
  print( sico );
  SVG<double,data_type> svg;
  svg.save( "simple.svg", sico );

  sico.clear();
  for( int i=0; i < 10; ++i )
   {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
   }
  ::math::topology::sico::delaunay2<double>( sico );
  SVG<double,data_type>{}.save( "rand-10.svg", sico );


  sico.clear();
  for( int i=0; i < 100; ++i )
   {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
   }
  ::math::topology::sico::delaunay2<double>( sico );
  SVG<double,data_type>{}.save( "rand-100.svg", sico );

  sico.clear();
  for( int i=0; i < 1000; ++i )
  {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
  }
  ::math::topology::sico::delaunay2<double>( sico );
  SVG<double,data_type>{}.save( "rand-1000.svg", sico );

  sico.clear();
  for( int i=0; i < 10000; ++i )
  {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
  }
  ::math::topology::sico::delaunay2<double>( sico );
  SVG<double,data_type>{}.save( "rand-10000.svg", sico );
}

void delaunay3() // not a test, just invoke
 {
  std::cout << __FUNCTION__ << std::endl;

  typedef std::array<double,3> data_type;
  ::math::topology::sico::structure<data_type>   sico;

  sico.push( {0,0, 0}, {} );
  sico.push( {1,0, 1}, {} );
  sico.push( {0,2, 2}, {} );
  sico.push( {1,3, 9}, {} );

  ::math::topology::sico::delaunay3<double>( sico );
}

int main( int argc, char *argv[] )
 {
  srand(0);
  std::cout << "Hello World" << std::endl;

  ::math::topology::sico::structure<float> left;

  left.push(0.0f, {});  // New point
  left.push(0.1f, {});  // New point
  left.push(0.2f, {});  // New point

  left.push(1.0f, {0,1});  // 0 - line
  left.push(1.1f, {0,2});  // 1 - line
  left.push(1.2f, {1,2});  // 2 -line

  left.push(3.0f, {0,1,2}); // triangle
  print( left );

  ::math::topology::sico::structure<float> right;

  right.push(0, {});  // New point
  right.push(1, {});  // New point
  right.push(2, {});  // New point
  right.push(3, {});  // New point

  right.push(4, {});  // New point
  right.push(5, {});  // New point
  right.push(6, {});  // New point

  //right.push(-1, {0}); // Change old
  //right.push(-2, {1}); // Change old
  //right.push(-3, {2}); // Change old

  right.push(0, {0,1});  // 0 - line
  right.push(1, {0,2});  // 1 - line
  right.push(2, {0,3});  // 2 -line

  right.push(3, {1,2});  // 3 -line
  right.push(4, {1,3});  // 4 -line
  right.push(5, {3,2});  // 5 -line

  right.push(6, {4,5});  // 6 -line
  right.push(7, {5,6});  // 7 -line
  right.push(8, {4,6});  // 8 -line

  right.push(0, {0,1,3}); // triangle
  right.push(1, {1,2,5}); // triangle
  right.push(2, {3,4,5}); // triangle
  right.push(3, {0,2,4}); // triangle

  right.push(4, {6,7,8}); // triangle

  ::math::topology::sico::push<float>( right, 0.123f, {0,1,2,3} ); // tetra
  print( right );

  ::math::topology::sico::structure<float> tetra;
  make_tetraedar( tetra );
  print( tetra );

  right.find( {0,1,2,3} );

  hyper_point( right );
  concatenate( right );
  vertex( right );
  erase( left );
  erase( right );
  find( left, right );
  trim( right );
  closur( right );
  star( tetra );
  star2( right );
  link( tetra );
  intersect( );
  NNG();
  delaunay();

  std::vector< std::vector< std::size_t> >              position;

  //::math::topology::sico::find( position, left, right );

  std::cout << "End" << std::endl;
  
  return EXIT_SUCCESS;
 }

