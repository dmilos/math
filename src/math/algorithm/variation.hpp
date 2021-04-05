#ifndef math_algorithm_concentric_loop_HPP_
 #define math_algorithm_concentric_loop_HPP_

// ::math::algorithm::next_variation( bein(), end(), max, start = 0, step =1 )
// ::math::algorithm::prev_variation( bein(), end(), max, start = 0, step =1 )

 namespace math
  {
   namespace algorithm
    {

     template<class _Tnumber, class _Titerator >
      bool next_variation
       (
            _Titerator const& _First
          , _Titerator const& _Last
          , _Tnumber const& _Max
          , _Tnumber const& _Start = 0
          , _Tnumber const& _Step  = 1
       )
       {
        _Titerator _Next = _First;
        while( _Next  != _Last )
         {
          *_Next += _Step;
          if( *_Next < _Max )
           {
            return true;
           }
          *_Next = _Start;
          ++_Next;
         }
        return false;
       }

     template<class _Tnumber, class _Titerator >
      bool prev_variation
       (
         _Titerator const& _First
         , _Titerator const& _Last
         , _Tnumber const& _Max
         , _Tnumber const& _Start = 0
         , _Tnumber const& _Step = 1
      )
      {
       _Titerator _Next = _First;
       while (_Next != _Last)
        {
         if( _Start <  *_Next )
          {
           *_Next -= _Step;
           return true;
          }

         *_Next = _Max;
         ++_Next;
       }
       return false;
      }

/*
        template
         <
           typename N_Iterator
          ,typename N_BoundType
        //,typename N_Incrementator
        //,typename N_Less
         >
        bool variation_next
         (
           N_Iterator      const& P_begin
          ,N_Iterator      const& P_end
          ,N_BoundType     const& P_lower
          ,N_BoundType     const& P_upper
        //,N_Incrementator const& P_incrementator_pre
        //,N_Less          const& P_less
         )
        {
         N_Iterator I_begin( P_begin );

         while( I_begin != P_end )
          {
           ++(*I_begin);
           if( *I_begin < P_upper  ) return true;
           *I_begin = P_lower;
           ++I_begin;
          }

         return false;
        }


        template
         <
           typename N_Iterator
          ,typename N_BoundType
        //,typename N_Incrementator
        //,typename N_Less
         >
        bool variation_prev
         (
           N_Iterator      const& P_begin
          ,N_Iterator      const& P_end
          ,N_BoundType     const& P_lower
          ,N_BoundType     const& P_upper
        //,N_Incrementator const& P_decrementator_pre
        //,N_Less          const& P_less
         )
        {
         N_Iterator I_begin( P_begin );

         while( I_begin != P_end )
          {
           --(*I_begin);
           if( !( *I_begin < P_lower ) ) return true;
           *I_begin = P_upper;
           --( *I_begin );
           ++I_begin;
          }
         return false;
        }

*/

    }
 }

#endif
