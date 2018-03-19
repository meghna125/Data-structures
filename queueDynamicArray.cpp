#include<iostream>
#include<conio.h>
#include<cstdlib>
using  namespace std;

#define msize 30

template<class T>

class queue
{
	T *arr;
	T front,rear,capacity;
	public:
		queue(T);
		T size();
		void enqueue(T);
		T dequeue();
		bool isEmpty();
		bool isFull();
		void display();
		~queue();
};

template<class T>
T queue<T>::size()
{
	int c=0;
	for(int i=front;i<=rear;i++)
		c++;
	return c;
}

template<class T>
queue<T>::queue(T size)
{
	arr=new T[size];
	rear=-1;
	front=-1;
	capacity=size;
}


template<class T>
queue<T>::~queue()
{
	delete []arr;
	rear=-1;
	front=-1;
	capacity=0;
}


template<class T>
void queue<T>::enqueue(T ele)
{
	if(isFull())
		cout<<"\nOverflow ";
	else
	{ 
		if(isEmpty())
		{
			front++;
			rear++;
			arr[rear]=ele;
		}
		else
			arr[++rear]=ele;
	}
}


template<class T>
T queue<T>::dequeue()
{
	int x;
	if(isEmpty())
		return -1;
	else
	{
		if(front==rear)
		{
			x=arr[front];
			front=-1;
			rear=-1;
		}
		else
		{
			x=arr[front++];
	    }
		return x;
	}
}


template<class T>
bool queue<T>::isEmpty()
{
	if(front==-1 && rear==-1)
		return true;
	else
		return false;
		
}


template<class T>
bool queue<T>::isFull()
{
	if(rear==capacity-1)
		return true;
	else
		return false;
}

template<class T>
void queue<T>::display()
{
	if(isEmpty())
		cout<<"\n\nQueue is Empty ";
	else
	{
		cout<<"\n\nQueue : ";
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<" ";
    }
}

int main()
{
	queue<int> q(msize);
	int ch;
	do
	{
		
		cout<<"\n\n----------------Menu--------------------- ";
		cout<<"\n1.Enqueue ";
		cout<<"\n2.Dequeue ";
		cout<<"\n3.Check Size";
		cout<<"\n4.Print queue ";
		cout<<"\n5.Exit ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: int n;
		        	cout<<"\n\nEnter element : ";
		        	cin>>n;
		        	q.enqueue(n);
		        	break;
		    case 2: cout<<"\n"<<q.dequeue()<<" is removed ";
		    		break;
		    case 3: cout<<"\n\nSize of array is : "<<q.size();
		    		break;
		    		
		    case 4: q.display();
		    		break;
		    case 5: return 0;
		    		break;
		    
		    default: cout<<"\n\nInvalid case ";
		    			  break;
		}
		
		    			  
	}while(1);
	
    return  0;
	
}



