#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
using namespace std;

stack<char> s;

int prec(char a)
{
	if(a == '/' || a == '*')
        return 2; 
	else if(a == '+' || a == '-')
	return 1;
	else
	return -1; 

}




void Postfix(string arr)
{
	char store[50];
	int j=0;
	char x;
	int len = arr.length();
	for(int i=0;i<len;i++)
	{
		if(arr[i]=='(')
			s.push(arr[i]);
		
		else if(arr[i]==')')
		{
			while(!s.empty() && s.top()!='(')
			{
				char x=s.top();
				s.pop();
				store[j++]=x;
			}
			s.pop();
		}
		else if((arr[i]>='a' && arr[i]<='z')||(arr[i]>='A' && arr[i]<='Z'))
			store[j++]=arr[i];
		else
		{
			while(!s.empty() && s.top()!='(' && prec(arr[i])<=prec(s.top()))
			{
				char x=s.top();
				s.pop();
				store[j++]=x;
			}
			s.push(arr[i]);
		}
		
	 }
	 while(!s.empty())
	 {
		char x=s.top();
		s.pop();
		store[j++]=x;
	}
         cout<<"\n\nPostfix expression ";
	 for(int i=0;i<j;i++)
		cout<<store[i]<<" ";
	 cout<<"\n";
		
				

}



int main()
{
	string arr;
	cout<<"\n\nEnter your expression ";
	cin>>arr;
	Postfix(arr);
 
	return 0;

}



