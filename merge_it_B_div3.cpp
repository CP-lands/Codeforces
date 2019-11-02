#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int a1 = 0;
		int count = 0;
		int tmp;
		int a2 = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>tmp;
			if(tmp % 3 == 0)
				count++;
			else if(tmp % 3 == 1)
				a1++;
			else
				a2++;
		}
		if(a1 >= a2)
		{
			count += a2;
			count += (a1 - a2) / 3;
		}
		else
		{
			count += a1;
			count += (a2 - a1) / 3;
		}
		cout<<count<<endl;
	}
	return 0;
}