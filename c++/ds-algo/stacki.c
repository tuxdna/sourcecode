#include<stdio.h>
#include<stdlib.h>
#include "stacki.h"
#define STACKSIZE 30

int main() {

  struct stacki stk;
  int num, choice=0;
  if(getstack(&stk,STACKSIZE)==0) {
    perror("stack could not be created");
    exit(1);
  }

  while(choice!=4) {
    printf("\n\t\t\tSTACK Menu:");
    printf("\n\t1 - Push");
    printf("\n\t2 - Pop");
    printf("\n\t3 - Show");
    printf("\n\t4 - Exit");
    printf("\n\tChoice [1-4]?");
    fflush(stdin);
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice) {
    case 1:
      printf("\nEnter a number:");
      scanf("%d",&num);
      if(push(&stk, num)) {
	printf("\nPUSHED: %d \n", num);
      }
      break;
    case 2:
      if((num=pop(&stk))!=-1) {
	printf("\nPOPPED: %d\n",num);
      }
      break;
    case 3:
      showstack(&stk);
      break;
    case 4:
      return 0;
    default:
      printf("\nI dont understand that choice!\n");
      break;
    }
  }
  return(0);
}

