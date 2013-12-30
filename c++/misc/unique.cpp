#include <iostream>
using namespace std;
int main(int args, char *argv[]) {
  // const int SIZE = 5;
  // int a[SIZE] = { 1 , 2, 2, 3, 4 };
  const int SIZE = 2;
  int a[SIZE] = { 1, 1};
  int i,j;

  for(i = 0, j = 0; j<SIZE; a[i+1] = a[j], j++, i++) {
    while(a[i] == a[j] && j < SIZE) {
      j++;
    }
  }

  i = i<SIZE ? i+1 : i;

  for(int k = 0; k < i; k++) {
    cout << a[k] << ", ";
  }
  cout << endl;

}
