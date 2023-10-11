#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *right;
		Node *left;
};

class BT{
	
	public:
	Node *root;
	BT(){
		root=NULL;
	}
	
	void create();
	void insert(Node* ,Node*);
    void inorder(Node *);
	void preorder(Node *root);
    void postorder(Node *);
    void search(Node *, int);
    void minimum(Node *);
    void maximum(Node *);
    void destroy();
    void mirror(Node *);
    
};



void BT :: create(){
	Node *temp;
	char choice;
	do{
		temp= new Node;
		cout<<"enter data: ";
		cin>>temp->data;
		
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

void BT:: insert(Node *root,Node *temp){
	
	if (temp->data < root->data){
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

void BT :: search(Node *temp, int key){  
        if (key == temp->data){
            cout<<"key found \n";
            
        }
        else if (key < temp->data){
            search(temp->left, key);
        }
        else if (key > temp->data){
            search(temp->right, key);
        }
        else{
            cout<<"not found\n";
            
        }
    }

void BT :: minimum(Node *temp){
    if (temp->left != NULL){
        minimum(temp->left);
    }
    else if(temp->left == NULL){
        cout<<"minimum value: ";
        cout<<temp->data;
    }
}

void BT :: maximum(Node *temp){
    if (temp->right !=NULL){
        maximum(temp->right);
    }
    else if (temp->right == NULL){
        cout<<"maximum value: ";
        cout<<temp->data;
    }
}
void BT::inorder(Node *temp){
    if(temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<"->";
        inorder(temp->right);
    }
    
}

void BT :: preorder(Node *temp){
	if (temp!=NULL){
		cout<<temp->data<<"->";
		preorder(temp->left);
		preorder(temp->right);
	}
    
}

void BT :: postorder(Node *temp){
    if (temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<"->";
    }
   
}

void BT :: destroy(){
    root=NULL;
    cout<<"Tree destroyed";
}

void BT::mirror(Node *root)
{
    if(root == NULL)
        return;
    else
    {
        Node *temp;
        temp = new Node;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main(){
	BT bt;
	int choice;
	char ch;
	do{
		cout<<"1.create\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.minimum\n7.maximum\n8.destroy\n9.mirror\n";
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
                bt.inorder(bt.root);
                }
                break;
			case 3:
				if (bt.root == NULL){
                     cout<<"tree cannot be displayed as it is not created";
                }
                else{
                bt.preorder(bt.root);
                }
                break;
            case 4:
               if (bt.root == NULL){
                     cout<<"tree cannot be displayed as it is not created";
                }
                else{
                bt.postorder(bt.root);
                }
                break;
            case 5:
                int key;
                cout<<"enter key: ";
                cin>>key;
                bt.search(bt.root ,key);
                break;
            case 6:
                bt.minimum(bt.root);
                break;
            case 7:
                bt.maximum(bt.root);
                break;
            case 8:
                bt.destroy();
                break;
            case 9:
                bt.mirror(bt.root);
                break;
		}
		cout<<"\ndo u want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
	
	return 0;
}

