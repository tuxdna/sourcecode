#include <stdio.h>
int main(int argc, char *argv[])
{
  int c;
  setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
  while( (c = getchar()) != EOF) {
    putchar(c);
  }
  return 0;
}
