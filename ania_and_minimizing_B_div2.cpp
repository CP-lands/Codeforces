#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	string s;
	cin>>n>>k>>s;
	if(n == 1)
	{
		cout<<0<<endl;
		return 0;
	}
	int count = 0;
	/*
	if(s[0] - '0' > 1)
	{
		s[0] = '1';
		count++;
	}
	int i = 1;
	while(i < n && count < k)
	{
		if(s[i] - '0' > 0)
		{
			s[i] = '0';
			count++;
		}
		i++;
	}*/

	while(count < k && i < n)
	{
		if(s[i] - '0' > 1 && i == 0)
		{
			s[i] = '1';
			count++;
		}
		if(s[i] - '0' >= 1 && i >= 1)
			{
				s[i] = '0';
				count++;
			}
		i++;
	}
	cout<<s<<endl;
	return 0;
}
