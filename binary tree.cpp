#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
class tree
{
node *root;
public:
	tree()
	{	root=NULL;	}
	void create();
	void pre(node *);
	
	node *return_root()
	{
		return root;
	}
};

void tree::create()
{
node *temp,*newnode;
char side,op;
do
{
   newnode=new node;
   cout<<"\n  Enter data=>";
   cin>>newnode->data;
   newnode->left=newnode->right=NULL;

if(root==NULL)  //For Root only or First Node 
	root=newnode;
else
{
temp=root;
while(1)
{
cout<<"\n  To the side L/R=>";
cin>>side;
   if(side=='l')
   {
	if(temp->left==NULL)
	{
	   temp->left=newnode;// attach to left side 
	   break;
	}
	else
	   temp=temp->left; //move to left side 
   }//end of outer if 
   else
   {
	if(side=='r')
	{
	   if(temp->right==NULL)
	   {
	     temp->right=newnode; // attach to right side
	     break;
	   }
	   else
	     temp=temp->right; //move to right side 
	}//end of outer if 
   }//end of outer else 
}//end of while
}//end of outermost else
cout<<"\n  Do u want to continue=>";
cin>>op;
}while(op=='y');
}

void tree::pre(node *temp)
{
if(temp!=NULL)
{
	cout<<"\t  "<<temp->data;
	pre(temp->left);
	pre(temp->right);
}
}

int main()
{
tree ob;
node *root1=NULL;
ob.create();
cout<<"\n In order\n";
ob.pre(ob.return_root());
return 0;
}
