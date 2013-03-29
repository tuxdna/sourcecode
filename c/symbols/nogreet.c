#include<stdio.h>

#include "greet.h"

/* void say_hello0(void) { */
/*   printf("hello, "); */
/* } */

/* void say_hello1(void) { */
/*   printf("hello, "); */
/* } */

/* void say_hello2(void) { */
/*   printf("hello, "); */
/* } */

/* void say_hello3(void) { */
/*   printf("hello, "); */
/* } */

void say_hello4(void) {
  printf(__FILE__"hello, ");
}

void say_hello5(void) {
  printf("hello, ");
}

void say_hello6(void) {
  printf("hello, ");
}

void say_greet(char *s) {
  printf("%s\n",s);
}
