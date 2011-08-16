#include <iostream>

using namespace std;
/*
http://dhost.info/zabrodskyvlada/aat/a_eucl.html
GCD(A,B)=GCD(B,A)
GCD(A,B)=GCD(-A,B)
GCD(A,0)=ABS(A)

*/
long gcd(long a, long b) {
  if(b == 0 ) {
    return a;
  }

  return gcd(b, a%b);
}

long lcm(long a, long b) {
  return a * b / gcd(a, b);
}

int main () {
  // cout << gcd (10, 20) << endl;

  long lcmval = lcm(1,2);

  for( long i = 3; i <= 20; i++ ) {
    lcmval = lcm(lcmval, i);
  }
  
  cout << lcmval << endl;
}
