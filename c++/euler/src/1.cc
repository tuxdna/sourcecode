#include <iostream>
using namespace std;
int main() {
  int sum = 0;
  
  for( int i = 1; i < 1000; i++ ) {
    if( 0 == (i % 3) ) {
      sum += i;
      continue;
    }
    if ( 0 == (i % 5) ) {
      sum += i;
      continue;
    }
  }

  cout << "sum " << sum << endl;
}
