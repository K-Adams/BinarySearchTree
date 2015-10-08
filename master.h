//Master header file
//contains all necessary functions to 
//implement the Binary Search tree cpp file
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stdio.h>

using namespace std;

void openFile(string input)
{

  if(input.empty())
    {
      cout<<"Nothing to open"<<endl;
    }
  else
    {
      ifstream file;
      file.open(input);
      cout<<"File stream opened!"<<endl;
    }
  return;
}

void closeFile(string file)
{
  if(file.is_open())  
    {
      file.close();
      cout<<"File Stream closed!"<<endl;
    }
  else
    {
      return;
    }
}

/*
void insert(int node);
void delete(int node);


void readFile(ifstream file)
{
  int node;
  string command;

  if(file.is_open())
    {
      while(!file.eof())
	{
	  (getline(file,command," "));
	}
    }
}
*/
