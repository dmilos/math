#ifndef _6dacc71d2544408c901ba6ca7e615f09
#define _6dacc71d2544408c901ba6ca7e615f09

#include <sstream>

#include "math/topology/topology.hpp"


template< typename scalar_name, typename data_name >
 class SVG
  {
   public:
     typedef ::math::topology::sico::structure<data_name> sizo_type;
     typedef ::math::linear::vector::point<scalar_name,2> point_type;

     point_type  m_move   = { 0, 0 };
     scalar_name m_scale  = scalar_name( 10.00 );
     scalar_name m_radius = scalar_name(  1.5*0.02/2.5  );
     scalar_name m_line   = scalar_name(  0.0075/3 );
     point_type m_canvas   = { 10, 10 };

   public:

     void save( std::string const& filename, sizo_type const&  sico )
      {
       std::ofstream ofs( filename );
       ofs << "<svg height=\"" << m_canvas[1] << "\" width=\"" << m_canvas[0] << "\">" << std::endl;
       ofs << this->save( sico );
       ofs << "</svg>" << std::endl;
      }

     void save( std::string const& filename, std::string const& content )
      {
       std::ofstream ofs( filename );
       ofs << "<svg height=\"" << m_canvas[1] << "\" width=\"" << m_canvas[0] << "\">" << std::endl;
       ofs << content;
       ofs << "</svg>" << std::endl;
      }

     std::string save( sizo_type const&  sico )
      {
       std::string idPrefix = "(" + std::to_string( rand() ) + ")";
       std::stringstream ss;
       ss << "<g " ; 
       ss << "id=\"group-" << rand() << "\" " ;
       ss << "transform=\"" 
         << "translate( " << m_move[0] << "," << m_move[1] << ") "
         << "scale("  << m_scale << "," << m_scale << ") "
        << "\" "
      ;

       ss <<    " >" << std::endl;

       for( size_t index=0; index < sico.size(2) ; ++index )
        {
         std::vector< std::size_t > vertex;
         ::math::topology::sico::vertex<data_name>( vertex, 2, index, sico );

         auto first = ::math::topology::sico::property::point<scalar_name,2>(  sico.vertex( vertex[0] ) );
         auto second = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( vertex[1] ) );
         auto third = ::math::topology::sico::property::point<scalar_name,2>(  sico.vertex( vertex[2] ) );

         decltype(first) center = { (first[0]+second[0]+third[0])/3, (first[1]+second[1]+third[1])/3  };
         ::math::linear::vector::convex<scalar_name>( first,  0.2f,  first, center );
         ::math::linear::vector::convex<scalar_name>( second, 0.2f, second, center );
         ::math::linear::vector::convex<scalar_name>( third,  0.2f,  third, center );

         ss << "<polygon "
                  << " id=\"" << idPrefix <<"polygon-index-"<< index  << "\""
                  << " points=\""
                  <<  first[0] << ","  <<   first[1] << " "
                  << second[0] << ","  <<  second[1] << " "
                  <<  third[0] << ","  <<   third[1]
                  << "\""
                  <<" style=\"fill:rgb(127,255,127);stroke:none\" />"
             << std::endl;
        }

       for( size_t index=0; index < sico.size(1) ; ++index )
        {
         auto simplex = sico.simplex( 1, index );
         auto first = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( simplex.face()[0] ) );
         auto second = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( simplex.face()[1] ) );

         ss << "<line "
                  << " id=\"" << idPrefix <<"line-index-"<< index << "\""
                  << " x1=\""<< first[0]  << "\""
                  << " y1=\""<< first[1]  << "\""
                  << " x2=\""<< second[0] << "\""
                  << " y2=\""<< second[1] << "\""
                  <<" style=\"stroke:rgb(255,0,0);stroke-width:"<< m_line << "\" />"
             << std::endl;
        }

       for( size_t index=0; index < sico.size(0) ; ++index )
        {
         auto vertex =  sico.vertex( index );
         auto center = ::math::topology::sico::property::point<scalar_name,2>( vertex );
         std::string  color = "#0000ff";

         switch( ::math::topology::sico::property::ID( vertex ) )
          {
           case ( 0 ): color="red"; break;
           case ( 1 ): color="green"; break;
           case ( 2 ): color="blue"; break;
           case ( 3 ): color="cyan"; break;
           case ( 4 ): color="yellow"; break;
           case ( 5 ): color="magenta"; break;
           case ( 6 ): color="gold"; break;
           case ( 7 ): color="chocolate"; break;
           case ( 8 ): color="lime"; break;
           case ( 9 ): color="purple"; break;
         }

         ss << "<circle "
           << " id=\"" << idPrefix <<"circle-index-"<< index  << "\""
           << " cx=\""<< center[0] << "\""
           << " cy=\""<< center[1] << "\""
           << " r=\""<< m_radius  << "\""
           <<" style=\"fill:" << color <<  ";stroke:none;\" />"
           << std::endl;
        }

       ss << "</g>" << std::endl;
       return ss.str();
      }

  };
#endif
