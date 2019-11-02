#include<iostream>

using namespace std;

int solution(int x, int d, int h, int max)
{
	if(d < x && d <= h)
		return -1;
	if(d >= x)
		return 1;
	else
	{
		if((x - max) % (d - h) == 0)
			return (x - max)/(d - h) + 1;
		else
			return (x - max)/(d - h) + 2;
	}
}

int main()
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
}