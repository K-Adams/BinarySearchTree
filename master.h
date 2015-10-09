//Master header file
//contains all necessary functions to 
//implement the Binary Search tree cpp file
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;
ifstream file;
int counter = 0;
template<typename T>
class Node {
        T value;
        Node<T> * right = nullptr;
        Node<T> * left = nullptr;
        Node<T> * parent = nullptr;
        }; // Node
template<class Node>
std::list<Node*> tree_list;
void openFile(string input)
{

  if(input.empty())
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
        int s = tree_list.size();
        return s;
}
template<typename T>
  void insert(T data){
        int i = 1;
        Node<T> * n = new Node<T>;
        n->value = data;
        Node<T> * temp = new Node<T>;
        if(tree_list.empty())
                tree_list.push_front(n);
        else {
                temp = tree_list.front();
                while(i){
                        if((n->value)>(temp->value)&&temp->right!=NULL)
                                temp=temp->right;
                        else if((n->value)>(temp->value)&&temp->right==NULL){
                                n = temp->right;
                                n->parent = temp;
                                i = 0;
                                tree_list.push(n);
                                }
                        else if((n->value)<(temp->value)&&temp->left!=NULL)
                                temp=temp->left;
                        else if((n->value)<(temp->value)&&temp->left==NULL){
                                n = temp->left;
                                n->parent = temp;
                                i = 0;
                                tree_list.push(n);}
                        else if(n->value ==temp->value)
                                i = 0;
                        }
        }
}
void preorder(Node *n){
        if(n){
        cout<< n->value << " ";
        preorder(n->left);
        preorder(n->right);
        }
        }
  //void delete(int node);
  void readFile(void)
  {
    int node;
      string command;
        if(counter)
           {
                while(file>>command)
                        {
              //          getline(file, command);
                        //file >> command;
                        file >> node;
                        cout<< "command: " <<command<< "|| node: " <<node<<endl;
                        if(command == "insert"){
                //              insert(node);
                        cout<<"YAY"<<endl;
                        }
            }
}
return;
}
                 
