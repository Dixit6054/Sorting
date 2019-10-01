//this is only the merge part implementation(last step in merge sort)
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

void insert(int data , node** head , node** last, int key)
{
	if(key==1)
	{
		node* temp = new node;
		(*temp).data = data;
		node* c;
		c = *head;
		*head = temp;
		temp->link = c;
		if(*last == NULL)
		*last = temp;
		
	}
	else
	{
		node* temp = new node;
		temp->data = data;
		temp->link= NULL;
		
		if(*last == NULL)
		*last = temp;//(*last)->link = temp;
		else
		{
			(*last)->link = temp;
			*last = temp;	
		}
		
		if(*head==NULL)
		*head=temp;
	}
}
void print (node* head)
{
	while(head != NULL)
	{
		cout << head->data <<" ";
		head = head->link;
	}
	cout<<endl;
}
/*i am combining second list into first*/
void merge(node** head, node* p1, node* c1, node* c2, node* n2)	// past1 current1  and for other linked list	 current and next 
{
if(c1!=NULL && n2!=NULL)		//the order of ther if elseif elseif matters a lot
{	
	if(c1->data <= c2->data)//simply iterate
	{
		p1=c1;
		c1 = c1->link;
	}
	else
	{
		if(p1==NULL)
		{
			node* temp = new node;
			temp->data = c2->data;
			temp->link = c1;
			*head = temp;
			p1=temp;
			delete c2;
			c2 = n2;
			n2 = n2->link;
			
		}
		else
		{
			node* temp = new node;
			temp->data = c2->data;
			temp->link = p1->link;
			p1->link = temp;
			p1 = temp;
			delete c2;
			c2 = n2;
			n2 = n2->link;
			
		}
		
	}
}
	else if(c1 !=NULL)
	{
		if(c1->data <= c2->data)//simply iterate
		{
		p1=c1;
		c1 = c1->link;
		}
		else
		{
			node* temp = new node;
			temp->data = c2->data;
			temp->link = p1->link;
			p1->link = temp;
			p1 = temp;
			delete c2;
			c2 = n2;
		}
		return;
	
	}
	else if (n2 != NULL)
	{
		p1->link = c2;
		return;
	}
	merge(head,p1,c1,c2,n2);
	
}
main()
{
	node* head1 = NULL;
	node* last1 = NULL;
	insert(2,&head1,&last1,0);
	insert(4,&head1,&last1,0);
	insert(5,&head1,&last1,0);
	insert(7,&head1,&last1,0);
	insert(12,&head1,&last1,0);
	insert(21,&head1,&last1,0);//2 4 5 7 12 21
	print(head1);


	node* head2 = NULL;
	node* last2 = NULL;
	insert(1,&head2,&last2,0);
	insert(3,&head2,&last2,0);
	insert(5,&head2,&last2,0);
	insert(7,&head2,&last2,0);
	insert(10,&head2,&last2,0);
	insert(11,&head2,&last2,0);//1 3 7 5 10 11
	print(head2);
	merge(&head1,NULL,head1,head2,head2->link);
	print(head1);
}
