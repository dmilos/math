#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <ctime>
#include <algorithm>

#include "math/math.hpp"

using namespace std;


#define LOAD7(DP_vect,DP_1,DP_2,DP_3,DP_4,DP_5,DP_6,DP_7)\
DP_vect[6]= DP_7 ;                                   \
DP_vect[5]= DP_6 ;                                   \
DP_vect[4]= DP_5 ;                                   \
DP_vect[3]= DP_4 ;                                   \
DP_vect[2]= DP_3 ;                                   \
DP_vect[1]= DP_2 ;                                   \
DP_vect[0]= DP_1

int main( int argc, char *argv[] )
 {
  vector<int> I_vec(7);
  int  comb1 = 0;

  clock_t t = clock();


  LOAD7( I_vec, 0, 0, 0, 5, 5, 5, 5 );
  do
   {
    comb1++;
    copy( I_vec.begin(), I_vec.begin()+3, ostream_iterator<int>(cout, ", " ) ); cout << endl;
   }
  while( ::math::algorithm::next_variation( I_vec.begin(), I_vec.begin()+3, 6, 0, 1 ) );

  cout << endl;
  cout << "comb1 " << comb1 << endl;
  cout << "Time : " << (clock() - t)/(float)CLOCKS_PER_SEC << endl;

  
  return 0;
 }
