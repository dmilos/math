#ifndef _DDMRM_math_random_congruent_HPP_
 #define _DDMRM_math_random_congruent_HPP_

// ::math::random::congruent<dimension,scalar>

#include <cstddef>
#include "../linear/vector/structure.hpp"



 namespace math
  {
   namespace random
    {

     template< typename scalar_name, ::math::type::size_type dimension_number >
      class congruent
       {
        public:
          typedef scalar_name         scalar_type;
          typedef ::math::linear::vector::point<scalar_name,dimension_number>      point_type;
          typedef std::size_t         size_type;

        public:
          congruent()
           {
            math::linear::vector::fill( m_seed, 0.5 );
            scalar_type g = 1.22074408460575947536;
            m_move[0] = scalar_type(1)/ g;
            m_move[1] = scalar_type(1)/ ( g*g );
            m_move[2] = scalar_type(1)/ ( g*g*g );
           }

          explicit congruent( point_type const& seed_param )
           {
            seed( seed_param );
           }

          void next( point_type & point )
           {
            math::linear::vector::addition( m_seed, m_move );
            m_move[0] = fmod( m_move[0], scalar_type(1) );
            m_move[1] = fmod( m_move[1], scalar_type(1) );
            m_move[2] = fmod( m_move[2], scalar_type(1) );
            point = m_seed;
           }

          void operator()( point_type & point ){ return this->next( point ); }

        public:
          void seed( point_type const& seed_param )
           {
            m_seed = seed_param;
           }

        private:
         point_type m_seed;
         point_type m_move;
      };

     template< typename scalar_name >
      class congruent<scalar_name,1>
       {
        public:
          typedef scalar_name         scalar_type;
          typedef std::size_t         size_type;

        public:
          congruent()
           {
            this->seed( 0.5 );
            scalar_type phi = ( sqrt(5) + 1 )/scalar_type(2);
            m_move = scalar_type(1)/scalar_type(phi);
           }

          explicit congruent( scalar_name const& seed_param )
           {
            seed( seed_param );
           }

          scalar_name next()
           {
            return m_seed = fmod( m_seed + m_move, scalar_type(1) );
           }

          void next( scalar_name & point_param )
           {
            point_param = this->next();
           }
          void operator()( scalar_name & point ){ return this->next(); }

        public:
          void seed( scalar_type const& seed_param )
           {
            m_seed = seed_param;
           }

        private:
          scalar_name m_seed;
          scalar_name m_move;
      };

     template< typename scalar_name >
      class congruent<scalar_name,2>
       {
        public:
          typedef scalar_name         scalar_type;
          typedef ::math::linear::vector::point<scalar_name,2>     point_type;
          typedef std::size_t         size_type;

        public:
          congruent()
           {
            this->seed( { 0.5, 0.5 } );
            scalar_type plastic =    pow( (scalar_type(9) + sqrt(scalar_type(69)))/scalar_type(18), scalar_type(1)/scalar_type(3))
                                  +  pow( (scalar_type(9) - sqrt(scalar_type(69)))/scalar_type(18), scalar_type(1)/scalar_type(3));
            m_move[0] = scalar_type(1) /( plastic );
            m_move[1] = scalar_type(1) /( plastic * plastic);
           }

          explicit congruent( point_type const& seed_param )
           {
            seed( seed_param );
           }

          void next( point_type & point )
           {
            point = this->next();
           }
          point_type next()
           {
            m_seed[0] = fmod( m_seed[0] + m_move[0], scalar_type(1) );
            m_seed[1] = fmod( m_seed[1] + m_move[1], scalar_type(1) );
            return m_seed;
           }

         void operator()( point_type & point ){ return this->next( point ); }

        public:
          void seed( point_type const& seed_param )
           {
            m_seed = seed_param;
           }

        private:
         point_type m_seed;
         point_type m_move;
      };

    }
  }

#endif