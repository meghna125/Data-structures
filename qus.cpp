#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;


class queue
{
	stack<int> s1,s2;
	int cur_size;
	public:
		queue();
		int dequeue();
		void enqueue(int);
		int front();
		int size();
		//void display();
		
};

queue::queue()
{
	cur_size=0;
}

void queue::enqueue(int ele)
{
	cur_size++;
	//cout<<cur_size;
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(ele);
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
	
	
	
}

int queue::dequeue()
{
	if(s1.empty())
		return 0;
	int k=s1.top();
	s1.pop();
	cur_size--;
	return k;
	
}

/*void stack::display()
{
    int c=cur_size;
	cout<<"\nStack "<<"\n";
	while(c!=0)
	{
		cout<<q1.front()<<"\n";
		q1.pop();
		c--;
	}
}*/


int queue::front()
{
	if(s1.empty())
		return -1;
	return s1.top();
	
}

int queue::size()
{
	return cur_size;
}


int main()
{
	queue q;
	int ch,ele;
	do
	{
		cout<<"\n\n------------------MENU---------------------"
			<<"\n1.ENQUEUE "
			<<"\n2.DEQUEUE "
			//<<"\n3.DISPLAY"
			<<"\n3.FRONT OF THE QUEUE "
			<<"\n4.SIZE OF QUEUE "
			<<"\n5.EXIT "
			<<"\n\nEnter your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"\nEnter Element : ";
						cin>>ele;
						q.enqueue(ele);
						break;
				case 2:cout<<"\n"<<q.dequeue()<<" is dequeued";
						break;
				/*case 3:s.display();
						break;*/
				case 3:cout<<"\nfront of queue is : "<<q.front();
						break;
				case 4: cout<<"\nSize of queue : "<<q.size();
						break;
				case 5:exit(0);
				
			}
	}while(1);
	
	return 0;
}
