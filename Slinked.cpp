#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;


class SNode { 
	/*   			
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure 
	approach: Class defines data item is names element with datatype string 
			and link is named next pf snode type
	*/
	private:
	  string elem; 
	  SNode* next; 
	friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/
	private:
		SNode* head; 						// pointer to the head of list
	public:
		SLinkedList();							// empty list constructor
		~SLinkedList();							// destructor
		bool empty() const; 					// is list empty?
		const string& front() const; 			// get front element
		void addFront(const string& e); 		// add to front of list
		void addBack(const string& e); 			// add to back of list
		void removeFront();			 			// remove from front 
		void removeEnd();						// remove from end
		void print(); 							// prints the SLL
								
};

SLinkedList::SLinkedList()
{
	head='\0';
}

SLinkedList::~SLinkedList()
{
	head='\0';
}

bool SLinkedList::empty() const
{
	if(head=='\0')
		cout<<"\n\tList is Empty!!";
}

const string& SLinkedList::front() const
{
	string d;
	if(head=='\0')
		cout<<"\n\tList is Empty!!";
	else
	{
		
		d=head->elem;
		return d;
	}
	
	
}

void SLinkedList::addFront(const string& e)
{
	SNode *temp;
	temp=new SNode;
	temp->elem=e;
	if(head=='\0')
	{
		temp->next='\0';
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	
}

void SLinkedList::addBack(const string& e)
{
	SNode *temp;
	temp=new SNode;
	temp->elem=e;
	temp->next='\0';
	SNode *t=head;
	while(t->next!='\0')
	{
		t=t->next;
	}
	t->next=temp;
}

void SLinkedList::removeFront()
{
	if(head=='\0')
		cout<<"\nList is Empty!!";
	else
	{
		SNode*t=head;
		head=t->next;
		delete t;
		 print();
	}
		
}

void SLinkedList::removeEnd()
{
	if(head=='\0')
		cout<<"\nList is Empty!!";
	else
	{
		SNode *t=head;
		SNode *p=t->next;
		while(p->next!='\0')
		{
			t=t->next;
			p=p->next;
		}
		t->next='\0';
		delete p;
		 print();
	}
	
}

void SLinkedList::print()
{
	SNode *t=head;
	if(t=='\0')
		cout<<"\nList is Empty!!";
	else
	{
		cout<<"\n\t-----------------------------------------------------------------";
		cout<<"\n\tLinked list : ";
		
		while(t->next!='\0')
		{
			cout<<t->elem<<" -> ";
			t=t->next;
		}
		cout<<t->elem;
		cout<<"\n\t-----------------------------------------------------------------";
	}
}


int main()
{
	SLinkedList l;
	int ch;
	string str;
	do
	{
		//system("cls");
		cout<<"\n\n------------------------MENU--------------------------------------------------------------------------------------"
		<<"\n\n\t1.Insertion at beginning "
		<<"\n\t2.Insertion at end "
		<<"\n\t3.Deletion at beginning "
		<<"\n\t4.Deletion at end "
		<<"\n\t5.Return Front of list "
		<<"\n\t6.Display list "
		<<"\n\t7.Exit "
		<<"\n\n\tEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"\n\tEnter data :  ";
					cin>>str;
			        l.addFront(str);
			        l.print();
					break;
			case 2: cout<<"\n\tEnter data : ";
					cin>>str;
			        l.addBack(str);
			         l.print();
					break;
			
			case 3: l.removeFront();
					
			
					break;
			case 4: l.removeEnd();
					
					break;
			case 5: 
					cout<<"\n\tFront of Linked List : "<<l.front();
					break;
			case 6:
				   l.print();
				   //sleep(1000);
			       break;
			case 7:exit(0);
		}
		//Sleep(1000);
		
		
	}while(1);
	return 0;
	
}
