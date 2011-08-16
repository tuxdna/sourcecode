struct stacki
{
  int *data;
  int size;
  int top;
};

int stackempty(struct stacki *stk)
{
  if(stk->top==-1)
    return 1;
  return 0;
}

int getstack(struct stacki *stk,int size)
{
  stk->size=0;
  stk->top=-1;
  stk->data=(int*)calloc(1,size);
  if(stk->data == NULL)
    {
      return 0;
    }
  stk->size=size;
  return size;
}

int push(struct stacki *stk, int num)
{
  if( stk->top == stk->size-1 ) {
    perror("stack overflow");
    return 0;
  }
  stk->top++;
  (stk->data)[stk->top] = num;
  return 1;
}

int pop(struct stacki *stk)
{
  if(stk->top==-1) {
    perror("stack underflow");
    return -1;
  }
  return (stk->data[stk->top--]);
}

int showstack(struct stacki*stk)
{
  int i=stk->top;
  if(i==-1) {
    perror("STACK Empty");
    return 0;
  }

  printf("\n\tTOP");

  while(i>=0) {
    printf("\n\t%6d",stk->data[i]);
    i--;
  }
  printf("\n\tBOTTOM\n");
  return 1;
}

