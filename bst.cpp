#include <iostream>
#include <fstream>
#include "master.h"
#include <unistd.h>

using namespace std;


//main
int main(int argc, char* argv[])
{
  //pause one second
  sleep(1);
  //open the file referenced by the command line argument
  openFile(argv[1]);
  //read the given file, parse contents of the file, complete given tasks
  readFile();
  //return the total number of nodes in the tree
  cout<<"Number of nodes in the bst: " << treeSize()<<endl;
  //return the tree height using getRoot()
  cout<<"Height of the bst: "<<treeHeight(getRoot())-1<<endl;
  cout<<"Pre-Order: "<< "";
  //retrieve the preorder traversal of the tree using getRoot()
  preorder(getRoot());
  cout<<endl<<"In-Order: "<< "";
  //retrieve the inorder traversal of the tree using getRoot()
  inorder(getRoot());
  cout<<endl<<"Post-Order: "<< "";
  //retrieve the inorder traversal of the tree using getRoot()
  postorder(getRoot());
  //pause one second
  sleep(1);
  //close the file stream
  closeFile();
  
  return EXIT_SUCCESS;
}
