#include<stdio.h>
struct node{
    int data;
    struct node * next;
}
struct node * head,tail = NULL;
head = (struct node * )malloc(sizeof(struct node));
tail = (struct node * )malloc(sizeof(struct node));

struct node * insert(int ele){
    if(head == NULL){
        head->data = ele;
        head->next = null;
        tail = head;
    }else{
        new = (struct node*)malloc(sizeof(struct node));
        new->data = ele;
        new->next = NULL;

        tail->next = new;
        tail = new;
    }
    return tail;
}

void printList(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}
)
void main(){

int arr[] = [1,2,3,4,5];
struct node * root = NULL;
for(int i= 0;i<5;i++){
    root = insert(arr[i]);
}
printList();
}