#include<stdio.h>

#define alen 8
#define blen 26
int a[alen];
int b[blen];

int values[alen][2]={{0}};

void show(void)
{
  int i;
  for(i=0;i<alen;++i) {
    printf("(%d,%d) ",
	   values[i][0],
	   values[i][1]
	   );
  }
  printf("\n");
}

void perm(int ai, int bi)
{
  int idx;
  if(ai==alen) {
    show();
    return;
  }

  for(idx=bi;idx<blen-(alen-ai); ++idx) {
    values[ai][0]=ai;
    values[ai][1]=idx;

    perm(ai+1,idx+1);
  }
}

int main()
{
  int i;
  for(i=0;i<alen;++i){ 	a[i]=i; }
  for(i=0;i<blen;++i){	b[i]=i; }

  perm(0,0);
	
  return 0;
}


