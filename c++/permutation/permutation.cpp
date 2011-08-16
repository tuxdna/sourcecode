/*
  Johnson Trotter Algorithm - Generate all permutations
 */

#include <iostream>

#define N 5

#define LEFT -1
#define RIGHT +1


using namespace std;

int numbers[N], direction[N];

void initiailize(int n) {
  for(int i = 0; i < N; i++ ) {
    direction[i] = LEFT;
    numbers[i] = i+1;
  }
}

bool is_mobile_pos(int pos) {
  int next_pos = pos + direction[pos];
  if(next_pos < 0 || next_pos >= N) {
    return false;
  }
  
  return numbers[pos] > numbers[next_pos];
}

bool is_mobile() {
  for(int i = 0; i < N; i++ ) {
    if ( is_mobile_pos(i) ) {
      return true;
    }
  }
  return false;
}

void print_perm() {
  for(int i = 0; i < N; i++ ) {
    cout << numbers[i] << (direction[i] == -1 ? "< " : "> ");
  }
  cout << endl;
}

void swap(int i, int j) {
  int tmp;

  // swap numbers
  tmp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = tmp;

  // swap direction
  tmp = direction[i];
  direction[i] = direction[j];
  direction[j] = tmp;
}

void johnson_trotter(int n) {

  initiailize(n);

  // print first permutation
  print_perm();

  // while atleast one mobile element is present
  while(is_mobile()) {

    // find largest mobile element: k
    int max_pos = -1;
    for( int i = 0; i < N; i++ ) {
      if(is_mobile_pos(i) && numbers[i] > numbers[max_pos]) {
	max_pos = i;
      }
    }

    // cout << max_pos << endl;
    if(max_pos == -1) {
      cout << "error!" << endl;
    }
    
    // swap k and the element in k's direction
    int next_pos = max_pos + direction[max_pos];
    swap(max_pos, next_pos);

    // toggle direction of elements larger than k
    for( int i = 0; i < N; i++ ) {
      if(numbers[i] > numbers[next_pos]) {
        direction[i] *= -1;
      }
    }

    // print the permutation
    print_perm();
  }
}

int main(int argc, char *argv[]) {
  int n;
  // cin >> n;
  johnson_trotter(n);
}
