#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
struct list 
  {int data;
   struct list * next; 
  }; 
typedef struct list List;  
int ListIsEmpty( List * head);
unsigned int ListItemCount( List * head);
void Traverse( List * head);
void Replace( List **ptr,int a,List * target);
List * SeekItem( List * head,int a);
bool InsertItem( List *head,int a,List * target);
int InsertHeadItem(List ** ptr,List * target);
List * AddItem( List * head);
int main(void)
{
}
int ListIsEmpty( List * head)
{
	if(head==NULL)
	return true;
	else return false;
 } 
unsigned int ListItemCount( List * head)
{
	unsigned int count=0;
	List * p=head;
	while(p!=NULL){
		++count;
		p=p->next;
	}
	return count;
}
void Traverse( List * head)
{
	int count = 0;
	List * p=head;
	while(p!=NULL){
		++count;
		printf("%d%10d\n",count,p->data);
		p=p->next;
	}
}
void Replace( List **ptr,int a,List * target)//Replace(ptr,a,target);List **ptr  {
	List * p=*ptr;
	List * pr=p;
	if(*ptr==NULL) {
		printf("nothing!");
		exit(0); 
	}
	while(p!=NULL&&p->data!=a){
		pr=p;
		p=p->next;
	}
	if(p==NULL){
		printf("not found!");
		exit(1);
	}
	
	if(p!=NULL){
		if(*ptr==p){
			target->next=p->next;
			*ptr=target;
			free(p);
		}
        else{
		
			target->next=p->next;
		    pr->next=target;
		    free(p);
         }
		
	}
}
	
 
List * SeekItem( List * head,int a)
{
	int count=0;
	List * p,* pr;
	p=head;
	pr=p;
	if(head==NULL){
		printf("nothing!");
		exit(0);
	}
	while(p!=NULL){
		count++;
		pr=p;
		if(p->data==a){
			printf("find it , it's %d\n",count);
			return p;
		}
		p=p->next;
	}
	if(p=NULL){
		printf("not found!");
		return NULL;
	}
}
bool InsertItem( List * head,int a,List * target)
{
	List * p;
	p=SeekItem(head,a);
	if(p==NULL){
		printf("not found !");
		return false;
	}
	target->next=p->next;
	p->next=target;
	return true;
}
int InsertHeadItem(List ** ptr,List * target)
{
	target->next=*ptr;
	*ptr=target;
	return true;
}
List *AddItem( List * head)
{
	List * pr=head;
	List * p=NULL;
	p=(List *)malloc(sizeof(List));
	if(p==NULL){
		printf("can't' malloc!");
		
	}
	p->next=NULL;
	printf("please input data :");
	scanf("%d",&p->data);
	if(head==NULL){
		head=p;
		
	}
	else{
	
      while(pr->next!=NULL){
		pr=pr->next;
		printf("text!\n");
	  }
	  pr->next=p;
	  
    }
    Traverse(head);
	return head;
}


