#include <iostream>
#include <fstream>
#include "master.h"
#include <unistd.h>

using namespace std;


//here is our main for bst.cpp
int main(int argc, char* argv[])
{
  cout<<"Attempting to open file...."<<endl;
  sleep(1);
  openFile(argv[1]);
  readFile();
  cout<<"Number of nodes in the bst: " << treeSize()<<endl;
  cout<<"Pre-Order: "<< "";
  preorder(getRoot());
  cout<<endl<<"In-Order: "<< "";
  inorder(getRoot());
  cout<<endl<<"Post-Order: "<< "";
  postorder(getRoot());
  cout<<endl<<"\nAttempting to close file...."<<endl;
  sleep(1);
  closeFile();
  
  return EXIT_SUCCESS;
}
