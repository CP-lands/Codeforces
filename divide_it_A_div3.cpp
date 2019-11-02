#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int q;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		long long n;
		cin>>n;
		int count = 0;
		while(n > 1)
		{
			if(n % 2 == 0)
			{
				n /= 2;
				count++;
			}
			else if(n % 3 == 0)
			{
				n = n - n / 3;
				count++;
			}
			else if(n % 5 == 0)
			{
				n = n - n / 5;
				count++;
			}
			else
				break;
		}
		if(n == 1)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}