#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int a[n];
		int count = 0;
		for(int j = 0; j < n; j++)
			cin>>a[j];
		int temp = a[n - 1];
		for(int k = n - 2; k > 0; k--)
		{
			if(a[k] > temp)
			{
				if(a[temp] > a[k])
					temp = k;
				count++;
			}
		}
		cout<<count<<endl;
	}
}

/*int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n, x;
		int count = INT_MAX;
		cin>>n>>x;
		int a[2*n];
		int max = 0;
		for(int i = 0; i < 2*n; i = i + 2)
		{
			cin>>a[i]>>a[i+1];
			if(a[i] > max)
				max = a[i];
		}
		for(int i = 0; i < 2*n; i = i + 2)
		{
			int temp = solution(x, a[i], a[i + 1], max);
			if(temp < count && temp > 0)
				count = temp;
		}
		if(count == INT_MAX)
			cout<<-1<<endl;
		else
			cout<<count<<endl;
	}
	return 0;
}*/