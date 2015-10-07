//Master header file
//contains all necessary functions to 
//implement the Binary Search tree cpp file
#include <iostream>
#include <fstream>
using namespace std;

void openFile(void)
{
  if(argv[1] == NULL)
    {
      cout<<"Nothing to open"<<endl;
    }
  else
    {
      ofstream file (argv[1]);
    }
  return;
}

void closeFile(ofstream file)
{
  if(file.is_open())
    {
      file.close();
    }
  else
    {
      return;
    }
}

void insert(int node);
void delete(int node);

void readFile()
{

}
