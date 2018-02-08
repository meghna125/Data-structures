#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define maxsize 100

class stack
{
	int *arr;
	int top,capacity;
	public:
		stack(int); 
		void push(int);
		int pop();
		int peek();
		int size();					// Current size of stack
		bool isEmpty();
		bool isFull();
		void display();
		~stack();
		
};

stack::stack(int size)
{
	arr=new int[size];
	top=-1;
	capacity=size;
}

stack::~stack()
{
	delete []arr;
	capacity=0;
	top=-1;
}

int stack::peek()
{
	if(isEmpty())
	   return -1;
	else
		return arr[top];
}

int stack::size()
{
	return top+1;
}


bool stack::isEmpty()
{
	return(top<0);
}

void stack::push(int n)
{
	if(isFull())
	{
		cout<<"Overflow ";
	}
	else
	{
		arr[++top]=n;
		cout<<"\n\n"<<n<<" is pushed onto the stack!";
	}
}

int stack::pop()
{
	if(isEmpty())
	{
		cout<<"\nUnderflow";
		return -1;
	}
	else
	{
		int x=arr[top--];
		return x;
	}
}

bool stack::isFull()
{
	if(top==capacity-1)
		return true;
	else
		return false;
}


void stack::display()
{
	if(isEmpty())
	{
	   cout<<"\n\nStack is Empty ";
    }
    else
    {
		cout<<"\n\nStack "<<"\n";
		for(int i=top;i>=0;i--)
		{
			cout<<arr[i]<<"\n";
		}
	}
}


int main()
{
	stack s(maxsize);
	int ch;
	do
	{
		
		cout<<"\n\n----------------Menu--------------------- ";
		cout<<"\n1.Push ";
		cout<<"\n2.Pop ";
		cout<<"\n3.Check Size";
		cout<<"\n4.Return top of the stack ";
		cout<<"\n5.Print stack ";
		cout<<"\n6.Exit ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: int n;
		        	cout<<"\n\nEnter element u want to push : ";
		        	cin>>n;
		        	s.push(n);
		        	break;
		    case 2: cout<<"\n"<<s.pop()<<" is popped from the stack!";
		    		break;
		    case 3: cout<<"\n\nSize of array is : "<<s.size();
		    		break;
		    case 4: cout<<"\n\nTop of the stack : "<<s.peek();
		    		break;
		    		
		    case 5: s.display();
		    		break;
		    case 6: return 0;
		    		break;
		    
		    default: cout<<"\n\nInvalid case ";
		    			  break;
		}
		
		    			  
	}while(1);
	
    return  0;
	
}

		
