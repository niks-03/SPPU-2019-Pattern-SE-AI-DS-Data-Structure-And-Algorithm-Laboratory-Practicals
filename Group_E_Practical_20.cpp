#include <iostream>
#include <string>
using namespace std;

class queue{
	public:
	string name;
	int pr, front, rear, size;
	int *P;
	string *Q;
	
	queue(){
		cout<<"enter size: ";
		cin>>size;
		Q=new string[size];
		P=new int[size];
		front=rear=-1;
	}
	
	void insert(){
		cout<<"enter patient name: ";
		cin>>name;
		cout<<"enter priority(1:serious, 2:non serious, 3:checkup): ";
		cin>>pr;
		
		if (front==-1 && rear==-1){
			front++;
			rear++;
			Q[rear]=name;
			P[rear]=pr;
		}
		
		else if (rear!=size-1 && front==0){
			if (pr==1){
				
				for (int i=rear; i>=0; i--){
					Q[i+1]=Q[i];
					P[i+1]=P[i];
				}
				Q[0]=name;
				P[0]=pr;
				rear++;
			}
			
			else if (pr==2){
				int ptr;
				
				if (P[rear]!=3){
					rear++;
					P[rear]=pr;
					Q[rear]=name;
				}
				
				else {
					
				for (int i=0; i<=rear; i++){
					if (P[i]==3){
						ptr=i;
						break;
					}
					
				}
				
				for (int j=rear; j>=ptr; j--){
					Q[j+1]=Q[j];
					P[j+1]=P[j];
				}
				Q[ptr]=name;
				P[ptr]=pr;
				rear++;
				}
				
			}
			
			
			else if (pr==3){
				rear++;
				Q[rear]=name;
				P[rear]=pr;	
				
			}
		}
	}
	
	void Delete(){
		int ptr=-1;
		cout<<"enter patient name: ";
		cin>>name;
		
		for (int i=0; i<=rear; i++){
			if (Q[i]==name){
				ptr=i;
				break;
			}
		}
		
		
		if (ptr==-1){
			cout<<"patient not found"<<endl;
		}
		else{
			cout<<"patient deleted:: "<<Q[ptr]<<endl;
			for (int i=ptr; i<rear; i++ ){
				P[i]=P[i+1];
				Q[i]=Q[i+1];
				
			}
			rear--;
		}
	}
	
	void vacant(){
		int count=0;
		for (int i=rear+1; i<size; i++){
			count++;
		}
		
		cout<<"vacant seats: "<<count<<endl;
	}
	
	void display(){
		for (int i=front; i<=rear; i++){
			cout<<Q[i]<<": ";
			switch(P[i]){
				case 1:
					cout<<"Serious"<<endl;
					break;
				case 2:
					cout<<"non serious"<<endl;
					break;
				case 3:
					cout<<"checkup"<<endl;
					break;
			}
			
		}
	}
	
};

int main(){
	queue obj;
	char ch;
	int choice;
	do{
		cout<<"\n1.insert\n2.display\n3.vacant seats\n4.delete\n";
		cin>>choice;
		
		if (choice==1){
			obj.insert();
			cout<<"==================================="<<endl;
			
		}
		else if(choice==2){
			obj.display();
			cout<<"==================================="<<endl;
		}
		else if (choice==3){
			obj.vacant();
			cout<<"==================================="<<endl;
		}
		else if (choice==4){
			obj.Delete();
			cout<<"==================================="<<endl;
		}
		
		cout<<"want to continue: ";
		cin>>ch;
	}while(ch=='y');


	return 0;
}
