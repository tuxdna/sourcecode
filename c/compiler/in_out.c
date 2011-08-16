#include<stdio.h>
#define N 10 
#define TRUE 1
#define FALSE 0

int display(unsigned value, int nbits)
{
  int i;
  for(i=nbits-1;i>=0;--i) {
    putchar((value&(1<<i)) ? '1': '0');
  }
}

int main()
{
  unsigned gen[N]={0x70,0x0C,0x02,0x01};
  unsigned kill[N]={0x0F,0x61,0x10,0x48};
  int graph[N][N] = {
    {0,1,0,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,0}
  };

  unsigned in[N];
  unsigned out[N], oldout;
  int change,i,j,k,n, pass;
	
  printf("Gen values:\n");
  for(i=0;i<4;++i) {
    printf("Block-%d :  ",i);
    printf("gen[%d]:",i);
    display(gen[i], 7);
    printf("  ");
    printf("kill[%d] :",i);
    display(kill[i], 7);
    printf("\n");
  }
		

	
  printf("Enter the no of blocks:");
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    in[i]=0;
    out[i]=gen[i];
  }

  printf("INITIAL\n");
  for(i=0;i<4;++i) {
    printf("Block-%d :  ",i);
    printf("in[%d]:",i);
    display(in[i], 7);
    printf("  ");
    printf("out[%d] :",i);
    display(out[i], 7);
    printf("\n");
  }
	
  change=1;
  pass=1;
	
  while(change) {	
    change=0;
    printf("\nPass %d:\n", pass);
    for(i=0;i<n;i++) {
      for(k=0;k<n;k++) {
	if(graph[k][i]==1) {
	  in[i]|=out[k];
	}
      }
      oldout=out[i];
      out[i]=gen[i]|(in[i]&(~kill[i]));
      if(out[i]!=oldout)
	change=1;

      printf("in[%d]:",i);
      display(in[i], 7);
      printf(" ");
      printf("out[%d] :",i);
      display(out[i], 7);
      printf("\n");

    }
    pass++;
  }
}
