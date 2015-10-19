//Master header file
//contains all necessary functions to 
//implement the Binary Search tree cpp file
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stdio.h>
using namespace std;
//create file stream variable
ifstream file;
int counter = 0;
int numOfNodes = 0;

//initialize Node Struct with left, right, parent aspects
struct Node {
        int value;
        Node * right = nullptr;
        Node * left = nullptr;
	Node * par = nullptr;
        }*root = NULL, *p=NULL, *z=NULL; // Nodes for root, parent and z node
        
// void function openFile to open file stream of command line argument        
void openFile(string input)
{

  if(input.empty() || input == "")
    {
      cout<<"Nothing to open"<<endl;
    }
  else
    {
      file.open(input);
      cout<<"File stream opened!"<<endl;
        counter = 1;
    }
  return;
}

//void function closeFile to close the file stream
void closeFile(void)
{
  if(counter)
    {
      file.close();
      cout<<"File Stream closed!"<<endl;
        counter = 0;
    }
  else
    {
      return;
    }
}

//int function to return the height. Does a recursive check of the left and right subtrees
int treeHeight(Node* n){
 int l = 0;
 int r = 0;
int a = 0;
 if(n == NULL){
     return 0;
         }
 l = treeHeight(n->left);
 r = treeHeight(n->right);
  if(l>r || l == r){
	a = (l+1);
     return a;}
  else{
	a = (r+1);
      return a;
	}
      }

//int function treeSize returns the total number of nodes in the tree
int treeSize(void){
  return numOfNodes;
}

//function treeMin checks for the minimum node in the tree
Node* treeMin(Node* n){
	if(n==NULL)
                return NULL;
     	while(n->left != NULL)
		n = n->left;
 	 return n;
}		

//void function to insert a node into the tree given certain insert cases
void insert(int number){
  int i = 1;
  if(root == NULL){
    root = new Node;
    root->value = number;
    numOfNodes++;
  }
  else {
    p = root;
    while(i){
      if((number)>(p->value)&&p->right!=NULL)
	p=p->right;
      else if((number)>(p->value)&&p->right==NULL){
	p->right = new Node;
	p->right->par = p;
	p = p->right;
	p->value = number;
	p->right = NULL;
	p->left = NULL;
	i = 0;
	numOfNodes++;
      }
      else if((number)<(p->value)&&p->left!=NULL)
	p=p->left;
      else if((number)<(p->value)&&p->left==NULL){
	p->left = new Node;
	p->left->par = p;
	p = p->left;
	p->value = number;
	p->right = NULL;
	p->left = NULL;
	i = 0;
	numOfNodes++;
      }
      else if(number ==p->value)
	i = 0;
    }
  }
}      

//void deleteNode function deletes a given node based on certain cases
void deleteNode(Node* n){
	p = NULL;;
        if(n->right == NULL && n->left !=NULL){
		p = n->left;
		p->par = n->par;
		if(n == root)
			root = p;
		 else if(n == n->par->left)
                                p->par->left = p;
                        else if(n==n->par->right)
                                p->par->right = p;
		n->par = NULL;
		n->left = NULL;
		n->right = NULL;}
	else if(n->right == NULL && n->left ==NULL){
		if(n == root)
                        root = NULL;
                 else if(n == n->par->left)
                                n->par->left = NULL;
                        else if(n==n->par->right)
                                n->par->right = NULL;
		n->par = NULL;
		
}
	else {
		p = treeMin(n->right);
		if(p->par !=n && p->right == NULL){
			n->value = p->value;
			p->par->left = NULL;
			p->par = NULL;
}
		else if(p->par != n && p->right != NULL){
			z = p->right;
			z->par = p->par;
			if(z->par)
			z->par->left = z; 
			p->par = n->par;
			if(n==root)
                                root = p;
			else if(n == n->par->left)
                                p->par->left = p;
                        else if(n==n->par->right)
                                p->par->right = p;
			p->right = n->right;
			p->left = n->left;
			if(p->left)
			p->left->par = p;
			if(p->right)
			p->right->par = p;
			n->left = NULL;
			n->right = NULL;
			n->par = NULL;}
		else if(p->par == n && p->right == NULL){
			p->par = n->par;
			if(n==root)
                                root = p;
			else if(n == n->par->left)
                                p->par->left = p;
                        else if(n==n->par->right)
                                p->par->right = p;
			p->left = n->left;
			if(p->left)
			p->left->par = p;
			n->left = NULL;
			n->right = NULL;
			n->par = NULL;}
		else if(p->par == n && p->right != NULL){
			p->par = n->par;
			p->left = n->left;
			if(p->left)
			p->left->par = p;
			if(n==root)
				root = p;
			else if(n == n->par->left)
                                p->par->left = p;
                        else if(n==n->par->right)
                                p->par->right = p;
			n->left = NULL;
                        n->right = NULL;
                        n->par = NULL;}
	



	}
numOfNodes--;
		
}

//function getRoot gets the root of the tree
Node* getRoot(){
  return root;
}

//function findNode finds a specific node in the tree
Node* findNode(int number){
	p = root;
          if(p == NULL)
              return NULL;
           while(p){
              if(p->value > number && p->left != NULL)
               p = p->left;
		else if(p->value > number && p->left == NULL)
			return NULL;
               else if(p->value < number&& p->right != NULL)
                p = p->right;
		else if(p->value < number && p->right==NULL)
			return NULL;
                else if(p->value == number)
                     return p;
      		}
	return NULL;
 	}
//Recursive preorder function displays the preorder traversal of the tree. Prints from the left of the node
void preorder(Node *n){
  if(n){
    cout<< n->value << " ";
    preorder(n->left);
    preorder(n->right);
  }
}

//Recursive inorder function displays the inorder traversal of the tree.Prints from the bottom of the node
void inorder(Node *n)
{
  if(n)
    {
      inorder(n->left);
      cout<< n->value<< " ";
      inorder(n->right);
    }
}

//REcursive postorder function displays the postorder traversal of the tree. Prints from the right of the node
void postorder(Node *n)
{
  if(n)
    {
      postorder(n->left);
      postorder(n->right);
      cout<< n->value<<" ";
    }
}

//void function readFile reads the given command line argument file, parses the string and integers. Compares if the string is
//insert or delete, based on that string compare, it will do the specified task with the related integer value
void readFile(void)
{
  int node;
  string command;
	p = NULL;
  if(counter)
    {
      while(file>>command)
	{
	  file >> node;
	  if(command == "insert")
	    insert(node);
	else if(command == "delete"){
		p=findNode(node);
		if(p)
		deleteNode(p);
	 	 }
    }
}
  return;
}
