#include <iostream>

using namespace std;

int main () {
  long sum_squares = 0;
  long square_sums = 0;
  
  long sum = 0;
  for( long i = 1; i <= 100; i++ ) {
    sum_squares += i*i;
    sum += i;
  }
  
  square_sums = sum * sum;
  cout << sum_squares << endl;
  cout << square_sums << endl;
  cout << square_sums - sum_squares << endl;
}
