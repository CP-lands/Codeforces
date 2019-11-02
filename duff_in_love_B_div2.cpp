#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long n, res = 1;
	cin>>n;
	for(long long i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			res *= i;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1)
		res *= n;
	cout<<res<<endl;
	return 0;
}