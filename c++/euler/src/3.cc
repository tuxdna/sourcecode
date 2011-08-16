#include <iostream>
#include <cmath>
#include "prime.cc"
using namespace std;


long primeFactor(long num) {
  long n = num;
  long i = 2;
  for(; i <= n; i ++ ) {
    if( (n%i == 0)
	// && isPrime(i)
	) {
      // register the factor
      cout << "factor: " << i << endl;

      // reduce upper limit
      n = n / i;

      // reinitialize the loop index
      i = 1;
    }
  }
}

int main() {
  long  num = 600851475143;
  num = 13195;
  primeFactor(num);
}
