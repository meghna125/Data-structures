#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int palindrome(string str)
{
	stack<char> s;
	queue<char> q;
	for(int i=0;i<str.length();i++)
	{
		s.push(str[i]);
		q.push(str[i]);
	}
	while(!s.empty())
	{
		if(s.top()!=q.front())
		{
			return 0;
		}
		else
		{
			s.pop();
			q.pop();
		}
		
	}
	return 1;
}



int main()
{
	string str;
	cout<<"\nEnter your expression : ";
	cin>>str;
	if(palindrome(str))
		cout<<"\nString is palindrome  ";
	else
		cout<<"\nString is not palindrome ";
	return 0;
}
