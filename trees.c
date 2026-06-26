#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node{
  int data;//hardcodeing to int but  can use string or void ig 
  struct Node* right;
  struct Node* left;
}Node;


Node* createNode(int dataelem){//works for me 
  Node* tmp=(Node*)malloc(sizeof(Node));
  tmp->data=dataelem;
  tmp->right=NULL;
  tmp->left=NULL;
  return tmp;
}
//For insertions let this be a BST

Node* insert(Node* root,int dataelem){//Going to be recursive btw,
  if(root==NULL){
    return createNode(dataelem);
  }
  if(dataelem<root->data){
    root->left=insert(root->left,dataelem);
  }
  else if(dataelem>root->data){
    root->right=insert(root->right,dataelem);

  }
  return root;
}
void printinorder(Node* root){//Recursive again 
  if(root==NULL){
    return ;
  }
  printinorder(root->left);
  printf(" %d ",root->data);
  printinorder(root->right);

}
int main(){
  Node* root=NULL;
  int arr[]={50, 30, 20, 40, 70, 60, 80};// change this if u want 
  int datasz=sizeof(arr)/sizeof(arr[0]);
  printf("populating the tree -=-=-\n"); 
  root=insert(root,arr[0]);
  for(int i=1;i<datasz;i++){
    insert(root,arr[i]);
  }
  
  printf("Data from tree --- \n");
  printinorder(root);
  printf("\n");
  return 0;
  
}
