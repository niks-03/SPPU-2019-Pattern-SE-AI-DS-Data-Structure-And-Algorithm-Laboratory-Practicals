#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
  node *left;
  node *right;
};

class BT{
  public:
  node *head;

BT(){
  head=NULL;
  }
void create(){
  node *temp;
  char ch;

  do{
    temp=new node;
    cout<<"enter data:";
cin>>temp->data;
temp->left=NULL;
temp->right=NULL;

if (head)
  } 
}
}
