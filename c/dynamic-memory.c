#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int main(int argc, char *argv[]) {
  int i=0;
  void *ptr, *new_ptr;
  int ptr_size = 4096; // sizeof(int *);

  if (argc > 1)
    ptr_size = atoi(argv[1]);

  printf("data size for malloc call: %d\n", ptr_size);
  ptr = malloc( ptr_size );
  for(i=0; i<SIZE; i++) {
    new_ptr = malloc( ptr_size );
    printf("allocating %d bytes at %p : size difference %d\n", ptr_size, ptr, (new_ptr - ptr));
    ptr = new_ptr;
  }
  return 0;
}
