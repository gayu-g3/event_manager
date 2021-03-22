#include<stdio.h>
#include<stdlib.h>

#include"init_head.h"

struct node
{
    int id;
    int bit;
    int (*cb)();
    struct node *next;
   
} *head = NULL;



int register_the_event (int id,int bit, int (*ptr)())
{
   struct node *new =(struct node*)malloc(sizeof(struct node));
   struct node *temp=head;

	if(temp == NULL)
	{
            new->bit =bit;
            new->id = id;
            new->cb = ptr;
            new->next = NULL;
            head = new;
	} else {
	      while(temp->next != NULL) {
	          temp = temp->next;
              }
	      new->bit =bit;
              new->id = id;
              new->cb = ptr;
	      new->next = NULL;
              temp->next = new;
	}
	return 0;
}

int event_execute(int event)
{
  struct node *temp=head;
  while(temp!=NULL){
     if ((temp->bit>>(event-1))&1){
        temp->cb(event);
       } 
      temp=temp->next;
    }
return 0;
}

int freeup(){
 struct node *temp=head;
 while(temp!=NULL){
    head=temp->next;
    free(temp);  
    temp=head;
   }
return 0;
   

}
