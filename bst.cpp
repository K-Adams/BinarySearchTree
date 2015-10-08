#include <iostream>
#include <fstream>
#include "master.h"
#include <unistd.h>

using namespace std;


//here is our main for bst.cpp
int main(int argc, char* argv[])
{
  cout<<"Attempting to open file...."<<endl;
  sleep(1000);
  openFile(argv[1]);

  cout<<"Attempting to close file...."<<endl;
  sleep(1000);
  closeFile(argv[1]);

  return EXIT_SUCCESS;  
}
