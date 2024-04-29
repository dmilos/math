
#include <iostream>

#include "math\math.hpp"

int main()
{
    std::cout << "Hello World!\n";
    ::math::statistic::histogram<>   hC;

    hC.resize( 20 );
    hC.size();

    hC.push( 1.25 );
    hC.push( 350 );
    hC.push( - 50 );


    ::math::statistic::histogram<::math::statistic::average<math::type::scalar_t>>   hA;

    hA.resize(20);
    hA.size();

    hA.push(1.25);
    hA.push(350);
    hA.push(-50);

}

