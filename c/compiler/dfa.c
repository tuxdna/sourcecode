#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ns, na, fs, is;
int **table;

void readfile()
{
  FILE *fp;
  int r,c;

  fp=fopen("dfa3.txt","r");
  if(fp==NULL) {
      exit(EXIT_FAILURE);
  }

  fscanf(fp,"NumberOfAlphabets:%d\n", &na);
  fscanf(fp,"NumberOfStates:%d\n", &ns);
  fscanf(fp,"InitialState:%d\n", &is);
  fscanf(fp,"FinalState:%d\n", &fs);
  table=malloc( sizeof(int*) * ns);

  if(table==NULL) {
    perror("Memory allocation failure!!\n");
    exit(EXIT_FAILURE);
  }

  for(r=0;r<ns;++r) {
      table[r]=malloc( sizeof(int) * na);
      if(table[r]==NULL) {
	  perror("Memory allocation failure!!\n");
	  exit(EXIT_FAILURE);
      }
      for(c=0;c<na;++c){
	fscanf(fp, "%d", &table[r][c]);
      }
      fscanf(fp,"\n");
  }
}

void showtable()
{
  int r,c;
  printf("Number of States: %d\n",ns);
  printf("Number of Alphabets: %d\n", na);
  printf("Initial State: %d\n",is);
  printf("Final State: %d\n",fs);
	
  printf("   ");
  for(c=0;c<na;++c) {
    printf(" %c",'a'+c);
  }

  printf("\n");
  for(r=0;r<ns;++r) {
    printf("%2d:", r+1);
    for(c=0;c<na;++c) {
      printf(" %d", table[r][c]);
    }
    printf("\n");
  }
  
}

int main()
{
  char str[100];
  int cs; //current state
  int i;
  readfile();
  showtable();
  puts("Enter the input string ending with $:");
  fgets(str,99,stdin);
	
  for(cs=is, i=0;i<strlen(str) && str[i]!='$'; i++) {
    cs=table[cs-1][str[i]-'a'];
    if(cs==0){
      puts("The string is not accepted, hangs the dfa!\n");
      break;
    }
  }

  if(cs==fs){
    puts("The string is Accepted!");
  }
  else {
    puts("The string is not Accepted!");
  }

  exit(EXIT_SUCCESS);
}
