#include<iostream>
#include<map>
using namespace std;
#define size 3

void input_func(int adj[][size], map<int,string>mapping){
  for(int i=0;i<size;i++){
    for(int j=i;j<size;j++){

      if(i==j){
        adj[i][j]=0;
      }
      else{
      cout<<"enter the distance between for " <<mapping[i]<<" and "<<mapping[j]<<" : ";
      int d;
      cin>>d;
      adj[i][j]=d;
      adj[j][i]=d;
      }
    }
  }
}

void print(int adj[][size],map<int,string>mapping){
  for(int i=0;i<size;i++){
    cout<<mapping[i]<<' ';
    for(int j=0;j<size;j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main(){
string s;

  map<int,string>mapping;
  for (int i=0;i<size;i++){
  	cout<<"Enter city name = ";
  	cin>>s;
  	mapping[i]=s;

  }
  int adj [size][size];

  input_func(adj,mapping);

  print(adj,mapping);
  
}
