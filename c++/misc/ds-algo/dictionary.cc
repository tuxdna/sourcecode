#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#include "stacki.h"

struct stacki myStack;

int myComparisonFunction(const void *x, const void *y)
{
  return (strcmp(*(const char **)x, *(const char **)y));
}

enum flag {  NO_TERMINATE=0, TERMINATE};

struct trie
{
  struct trie *nodes[256];
  enum flag f;
};

struct trie *root = NULL;

struct trie *
newTrieNode()
{
  return (struct trie*)calloc(1, sizeof(struct trie));
}

void insertAt(struct trie *node, char *word)
{
  struct trie *tmp_node = NULL;
  if(node == NULL)
    return;

  if( '\0' == *word ) {
    node->f = TERMINATE;
    return;
  }

  printf("word[n]: %c\n", *word);
		
  if(node->nodes[(int)*word] == NULL) {
    tmp_node = newTrieNode(); 
    node->nodes[(int)*word] = tmp_node;
  } else {
    tmp_node = node->nodes[(int)*word];
  }

  insertAt( tmp_node, word+1);		
}

void insert_word( char *word)
{
  // if the word contains nothing
  if(NULL == word)
    return;

  //the trie is empty
  if(NULL == root)
    root = newTrieNode();

  printf("Trying to insert word:%s \n", word);
  insertAt(root, word);
}

enum Bool { FALSE, TRUE };
enum Bool flag = FALSE;

int lookup(struct trie *node, char *word)
{
  int loopvar;
  int retval = 0;

  if( NULL == node )
    return retval;


  if( '\0' == *word ) {
    if( TERMINATE == node->f) {
      flag = TRUE;
      return 0;
    }
  }

  loopvar = (int)*word;
  while(loopvar<256) {
    push(&myStack, loopvar);
    if( NULL != node->nodes[loopvar] ) {
      printf("%c", loopvar);
      if( TRUE == flag ) {
        if( TERMINATE == node->f ) {
          int i;
          //print the stack and free it thereafter
          for(i=0; i<= myStack.top; i++) {
            putchar(myStack.data[i]);
            putchar('\n');
            myStack.top=-1;
          }
          retval = 1;
          break;
        }
      }

      retval = lookup( node->nodes[loopvar], word+1);
      if( 1 == retval ) // finished the search {
        break;
    } else {
      printf(".");
      flag=TRUE;
    }

    pop(&myStack);
    
    loopvar++;
  }
  return retval;
}

void findNextWord(char *word)
{
  flag = FALSE;
  lookup(root, word);
}

int main()
{
  FILE *fp=NULL;
  char str[100];

  int choice;

  getstack( &myStack, 200 );
  fp=fopen("data.txt", "r");
  if(fp==NULL) {
    printf("File could not be opened!\n");
    exit(EXIT_FAILURE);
  }

  while(!feof(fp)) {
    fscanf(fp, "%s\n", str);
    insert_word(str);
  }

  do{
    printf("Enter a string to lookup( for the succeding word in order ):");
    scanf("%s", str);
    findNextWord(str);
    printf("Do you want to continue?(y/n):");
    while(getchar()!='\n')
      ;		
    choice = getchar();
  }while(choice=='y');
  exit(EXIT_SUCCESS);
}

