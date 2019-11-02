#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int q;
	cin>>q;
	int n;
	int tmp1, tmp2;
	for(int i = 0; i < q; i++)
	{
		cin>>n;
		if(n == 2)
			cout<<2<<endl;
		else
		{
			tmp1 = n / 2;
			tmp2 = n - n / 2;
			if(tmp1 == tmp2)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
	}
	return 0;
}