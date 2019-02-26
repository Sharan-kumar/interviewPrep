#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

struct node* insert(struct node*head,int ele)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return head;
    }
}

void printList(struct node *temp)
{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct node * deleteLast(struct node*head){
	struct node * temp = head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct node * del = temp->next;
	temp->next = NULL;
	free(del);
	return head;
}

struct node * insertAtHead(struct node *head, int ele){
	struct node *new  = NULL;
	new = (struct node *)malloc(sizeof(struct node));
	new->data = ele;
	new->next = head;
	return new;
}

struct node * insertAtTail(struct node *head, int ele){
	struct node *new  = NULL;
	new = (struct node *)malloc(sizeof(struct node));
	new->data = ele;
	struct node * temp = head;
	while(temp->next!=NULL){
		temp = temp ->next;
	}
	temp->next = new;
	new -> next = NULL;
	return head;
}

void main()
{
    int i;
    struct node *head=NULL;
    int ele[] = {6,7,8,9,10};
    for(i=0;i<5;i++)
    {
        head=insert(head,ele[i]);
    }
    printList(head);
    head = deleteLast(head);
    printList(head);
    head = insertAtHead(head,3);
    printList(head);
    head = insertAtTail(head,11);
    printList(head);
    
}
