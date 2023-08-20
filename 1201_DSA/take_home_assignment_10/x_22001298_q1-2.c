#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

int i=-1;

node* newnode(int key){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insert(int data, int i){
	int array[15];
	array[1]=data;
	printf("%d\t",array[i]);
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);

		inorder(root->right);
	}
}

int main(){
	node* root=NULL;
	root=newnode(15);
	root->left=newnode(10);
	root->right=newnode(20);
	root->left->left=newnode(8);
	root->left->right=newnode(12);
	root->right->right=newnode(25);
	root->right->left=newnode(17);
	root->left->left->left=newnode(5);
	root->left->left->right=newnode(9);
	root->left->right->right=newnode(14);
	root->right->right->right=newnode(30);
	root->right->right->left=newnode(22);
	printf("Output Array :\t");
	inorder(root);
	printf("\n");
	return 0;
}
