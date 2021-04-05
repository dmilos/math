#ifndef math_function_clamper
#define math_function_clamper

 // ::math::function::ramp
 // ::math::function::saw
 // ::math::function::wave
 // ::math::function::sinkhole
 // ::math::function::to_one
 // ::math::function::to_any
 // ::math::function::relu
 // ::math::function::stairs

namespace math
 {
  namespace function
   {

     template< typename scalar_name >      //  _____/-----
      inline
      scalar_name
      ramp
       (
         scalar_name const& value
        ,scalar_name const& lower  = scalar_name( 0 )
        ,scalar_name const& higher = scalar_name( 1 )
       )
       {
        return ( (value) < lower ? lower : ( higher < (value) ? higher : (value) ) ) ;
       }

     template< typename scalar_name  >   //  ////////
      inline
      scalar_name
      saw
       (
         scalar_name  const& value 
        ,scalar_name  const& lower  
        ,scalar_name  const& higher
       )
       {
        if( lower < value ) return           scalar_name( ::fmod( value - lower, higher - lower ) ) + lower;
        if( value < lower ) return  higher - scalar_name( ::fmod( lower - value, higher - lower ) );
        return value;
       }

     template< typename scalar_name  >   //  ////////
      inline
      scalar_name
      saw
       (
        scalar_name  const& value
       )
       {
        if( scalar_name(0) < value ) return                   scalar_name( ::fmod(  + value, scalar_name(1) ) ) ;
        if( value < scalar_name(0) ) return  scalar_name(1) - scalar_name( ::fmod(  - value, scalar_name(1) ) );
        return value;
       }

     template< typename scalar_name  >   //  /\/\/\/\/
      inline
      scalar_name
      wave
       (
         scalar_name  const& value
        ,scalar_name  const& lower 
        ,scalar_name  const& higher
       )
       {
        scalar_name  Ir_result;
        scalar_name  I_size =  higher - lower;

        if( lower < value )
         {
          Ir_result = scalar_name( ::fmod( value - lower, 2 * I_size ) );
         }
        else
         {
          if( value < lower )
           {
          Ir_result = scalar_name( ::fmod( lower - value, 2 * I_size ) );
           }
          else
           {
            return Ir_result = value;
           }
         }

        if( I_size < Ir_result )
         {
          Ir_result =  - Ir_result + 2 * I_size;
         }

        Ir_result += lower;
        return Ir_result;
       }

     template< typename scalar_name  >   //  /\/\/\/\/
      inline
      scalar_name
      wave
       (
         scalar_name  const& value
       )
       {
        scalar_name  Ir_result;

        if( scalar_name(0) < value )
         {
          Ir_result = scalar_name( ::fmod(    + value, scalar_name(2) ) );
         }
        else
         {
          if( value < scalar_name(0) )
           {
            Ir_result = scalar_name( ::fmod(  - value, scalar_name(2) ) );
           }
          else
           {
            return Ir_result = value;
           }
         }

        if( scalar_name(1) < Ir_result )
         {
          Ir_result = scalar_name(2) - Ir_result;
         }
        return Ir_result;
       }


     template< typename scalar_name  >  //  \\\\\//////
      inline
      scalar_name
      sinkhole
       (
        scalar_name   const& value
        ,scalar_name  const& lower  
        ,scalar_name  const& higher 
       )
       {
        return scalar_name( ::fmod( fabs( value ) - lower, higher - lower ) ) + lower;
       }

     template< typename scalar_name  >  //  \\\\\//////
      inline
      scalar_name
      sinkhole
       (
        scalar_name  const& value
       )
       {
        return scalar_name( ::fmod( fabs( value ), scalar_name(1) ) );
       }

      template< typename scalar_name  >  //  _____/~~~
      inline
      scalar_name
      relu    //  rectified linear unit  = max(lower, value )
       (
        scalar_name  const& value,
        scalar_name  const& lower  = scalar_name ( 0 )
       )
       {
        return ( value < lower ? lower : value );
       }

      template< typename scalar_name , typename integer_name = int >  //  _____------^^^
      inline
       scalar_name
       stairs  //!< AKA floor
       (
         scalar_name  const& value
       )
       {
        return floor( value );
       }

      template< typename scalar_name , typename integer_name = int >  //  _____------
      inline
       scalar_name
       stairs
       (
         scalar_name  const& value,
         scalar_name  const& step
       )
       {
        return step * floor( value / step );
       }


     template< typename scalar_name >
      inline
      scalar_name
      to_one      //!< [left,right] -> [0,1]
       (
         scalar_name  const& value              //!< what  goes to [0,1]
        ,scalar_name  const& left               //!< left  side of interval
        ,scalar_name  const& right              //!< right side of interval
       )
       {
        return ( value - left ) / ( right - left );
       }

     template< typename scalar_name >
      inline
      scalar_name
      to_any      //!< [0,1] -> [left,right] ->
       (
         scalar_name  const& value              //!< what  goes to [left,right]
        ,scalar_name  const& left               //!< left  side of interval
        ,scalar_name  const& right              //!< right side of interval
       )
       {
        return value * ( right - left ) + left ;
       }

     template< typename scalar_name >
      inline
      scalar_name
      any_to_any      //!< [leftA,rightA] -> [leftB,rightB]
       (
         scalar_name  const& value                //!< what  goes to [leftB,rightB]
        ,scalar_name  const& leftA
        ,scalar_name  const& rightA
        ,scalar_name  const& leftB
        ,scalar_name  const& rightB
       )
       {
        return ::math::function::to_any( ::math::function::to_one<scalar_name>( value, leftA, rightA ), leftB, rightB );
       }


   }
 }

#endif
