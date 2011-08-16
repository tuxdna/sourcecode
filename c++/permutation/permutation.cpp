/*
  Johnson Trotter Algorithm - Generate all permutations
*/

#include <iostream>

using namespace std;


#define LEFT -1
#define RIGHT +1

class JtPermutation {
private:
  int *numbers;
  int *direction;
  int n_size;

  void initialize(int sz) {
    n_size = sz;
    numbers = new int[n_size];
    direction = new int[n_size];
    reset();
  }
  
  bool is_mobile_pos(int pos) {
    int next_pos = pos + direction[pos];
    if(next_pos < 0 || next_pos >= n_size) {
      return false;
    }
    return numbers[pos] > numbers[next_pos];
  }

  bool is_mobile() {
    for(int i = 0; i < n_size; i++ ) {
      if ( is_mobile_pos(i) ) {
	return true;
      }
    }
    return false;
  }
  
  void print_perm() {
    for(int i = 0; i < n_size; i++ ) {
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
  
public:
  JtPermutation(int n) {
    initialize(n);
  }

  ~JtPermutation() {
    delete numbers;
    delete direction;
  }

  void printAll() {
    // print first permutation
    print_perm();
    
    // while atleast one mobile element is present
    while(is_mobile()) {
      
      // find largest mobile element: k
      int max_pos = -1;
      for( int i = 0; i < n_size; i++ ) {
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
      for( int i = 0; i < n_size; i++ ) {
	if(numbers[i] > numbers[next_pos]) {
	  direction[i] *= -1;
	}
      }
      
      // print the permutation
      print_perm();
    }
  }

  void reset() {
    for(int i = 0; i < n_size; i++ ) {
      direction[i] = LEFT;
      numbers[i] = i+1;
    }
  }

  
};

int main(int argc, char *argv[]) {
  int n = 5;
  cout << "Enter a number:" << endl;
  cin >> n;
  JtPermutation jt(n);
  jt.printAll();
  cout << "reset..." << endl;
  jt.reset();
  cout << "print all again..." << endl;
  jt.printAll();
}
