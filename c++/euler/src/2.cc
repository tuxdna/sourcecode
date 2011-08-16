#include<iostream>
using namespace std;
int main() {
  const int limit = 4000000;
  // const int limit = 34;
  int sum = 0;
  int a = 1;
  int b = 2;
  sum += b;

  while ( b <= limit ) {
    int t = a;
    a = b;
    b += t;
    if ( 0 == b%2 ) {
      sum +=  b;
    }
  }

  cout << "sum " << sum << endl;
}
