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

int treeSize(void){
  return numOfNodes;
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

Node* getRoot(){
  return root;
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
      inorder(n->left);
      inorder(n->right);
      cout<< n->value<<" ";
    }
}


void readFile(void)
{
  int node;
  string command;
  if(counter)
    {
      while(file>>command)
	{
	  file >> node;
	  if(command == "insert"){
	    insert(node);
	  }
	}
    }
  return;
}
