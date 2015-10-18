//Master header file
//contains all necessary functions to 
//implement the Binary Search tree cpp file
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stdio.h>
using namespace std;
ifstream file;
int counter = 0;
int numOfNodes = 0;
struct Node {
        int value;
        Node * right = nullptr;
        Node * left = nullptr;
	Node * par = nullptr;
        }*root = NULL, *p=NULL; // Node
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
int treeHeight(Node* n){
 int l = 0;
 int r = 0;
 if(n == NULL){
     return 0;
         }
 l = treeHeight(n->left);
 r = treeHeight(n->right);
  if(l>r || l == r)
     return (l+1);
  else
      return (r+1);
      }
int treeSize(void){
  return numOfNodes;
}
Node* treeMin(Node* n){
	if(n==NULL)
                return NULL;
     	if(n->left)	
        	return treeMin(n->left);
 	 return n;
	}		

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
void transplant(Node* f, Node* s){
 	if(f->par == NULL){
 		s->par = NULL;
		s->left = f->left;
 		s->right = f->right;
                root = s;
                f = NULL;}
        else if(f == f->par->left)
                f->par->left = s;
        else
            	f->par->right = s;                                                                                                                                                                                                                         if(s) 
	        s->par = f->par;
                    }
void deleteNode(Node* n){
        p = NULL;
        if(n->right == NULL)
                transplant(n,n->left);
        else{
                p = treeMin(n->right);
                if(p->par != n){
                        transplant(p,p->right);
                        p->right = n->right;
                        p->right->par = p;
                        }
                transplant(n,p);
                p->left = n->left;
                p->left->par = p;
        }
}
Node* getRoot(){
  return root;
}
Node* findNode(int number){
	p = root;
          if(p == NULL)
              return NULL;
           while(p){
              if(p->value > number)
               p = p->left;
               else if(p->value < number)
                p = p->right;
                else if(p->value == number)
                     return p;
               else if(p==NULL)
               return NULL;
      		}
	return NULL;
 	}

void preorder(Node *n){
  if(n){
    cout<< n->value << " ";
    preorder(n->left);
    preorder(n->right);
  }
}

void inorder(Node *n)
{
  if(n)
    {
      inorder(n->left);
      cout<< n->value<< " ";
      inorder(n->right);
    }
}

void postorder(Node *n)
{
  if(n)
    {
      postorder(n->left);
      postorder(n->right);
      cout<< n->value<<" ";
    }
}


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
  return;
}

