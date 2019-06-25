#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head,*tail = NULL;

struct node * insert(int ele){
	    struct node * new;
        new = (struct node*)malloc(sizeof(struct node));
        new->data = ele;
        new->next = NULL;
    if(head == NULL){
        head = new;
        tail = head;
    }else{

        tail->next = new;
        tail = new;
    }
}

void printList(struct node *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int lengthList(struct node * temp){
	int count = 0;
	while(temp != NULL){
		count+=1;
		temp= temp-> next;
	}
	return count;
}


void reverseLinkedList(){
	struct node * temp,* temp1,*rev;
	int i;
	temp = temp1 =rev =  (struct node *)malloc(sizeof(struct node));
	rev = tail;
	temp = head->next;
	temp1 = head;
	while(temp->data != rev->data){
	while(temp->next->data != rev->data){
		temp= temp->next;
		temp1= temp1->next;
	}
	temp1->next = temp->next;
	tail->next = temp;
	temp->next = NULL;
	tail = temp;	
	temp = head->next;
	temp1 = head; 
}
head=temp;
tail->next  = temp1;
temp1->next = NULL;
}


void main(){

int i,arr[] = {1,2,3,4,5};
for(i= 0;i<5;i++){
    insert(arr[i]);
}
printList(head);
printf("\n");
//printf("%d",lengthList(head));
reverseLinkedList();
printf("\n");
printList(head);
}
