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
        printf("%d",temp->data);
        temp = temp->next;
    }
}

void main(){

int i,arr[] = {1,2,3,4,5};
for(i= 0;i<5;i++){
    insert(arr[i]);
}
printList(head);
}
