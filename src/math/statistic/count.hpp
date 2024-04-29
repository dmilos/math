#ifndef math_statistic_count
#define math_statistic_count

// ::math::statistic::count<size_name>


namespace math
 {
  namespace statistic
   {

    template
      <
       typename size_name = long unsigned
      >
      class count
      {
       public:
         typedef size_name size_type;
         typedef size_name value_type;

         count()
          {
           this->reset( 0 );
          }

         void reset()
          {
           this->reset( 0 );
          }

         void reset( size_type const& count )
          {
           this->m_value = count;
          }

         void push()
          {
           m_value ++;
          }

         template < typename sample_name >
          void push( sample_name const& dummy )
           {
            m_value ++;
           }

         value_type const& value()const
          {
           return m_value;
          }

         operator value_type const& () const
          {
           return value();
          }

        private:
          value_type m_value;
      };

   }
 }

#endif
