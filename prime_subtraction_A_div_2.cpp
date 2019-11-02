#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		long long x, y;
		cin>>x>>y;
		int tmp = 0;
		long long res = x - y;
		if(res == 1)
			cout<<"NO"<<endl;
		else 
			cout<<"YES"<<endl;
 
	}
	return 0;
}