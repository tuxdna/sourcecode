struct data_st
{
  int c;
  int freq;
};

struct node_st
{
  struct data_st data;
  struct node_st *next;
  struct node_st *left, *right;
};

struct node_st *getnode()
{
  return (struct node_st*)calloc(1,sizeof(struct node_st));
}

int q_insert(struct node_st** front, struct node_st* new)
{
  struct node_st *tmp, *prev;
  int flag;
  if(new==NULL) {
    perror("insert():new is NULL");
    return -1;
  }

  if(*front==NULL) {	
    new->next=NULL;
    *front=new;
    return 0;
  }

  tmp=prev=*front;
  if(tmp->data.freq < new->data.freq) {
    new->next=tmp;
    *front=new;
    return 0;
  }

  tmp=tmp->next;
  while(tmp!=NULL) {
    if(tmp->data.freq < new->data.freq) {
      prev->next=new;
      new->next=tmp;
      return 0;
    }
    prev=tmp;
    tmp=tmp->next;
  }
  prev->next=new;
  return 0;
}

struct node_st* q_getmin(struct node_st** front)
{
  struct node_st *tmp, *prev;
  if(*front==NULL) {
    return NULL;
  }

  tmp=prev=*front;

  if(tmp->next==NULL) {
    *front = NULL;
    return tmp;
  }

  while(tmp->next!=NULL) {
    prev=tmp;
    tmp=tmp->next;
  }

  prev->next=NULL;
  return tmp;
}
