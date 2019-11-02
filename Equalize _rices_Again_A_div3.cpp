#include<bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		int n;
		cin>>n;
		int sum = 0;
		int tmp;
		for(int j = 0; j < n; j++)
		{
			cin>>tmp;
			sum += tmp;
		}
		if(sum % n == 0)
			cout<<sum/n<<endl;
		else
			cout<<sum/n + 1<<endl;
	}
	return 0;
}