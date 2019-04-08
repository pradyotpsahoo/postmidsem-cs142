#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	node*prev;
	node(){
		next = NULL;
		prev = NULL;	
	}
};

class ll{
	public:
	node* head;
	node* tail;
	ll(){
		head = NULL;
		tail = NULL;
	}
	void insert(int value){
		node * temp =new node;
		temp->data=value;
		if(head==NULL){
			head=temp;
			tail=temp;
		}
		
		else{
			tail->next=temp;
			tail=temp;
		}
	}
	void display(){
		node* current=head;
		while(current!=NULL){
			cout<<current->data<<"--";
			current=current->next;	
		}
		cout<<endl;
	}
	void insertat(int pos,int value){
		node*temp=new node;
		node* current=head;
		temp->data=value;
		int i=1;
		if(pos!=1){
			while(i<pos-1){
				i++;
				current=current->next;
			}
			temp->next=current->next;
			current->next=temp;
		}
		else{
			temp->next=head;
			head=temp;
		}
	}
	void del(){
		node *current=head;
		node* temp=tail;
		while(current->next!=tail){
			current=current->next;
		}
		current->next=NULL;
		tail=current;
		delete temp;
	}
	void deleteat(int pos){
		node*current=head;
		int i=1;
		if(pos!=1){
		while(i<pos-1){
			i++;
			current=current->next;
		}
		node*current2;
		current2=current->next;
		current->next=current2->next;
		delete current2;
	}
	else{
		  head=current->next;
		delete current;
	}
	}
};
int main(){
	ll l1;
	for(int i=1;i<11;i++){
		l1.insert(i);
	}
	l1.display();
	l1.del();
	l1.display();
	l1.insertat(7,76);
	l1.display();
	l1.del();
	l1.display();
	l1.deleteat(1);
	l1.display();
	l1.insertat(1,88);
	l1.display();
	return 0;
}
