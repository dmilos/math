#ifndef math_algorithm_combination_HPP_
 #define math_algorithm_combination_HPP_

// math::algorithm::next_combination( std::begin( ), std::end( ), max, step ); //!< container is in in reverse order {5,4,3,2,1}

 namespace math
  {
   namespace algorithm
    {

     template<class _Tnumber, class _Titerator >
      bool next_combination
       (
            _Titerator const& _First
          , _Titerator const& _Last
          , _Tnumber const& _Max //!< can not be reach .i.e. to be equal
          , _Tnumber const& _Step  = 1
       )
       {
        _Titerator _Current = _First;
         if( _Current  == _Last )
          {
           return false;
          }
         *_Current += _Step;
         if( *_Current < _Max )
          {
           return true;
          }
        _Titerator _Next = _Current + 1;
         if( _Next == _Last )
          {
           return false;
          }
         if( false == next_combination( _Next, _Last, _Max-_Step, _Step ) )
          {
           return false;
          }
         *_Current = *_Next + _Step; 
         return *_Current < _Max;
        }

    }
 }

#endif
