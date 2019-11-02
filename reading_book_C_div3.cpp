#include<iostream>

using namespace std;

long long solution(long long n, long long m)
{
	if(m > n || m == 0)
		return 0;
	long long sum = 0;
	long long min_sum = 0;
	for(long long i = m; i <= 10 * m; i = i + m)
		min_sum = min_sum + i % 10;
	sum =(n/(10 * m)) * min_sum;
	for(long long i = 0; i <= n % (10 * m); i = i + m)
		sum = sum + i % 10;
	return sum;
}
int main()
{
	long long n,m;
	int q;
	cin>>q;
	for(long long i = 0; i < q; i++)
	{
		cin>>n>>m;
		cout<<solution(n,m)<<endl;
	}
	return 0;
}