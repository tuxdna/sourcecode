#include <iostream>
#include <cmath>
#include "prime.cc"
using namespace std;

#define ASIZE 10001
// #define ASIZE 6

int main() {
  long primes[ASIZE];
  int n, pidx;
  for (  n = 2, pidx=0; pidx < ASIZE; n++) {
    if(isPrime(n)) {
      primes[pidx] = n;
      cout << pidx << ": " << n << endl;
      pidx++;
    }
  }
  
  cout << ASIZE << " prime: " << primes[ASIZE-1] << endl;
}


