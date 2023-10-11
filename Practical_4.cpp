#include <iostream>
#include <string>
using namespace std;

class node{
	public:
		string word, meaning;
		node *right;
		node *left;
};

class BT{
	
	public:
	node *root;
	BT(){
		root=NULL;
	}
	
	void create();
	void insert(node* ,node*);
    void asc_order(node *);
	void desc_order(node *root);
    void update(node*, string);
    void delete_word(node*, string);
    
};

void BT :: create(){
	node *temp;
	char choice;
	do{
		temp= new node;
		cout<<"\nenter word: ";
		cin>>temp->word;
		cout<<"\nenter meaning: ";
		cin.ignore();
		getline(cin, temp->meaning);
		
		temp->right=NULL;
		temp->left=NULL;
		
		if (root == NULL){
			root=temp;
			cout<<"\nadded to root\n";
		}
		
		else{
			insert(root, temp);
		}
		cout<<"\nwant to add more data(y/n): ";
		cin>>choice;
	}while(choice=='y');
}

void BT:: insert(node *root,node *temp){
	
	if (temp->word < root->word){
		if (root->left==NULL){
			root->left=temp;
		}
		else{
			insert(root->left, temp);
		}
		
	}
	else{
		if (root->right==NULL){
			root->right=temp;
		}
		else{
			insert(root->right, temp);
		}	
	}
}

void BT::asc_order(node *temp){
    if(temp != NULL)
    {
        asc_order(temp->left);
       cout<<temp->word<<": "<<temp->meaning<<" ->";
        asc_order(temp->right);
    }
}


void BT :: desc_order(node *temp){
	if (temp!=NULL){
		desc_order(temp->right);
       cout<<temp->word<<": "<<temp->meaning<<" ->";
        desc_order(temp->left);
	}
}

void BT :: update(node *temp, string key){
	if(temp!=NULL){
		if (temp->word == key){
			cout<<"enter new meaning: ";
			cin.ignore();
			getline(cin, temp->meaning);
			
			cout<<"meaning is updated ";
		}
		update(temp->right, key);
		update(temp->left, key);
	}
}

void BT :: delete_word(node *temp, string key){
	if(temp!=NULL){
		if (temp->word == key){
			temp==NULL;
		}
		delete_word(temp->right, key);
		delete_word(temp->left, key);
	}
}


int main(){
	BT bt;
	int choice;
	char ch;
	do{
		cout<<"1.create\n2.ascending order\n3.descending order\n4.update\n5.delete word\n";
        cout<<"choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				bt.create();
				break;
           case 2:
                if (bt.root == NULL){
                     cout<<"tree cannot be displayed as it is not created";
                }
                else{
                bt.asc_order(bt.root);
                }
                break;
			case 3:
				if (bt.root == NULL){
                     cout<<"tree cannot be displayed as it is not created";
                }
                else{
                bt.desc_order(bt.root);
                }
                break;
            case 4:{
                string key;
                cout<<"enter word to be updated: ";
				cin>>key;
            	bt.update(bt.root, key);
            	break;}
            case 5:
            	string key;
            	cout<<"enter word to be deleted: ";
            	cin>>key;
            	bt.delete_word(bt.root, key);
            	break;
    
		}
		cout<<"\ndo u want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
	
	return 0;
}
