bool isPrime(long n) {
  for( long i = 2 ; i <= sqrt(n); i ++ ) {
    if(n%i == 0){
      return false;
    }
  }
  return true;
}
