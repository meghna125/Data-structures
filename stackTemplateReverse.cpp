#include<iostream>
#include<stack>
#include<conio.h>
using namespace std;


stack<int> s;

void input()
{
	int n;
	cout<<"\nEnter your number ";
	cin>>n;
	s.push(n);
	
}

void reverse()
{
	
	while(!s.empty())
	{
		cout<<"\n"<<s.top();
		s.pop();
	}
}


int main()
{
	cout<<"\n\tProgram to reverse a number ";
	int n;
	cout<<"\n\nHow many digits number you want to reverse ";
	cin>>n;
	while(n!=0)
	{
		input();
		n--;
	}
	reverse();
	return 0;
}
