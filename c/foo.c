#include <stdlib.h>
#include <string.h>

int a = 100;
int b = 42;

int foo(void)
{
  int x = a++;

  return (x+100);
}

int main()
{
  int i = 0, j = 42;
  char c[27];
  char *m = NULL;

  for (i = 0; i<26; i++)
    c[i] = 'a'+i;

  c[26] = '\0';

  i += b*foo();
  j++;

  m = (char *)malloc(64);

  memset(m, 'a', 63);
  m[63] = '\0';

  return i+j;
}

