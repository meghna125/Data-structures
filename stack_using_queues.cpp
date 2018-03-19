#include<iostream>
#include<queue>
using namespace std;


class stack
{
	queue<int> q1,q2;
	int cur_size;
	public:
		stack();
		int pop();
		void push(int);
		int top();
		int size();
		//void display();
		
};

stack::stack()
{
	cur_size=0;
}

void stack::push(int ele)
{
	
	cur_size++;
	//cout<<cur_size;
	
	q2.push(ele);
	while(!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
	}
	
	queue<int> q=q1;
	q1=q2;
	q2=q;
	
}

int stack::pop()
{
	if(q1.empty())
		return 0;
	int k=q1.front();
	q1.pop();
	cur_size--;
	return k;
	
}



int stack::top()
{
	if(q1.empty())
		return -1;
	return q1.front();
	
}

int stack::size()
{
	return cur_size;
}


int main()
{
	stack s;
	int ch,ele;
	do
	{
		cout<<"\n\n------------------MENU---------------------"
			<<"\n1.PUSH "
			<<"\n2.POP "
			//<<"\n3.DISPLAY"
			<<"\n3.TOP OF THE STACK "
			<<"\n4.SIZE OF STACK "
			<<"\n5.EXIT "
			<<"\n\nEnter your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"\nEnter Element : ";
						cin>>ele;
						s.push(ele);
						break;
				case 2:cout<<"\n"<<s.pop()<<" is popped ";
						break;
				//case 3:s.display();
				//		break;
				case 3:cout<<"\nTop of stack is : "<<s.top();
						break;
				case 4: cout<<"\nSize of stack : "<<s.size();
						break;
				case 5:exit(0);
				
			}
	}while(1);
	
	return 0;
}
