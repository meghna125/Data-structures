#include<iostream>
#include<cstdlib>
#define SIZE 50
using namespace std;

class queue 
{	
	/*   			
    objective: Create a class to implement Queue(circular) using dynamically created array 
	input parameters: none
	output value: none
	description:  Class definition
	approach: Class definition provides data member and member functions for the Queue class
	*/


	int *arr;			// array to store queue elements
	int capacity;			// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q

	public:
		queue(int size = SIZE);			// constructor
		~queue();	
		void dequeue();
		void enqueue(int);
		int peek();  				// returns front element
		int size();				// returns current size of Q
		bool isEmpty();
		int input();
		void display();
		bool isFull();
};

int queue::input()
{
	int ele;
	cout<<"\nEnter element : ";
	cin>>ele;
	return ele;
}



queue::queue(int size)
{
	arr=new int[size];
	front=-1;
	rear=-1;
	capacity=size;
	count=0;
}

queue::~queue()
{
	delete []arr;
	capacity=0;
	front=rear=-1;
	count=0;
}

/*bool queue::isFull()
{
	if(front==(rear%count)+1)
		return true;
	else
		return false;
}*/

bool queue::isEmpty()
{
	if(front==-1 && rear==-1)
		return true;
	else
		return false;
}

void queue::enqueue(int val)
{
	
	if(isFull())
		cout<<"\nQueue is Full ";
	else
	{
		
		if(front==-1 && rear==-1)
		{
			front=0;rear=0;
			arr[front]=val;
			count++;
			
		}
		else
		{
			rear=(rear%count)+1;
			arr[rear]=val;
			count++;
		}
		
		
	}
	
}

void queue::dequeue()
{
	if(isEmpty())
		cout<<"\nQueue is Empty ";
	else
	{
		if(front==rear)
		{
			cout<<"\nelement deleted is : "<<arr[front];
			front=rear=-1;
		}
		else
		{
			cout<<"\nelement deleted is : "<<arr[front];
			front=(front%count)+1;
		}
		count--;
	}
}

void queue :: display()
{
 //cout<<endl;
 if(front!=-1 && rear!=-1)
 {
        int i=front;
        cout<<"arr["<<i<<"] :"<<arr[i]<<endl;
        while(i!=rear)
        {
         i=(i % count)+1;
         cout<<"arr["<<i<<"] :"<<arr[i]<<endl;
        }

 }
 else
 {
    cout<<"Queue is empty"<<endl;
 }
 //getch();
}
 

int queue::peek()
{
	if(isEmpty())
		return -1;
	else
		return arr[front];
}

int queue::size()
{
	return count;
}


int main()
{
	queue q(SIZE);
	int ch;
	do
	{
		
		
		cout<<"\n\n----------------Menu--------------------- "
			<<"\n1.Enqueue "
			<<"\n2.Dequeue "
			<<"\n3.Check Size"
			<<"\n4.Return top of queue "
			<<"\n5.Print queue "
			<<"\n6.Exit "
			<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
		        	q.enqueue(q.input());
		        	break;
		    case 2: q.dequeue();
		    		break;
		    case 3: cout<<"\n\nSize of array is : "<<q.size();
		    		break;
		    case 4: cout<<"\nTop of queue is : "<<q.peek();
		    		break;
		    case 5: q.display();
		    		break;
		    case 6: exit(0);
		    
		    default: cout<<"\n\nInvalid case ";
		    			  break;
		}
		
		    			  
	}while(1);
	
    return  0;
	
}




