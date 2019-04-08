#include <iostream>
//declaring librrary
using namespace std;


//declaring the node fuction 
class node{
    public:
    int data;
	//having paraameter like data, right,left,parent
    node*left;
    node*right;
    node*parent;
node(int value)
{
//constructer that initialise the value to null
    data=value;
    left=NULL;
    right=NULL;
    parent=NULL;
}
};
class bst
 //declaring bst classs
{
    public:
    node*root;
	//declaring root node type pointer
    bst()
    {
        root=NULL;
		//initialise value of root to null. 
        
    }
    
    
//inserting the  elementes
void inserthelper(int value )
{
    insert(root,value);
	//calling insert function
}
void insert(node*current,int value)
{   
    //if root ==null,create a new node and assign to it.
    if (root==NULL) 
    {
        root=new node (value);
        //new node becomes root
    }
    //else cases 
    //if value<data of root then it goes to left side of root
    else if(value<current->data)
    {
    	//if in the left of root there is no node then create a new node 
    	//joined to it 
        if (current->left==NULL)
        {
            current->left=new node (value);
            current->left->parent=current;
        }
        else
        insert(current->left,value);//USING RECURTION
    }
     //if value<data of root then it goes to left side of root
     else 
    { 
       	//if in the left of root there is no node then create a new node
       	//joined it 
        if (current->right==NULL)
        {
            current->right=new node (value);
            current->right->parent=current;
        }
        else
        insert(current->right,value);//USING RECURTION
    }
}

//displaying the binary tree
void displayhelper()
{   
    cout<<"THE ELEMENTS IN BST ARE : ";
    display(root);//fuction calling by the function
}
void display(node*current)
{
    if(current==NULL)
    return ;//if casse of there is no elements then return
    //in order display
    display(current->left);//first display left and its data 
    cout<<current->data<<" , ";//then display its parents
    display(current->right);//theen display its right 
}
};
int main() {
    bst b1;
    b1.inserthelper(2);
    b1.inserthelper(4);
    b1.inserthelper(3);
    b1.inserthelper(1);
    b1.inserthelper(6);
    b1.inserthelper(5);
    b1.inserthelper(7);
    b1.inserthelper(9);
    b1.inserthelper(8);
    b1.displayhelper();
	return 0;
}
