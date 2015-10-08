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


  //void insert(int node);
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
