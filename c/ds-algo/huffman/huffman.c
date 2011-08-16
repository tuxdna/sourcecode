#include<stdio.h>
#include<stdlib.h>
#include "stacki.h"
#include "hufq.h"
#define STACKSIZE 50
#define MASK (0xffffffff)

struct stacki stk;
FILE *fp, *tablefp;
int tablesize=0;

struct entry
{
  char c;
  unsigned char size;
  unsigned code;
}e[256]={0};

void save(struct  data_st *d)
{
  int i;
  char c;
  unsigned code=0;
  unsigned char codesize;		
  fprintf(fp,"%c 0x%02x %10d ", d->c, d->c, d->freq );
  for(i=0;i<=(stk.top);i++) {
    fprintf(fp,"%d",stk.data[i]);
    code+=(unsigned)(1<<((stk.top) -i ))*(stk.data[i]);
  }
  codesize=stk.top+1;
  fprintf(fp," \n");
  printf("\ncode %p \tcodesize %u",code, codesize);
  e[d->c].c=d->c;
  e[d->c].size=codesize;
  e[d->c].code=code;
  tablesize++;
}

inorder(struct node_st *node)
{

  if((node->left == NULL) && (node->right == NULL))
    save(&(node->data));

  if(node==NULL)
    return;

  if(node->left != NULL) {
    push(&stk,0);
    inorder(node->left);
    pop(&stk);
  }

  if(node->right != NULL) {
    push(&stk,1);
    inorder(node->right);
    pop(&stk);
  }
  return;
}

int main(int argc, char *argv[])
{
  FILE *infile=stdin;
  char outfname[256]="/tmp/huffman.enc";
  int set[256]={0};
  struct node_st *head=NULL, *node=NULL;
  int i;
  int flag=0;

  if(argc==1) {
    printf("Usage: %s <file> <outfile>\n",argv[0]);
    printf("   <file>: it can be any file or just a - for standard input\n");
    printf("<outfile>: it is the file where huffman table is stored in _text_\n");
    printf("\t   if this parameter is missing the default output file is\n");
    printf("\t   %s\n",outfname);
    return 1;
  }	

  if(argc>=2) {
    if(strcmp(argv[1],"-")==0) {
      infile=stdin;
			
    } else {		
      printf("Reading input file: %s\n",argv[1]);
      infile=fopen(argv[1],"r");
      if(infile==NULL) {
	printf("Unsuccessfull!! Either the file does'nt"
	       " exist or not accessible.\n");
	printf("Continuing with stdin...\n");
	infile=stdin;
      }
    }
  }

  if(argc>=3)
    strcpy(outfname,argv[2]);
	
  printf("Input\n");
  while((i=fgetc(infile))!=EOF)
    set[i]++;

  printf("\n...Complete");
  if(infile != stdin) {
    flag=1;
    fclose(infile);
  }

  head=NULL;
  for(i=0;i<256;++i) {
    if(set[i]==0)
      continue;

    if((node=getnode())==NULL) {
      perror("main: node is NULL");
      exit(1);
    }
    node->data.c=i;
    node->data.freq=set[i];
    q_insert(&head,node);
  }

  if(head!=NULL) {
    struct node_st *x, *y, *z;
    while( head->next!=NULL ) {
      z = getnode();
      if(z==NULL) {
	perror("getnode() gives NULL for z");
      }
      x = q_getmin(&head);
      x->next = NULL;
      z->left = x;
      y = q_getmin(&head);
      y->next = NULL;
      z->right = y;
      z->data.freq = x->data.freq + y->data.freq;
      q_insert(&head,z);
    }
    getstack(&stk,STACKSIZE);
  }	

  if(head==NULL) {
    printf("\nWhat? No input!\n");
    exit(0);
  }

  if((fp=fopen(outfname,"w+"))==NULL) {
    printf("\nOutput file could not be created!! ");
    printf("Continuing only with stdout...\n");
    fp=stdout;
  }

  printf("\noutput file created: %s\n",outfname);
  inorder(head);
  fclose(fp);

  /*Table File Creation*/
  printf("\ntablesize %d\n",tablesize);
  tablefp=fopen("table","w+");
  fwrite(&tablesize,sizeof(tablesize),1,tablefp);

  for(i=0;i<256;++i) {
    if(e[i].size)
      fwrite(&e[i],sizeof(e[i]),1,tablefp);
  }

  if(flag) {
    unsigned xn=0,xn1=0,mask;
    int maxbit=8*sizeof(xn);
    int x=maxbit,x1=maxbit;
    infile=fopen(argv[1],"r");
    if(infile!=NULL) {
      while((i=fgetc(infile))!=EOF) {	
	e[i].code;
	mask = (~0) & (e[i].code);
	if(e[i].size <= x) {
	  mask <<= (maxbit - e[i].size);
	  mask >>= (x);
	  xn &= mask;
	  x -= e[i].size;
	  if(x==0) {
	    /*HERE---->print xn to file*/
	    fwrite(&xn,sizeof(xn),1,tablefp);
	    x=maxbit;
	  }
	} else {
	  unsigned tempmask=mask;
	  mask >>= (e[i].size - x);
	  xn |= mask;
	  /*HERE---->print xn to file*/
	  fwrite(&xn,sizeof(xn),1,tablefp);
	  mask=tempmask;
	  mask <<= ( maxbit - e[i].size + x );
	  xn |= mask;
	  x = maxbit - e[i].size + x;
	}
				
      }
    }
  }
  fclose(tablefp);
  return 0;
}
