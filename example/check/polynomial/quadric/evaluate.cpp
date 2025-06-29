#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Hello World" << endl;

    std::array<float, 3>   c{ 1,2,3 };
    float   x0 = 0, y0 = 1
        , x1 = 1, y1 = 2
        , x2 = 2, y2 = 3
        ;

    cout << ::math::polynomial::quadric::evaluate(x0, c.data()) << std::endl;
    cout << ::math::polynomial::quadric::evaluate(x1, c.data()) << std::endl;
    cout << ::math::polynomial::quadric::evaluate(x2, c.data()) << std::endl;
    cin.get();
    return EXIT_SUCCESS;
}

