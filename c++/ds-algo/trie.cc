#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>


using namespace std;

#define MAX_SIZE 100
#define MAX_STRING_SIZE 1024
#define TRIE_NODES_SIZE 256

class TrieNode {
public:
  TrieNode *nodes[TRIE_NODES_SIZE];
};

class Trie {
private:
  TrieNode *rootNode;

  TrieNode* newTrieNode() 
  {
    return (TrieNode*)calloc(1, sizeof(TrieNode));
  }

  void destroy(TrieNode *node) {
    if( NULL == node ) {
      return;
    }

    for(int i = 0; i<TRIE_NODES_SIZE; i++) {
      TrieNode *nthNode = node->nodes[i];
      if( NULL != nthNode ) {
        destroy(nthNode);
      }
    }

    free(node);
  }

  //vector<string>
  void allWordsAtNode(TrieNode *node, char *stack, int stackSize, int stackPosition, vector<string> &lvec) {
    //vector<string> wordListVector;
    if(NULL == node) {
      return;
    }

    for(int i = 0; i<TRIE_NODES_SIZE; i++ ) {
      TrieNode *currNode = node->nodes[i];

      if(NULL != currNode) {
        ++ stackPosition;
        stack[stackPosition] = i;

        if(i==0) {
          lvec.push_back(stack);
        }

        allWordsAtNode(currNode, stack, stackSize, stackPosition, lvec);
        -- stackPosition;
        
      }
    }
  }

public:
  Trie() {
    rootNode = NULL;
  }

  ~Trie() {
    cout << "Trie destructor called:!" << endl;
    clear();
  }

  void clear() {
    destroy(rootNode);
    rootNode = NULL;
  }

  void add(char *word) {
    if(word == NULL)
      return;

    // initialize root node if its not yet initialized
    if(NULL == rootNode)
      rootNode = newTrieNode();

    printf("Trying to insert word: [%s]...\n", word);
    //     insertAt(root, key, word);

    TrieNode *currNode = rootNode;
    unsigned int i = 0;
    for(i = 0; i<=strlen(word); i++) {
      int c = word[i];
      cout << "checking: " << (char)c << endl;
      TrieNode *tempNode = currNode->nodes[c];
      if(NULL == tempNode) {
        break;
      }
      currNode = tempNode;
    }

    for(; i<=strlen(word); i++) {
      int c = word[i];
      cout << "adding: " << (char)c << endl;
      TrieNode *tempNode = newTrieNode();
      currNode->nodes[c] = tempNode;

      currNode = tempNode;
    }
  }

  bool lookup(char *key)
  {
    if(key==NULL)
      return false;
    TrieNode *currNode = rootNode;
    unsigned int i;
    for( i = 0; i < strlen(key) && currNode != NULL; i++ ) {
      int c = key[i];
      cout << "checking: " << (char)c << endl;
      currNode = currNode->nodes[c];
    }
    return currNode != NULL;
  }

  TrieNode* lookupNode(char *key)
  {
    if(key==NULL)
      return NULL;

    TrieNode *currNode = rootNode;
    unsigned int i;
    for( i = 0; i < strlen(key) && currNode != NULL; i++ ) {
      int c = key[i];
      cout << "checking: " << (char)c << endl;
      currNode = currNode->nodes[c];
    }
    return currNode;
  }

  void list(vector<string> &lvec) {
    const int stackSize = MAX_STRING_SIZE;
    char *stack = (char*)calloc(1, sizeof(char) * stackSize);
    allWordsAtNode(rootNode, stack, stackSize, -1, lvec);
    free(stack);
  }

  void listBeginsWith(char *beginsWith, vector<string> &lvec) 
  {
    TrieNode *currNode = lookupNode(beginsWith);
    const int stackSize = MAX_STRING_SIZE;
    char *stack = (char*)calloc(1, sizeof(char) * stackSize);
    strcpy(stack, beginsWith);
    allWordsAtNode(currNode, stack, stackSize, strlen(beginsWith)-1, lvec);
    free(stack);
  }

};

char * readLine(char *s, int sz, FILE *in) {
  fgets(s, sz, in);
  int len = strlen(s);
  if(s[len-1] == '\n') {
    s[len-1] = 0;
  }
  return s;
}


int main()
{
  FILE *fp=NULL;
  char str[MAX_SIZE];
  //int choice;

  Trie trie;

  // input file contains words separated with newline '\n'
  fp=fopen("data.txt", "r");
  if(fp==NULL) {
    printf("File could not be opened!\n");
    exit(EXIT_FAILURE);
  }

  while(!feof(fp)) {
    // read a line
    //     fscanf(fp, "%s\n", str);
    readLine(str, MAX_SIZE, fp);
    
    // add to trie
    printf("adding string: [%s]...\n", str);
    trie.add(str);
  }

  // close input file
  fclose(fp);

  //   do {
  printf("Enter a word to look for anagrams-set: ");
  //     scanf("%s", str);
  char *s  = (char*)"codejam ";
  if(trie.lookup(s)) {
    cout << "Found: " << s << endl;
  } else {
    cout << "Not found: " << s << endl;
  }
  printf("Do you want to continue?(y/n):");
  //     while(getchar()!='\n')
  //       ;		
  //     choice = getchar();
  //   } while(choice=='y');
  cout << endl;

  vector<string> v;

  trie.list(v);
  v.clear();

  
  trie.listBeginsWith((char*)"cod", v);


  for(vector<string>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }


  //   char sp[] = "";
  //   cout << strlen(sp) << endl;

  exit(EXIT_SUCCESS);

}

