#include<stdio.h>
int main() {
  int i = 0;
  printf("%d\n", sizeof(i));
  printf("%p\n", &i);
  printf("%p\n", (&i+1));
}
