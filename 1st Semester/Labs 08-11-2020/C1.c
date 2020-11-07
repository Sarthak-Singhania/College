#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev,*next;
};// next points to the next structure instance or is NULL

struct Node *prev_pos = NULL;
struct Node *listp = NULL;
struct Node *last = NULL;

struct Node *insert(struct Node *listp, int pos, int info) {
  /*Inserts a Node in list at position pos with data info
    pos>0. If pos>list length then new node added at end.
    If pos<1 adds at beginning.
  */
  struct Node *new=malloc(sizeof(struct Node)), *prev_pos;
  //create new node and initialize fields
  new->data=info;
  new->next=NULL;
  new->prev=NULL;
  if (listp==NULL) listp=new;
  else
    if (pos<=1) {
      new->next=listp;
      listp=new;
    }
    else {
    //pos>1. Go to node at pos-1.
    prev_pos=listp;
    int i=1;
    while ((i++<pos-1) && prev_pos->next!=NULL) {
      prev_pos=prev_pos->next;
    }
    new->next=prev_pos->next;
    prev_pos->next=new;
    last=new;

  }
  return listp;
}

struct Node *delete(struct Node *listp, int pos) {
  /*Deletes Node at position pos. pos>0.
    If pos> list length then deletes last node.
    If pos<1 deletes first node.
  */
  struct Node *prev_pos, *temp;
  if (listp==NULL) return NULL;
  else
    if (pos<=1) listp=listp->next;
    else {//pos>1
    int i;
    prev_pos=listp;
    i=1;
    while (i++<pos-1 && (prev_pos->next)->next!=NULL) {
      prev_pos=prev_pos->next;
    }
    temp=prev_pos->next;//node to be deleted
    prev_pos->next=(prev_pos->next)->next;//node removed from list
    free(temp);//send memory back to store
  }
  return listp;
}

int findSize(struct Node *listp) 
{ 
   int len = 0; 
   while (listp != NULL) 
   { 
       len++; 
       listp = listp->next; 
   } 
   return len;
} 

void search(int data) {
   int pos = 0;
   
   if(listp==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   prev_pos = listp;
   while(prev_pos!=NULL) {
      pos++;
      if(prev_pos->data == data) {
         printf("%d found at position %d\n", data, pos);
         return;
      }

      if(prev_pos->next != NULL)
         prev_pos = prev_pos->next;
      else
         break;
   }

   printf("%d does not exist in the list\n", data);
}

void printNode(struct Node *listp) {
  struct Node *tmp=listp;
  printf("[");
  while (tmp!=NULL) {
    printf("%d ", tmp->data);
    tmp=tmp->next;
  }
  printf("]\n");

}

int main(void) {
  char op;
  int pos, info,data;
  struct Node *listp=NULL;
  //operation loop
  while (1) {
    printf("Operation add(a)/delete(d)/length(l)/search(s)/exit(e) = ");
    scanf("%c",&op);
    getchar();//purge the newline
    switch (op){
      case 'a':{
        printf("Give position and data for insert = ");
        scanf("%d %d", &pos, &info);
        getchar();//purge the newline char
        listp=insert(listp, pos, info);
        printNode(listp);
        break;}
      case 'd':{
        printf("Give position for delete = ");
        scanf("%d", &pos);
        getchar();//purge newline char
        listp=delete(listp, pos);
        printNode(listp);
        break;}
      case 'l':
      {
        printf("Length of list = %d\n", findSize(listp));
        break;
      }
      case 's':
      {
        printf("Give data to search = ");
        scanf("%d", &data);
        getchar();
        search(data);
      }
      case 'e': {return 0;}
      default: {printf("Illegal operation\n");}
    }
  }
  return 0;
}