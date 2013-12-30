#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myComparisonFunction(const void *x, const void *y)
{
  return (strcmp(*(const char **)x, *(const char **)y));
}

int main()
{
  FILE *fp=NULL;
  char str[100];

  char *words[200]={0};

  int ctr=0;

  int i;
  int size;
  int choice;
	

  fp=fopen("data.txt", "r");
  if(fp==NULL) {
    printf("File could not be opened!\n");
    exit(EXIT_FAILURE);
  }

  while(!feof(fp)) {
    fscanf(fp, "%s\n", str);
    words[ctr] = strdup(str);
    ctr++;
  }

  size=ctr;

  printf("%d words\n", size);
  qsort(words, size, sizeof(words[0]), &myComparisonFunction); 

  for(i=0;i<size; ++i) {
    printf("Word %3d : [%s]\n", i,words[i]);
  }
	
  do {
    printf("Enter a string to lookup( for the succeding word in order ):");
    scanf("%s", str);
    for(i=0;i<size;++i) {
      if(strcmp(str, words[i])<0) {
        printf("Found: %s\n", words[i]);
        break;
      }
    }

    printf("Do you want to continue?(y/n):");
    while(getchar()!='\n')
      ;		
    choice = getchar();

  } while(choice=='y');

  exit(EXIT_SUCCESS);
}

