#include <iostream>
#include <cmath>

using namespace std;

int nthDigitFromRight(int num, int pos) {
  // assuming pos > 0
  int i;
  int d;
  do {
    d = num % 10;
    num = num / 10;
    pos --;
  } while( pos > 0 );

  return d;
}

bool isPalindrome(int n) {
  // find number of digits
  int ndigits  = 0;
  int tmp = n;
  int i = n;
  while(i > 0) {
    i = i / 10;
    ndigits++;
  }

  // check for palindrome
  for(int k = 1; k < ndigits; k++, ndigits--) {
    if( nthDigitFromRight(n,k) != nthDigitFromRight(n,ndigits) ) {
      return false;
    }
  }

  return true;
}


int main() {
  int  num = 9019;

  int max = 0;
  for( int i = 100; i <= 999; i++ ) {
    for( int j = 100; j <= 999; j++ ) {
      int n = i * j;
      if ( isPalindrome(n) ) {
	cout << n << endl;
	if(n>max) {
	  max = n;
	}
      }
    }
  }

  cout << "max : " << max << endl;
}
