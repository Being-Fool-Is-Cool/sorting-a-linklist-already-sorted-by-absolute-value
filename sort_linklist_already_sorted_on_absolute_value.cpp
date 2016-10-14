#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node * next;
};

node * newnode(int data)
{
	node * temp=new node;
	temp->data=data;
	temp->next=NULL;
	
	return temp;
}
node *sortall(node *head)
{
	node *prev=head;
	node *curr=head->next;
	
	while(curr)
	{
		if(curr->data < prev->data)
		{
			prev->next=curr->next;
			curr->next=head;
			head=curr;
			curr=prev;
			curr=curr->next;
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
	return head;
}

int main()
{
	node * head=newnode(0);
	head->next=newnode(1);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(-2);
	head->next->next->next->next->next=newnode(5);
	head->next->next->next->next->next->next=newnode(-5);
	
	node * headf=sortall(head);
	while(headf)
	{
		cout<<headf->data<<"->";
		headf=headf->next;
	}
}
