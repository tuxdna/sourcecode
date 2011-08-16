/*Program to find Dominators*/
#include<stdio.h>
#include<stdlib.h>

int **graph;
struct Set{
  int count;
  int *set;
};

typedef struct Set Set;
Set *sets;
int nodes;

void readfile(char *fname)
{
  int i,j;
  FILE *fp;
  fp=fopen(fname, "r");
  if(fp==NULL){
    perror("Could not open the file!");
    exit(EXIT_FAILURE);
  }

  fscanf(fp,"Number of Nodes:%d\n", &nodes);
  printf("Number of Nodes: %d\n",nodes);
  graph=malloc(nodes*sizeof(int*));
  sets=malloc(nodes*sizeof(Set));
  for(i=0;i<nodes;++i) {
    graph[i]=malloc(nodes*sizeof(int));
    sets[i].set=malloc(nodes*sizeof(int));
    sets[i].count=0;

    for(j=0;j<nodes;++j) {
      fscanf(fp, "%d",&graph[i][j]);
      printf(" %d",graph[i][j]);
    }
    fscanf(fp, "\n");
    printf("\n");
  }

  for(j=0;j<nodes;++j) {
    for(i=0;i<nodes;++i) {
      if(graph[i][j]!=0) {
	sets[j].set[sets[j].count]=i+1;
	sets[j].count++;
      }
    }
  }
  
  
  /*free the graph here*/
  for(i=0;i<nodes;++i) {
    free(graph[i]);
  }
  free(graph);
  
  /*close the file*/
  fclose(fp);
  
  /*print the predecessors*/
  printf("The predecessors\n");
  for(i=0;i<nodes;++i) {
    printf("%3d: ",i+1);
    for(j=0;j<sets[i].count;++j) {
      printf(" %d",sets[i].set[j]);
    }
    printf("\n");
  }
}


Set intersection(Set s1, Set s2)
{
  int i;
  int *set;
  Set ret_set;
  ret_set.set=malloc(nodes*sizeof(int));
  ret_set.count=0;
  
  set=malloc(nodes*sizeof(int));
  
  for(i=0;i<nodes;++i) {
    set[i]=0;
  }
  for(i=0;i<s1.count;++i) {
    set[ s1.set[i]-1 ]++;
  }
  
  for(i=0;i<s2.count;++i) {
    set[ s2.set[i]-1 ]++;
  }
  
  for(i=0;i<nodes;++i) {
    if(set[i]==2) {
      ret_set.set[ret_set.count] = i+1;
      ret_set.count++;
    }
  }
  
  free(set);
  return ret_set;
}

int main()
{
  int i, j;
  readfile("graph.txt");
  /*Determine the Dominators*/
  
  /* D(n0)= {n0} */
  sets[0].count=1;
  sets[0].set[0]=1;
  
  /* for other elements */
  for(i=1;i<nodes;++i) {
    /*intersection operation here*/
    Set inter;
    inter.set=malloc(nodes*sizeof(int));
    inter.count=nodes;
    for(j=0;j<nodes;++j) {
      inter.set[j]=j+1;
    }

    for(j=0;j<sets[i].count;++j) {
      Set t;
      if(sets[i].set[j]>i+1) {
	continue;
      }

      t=intersection(inter, sets[ sets[i].set[j] - 1 ]);
      free(inter.set);
      inter=t;
    }
    free(sets[i].set);
    sets[i]=inter;
    
    /*union operation here*/
    sets[i].set[sets[i].count]=i+1;
    sets[i].count++;	
    
  }
  
  /*print the dominators*/
  printf("The dominators\n");
  for(i=0;i<nodes;++i) {
    printf("%3d: ",i+1);
    for(j=0;j<sets[i].count;++j) {
      printf(" %d",sets[i].set[j]);
    }
    printf("\n");
  }
  
  
  /*free memory used in sets*/
  for(i=0;i<nodes;++i) {
    free(sets[i].set);
  }
  exit( EXIT_SUCCESS );
}

