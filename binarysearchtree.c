#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct node * insert(struct node * root, int ele){
	if(root == NULL){
	     
	return newNode(ele);
	}else{
		if(ele > root->data){
			root->right = insert(root->right,ele);
		}
		else if(ele < root->data){
			root->left = insert(root->left,ele);
		}
		else{
			printf("\n insertion not possible!");
		}
	}
}

void preorder(struct node* tree){
	if(tree!=NULL){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

int height(struct node * tree){
	if (tree == NULL){
		return 0;
	}else{
		int lheight = height(tree->left);
		int rheight  = height(tree->right);
		
		return (lheight>rheight)?lheight+1:rheight+1;
	}
}

void printLevelOrder(struct node * tree, int level){
	if(tree == NULL){
		return;
	}else if(level == 1){
		printf("%d ",tree->data);
	}else{
		printLevelOrder(tree->left,level-1);
		printLevelOrder(tree->right,level-1);
	}
}

void levelorder(struct node *tree){
	int i;
	for(i=1;i<=height(tree);i++){
		printLevelOrder(tree,i);
	}
}



void main(){
	struct node * root = NULL;
	root = (struct node *)malloc(sizeof(struct node));
	int arr[] = {8,3,10,1,6,14,4,7,13};
	int i;
	root = insert(NULL, arr[0]);
	for(i = 1;i<9;i++){
		insert(root,arr[i]);
	}
	preorder(root);
	printf("\nHeight of the Tree: %d\n",height(root));
	levelorder(root);
}
