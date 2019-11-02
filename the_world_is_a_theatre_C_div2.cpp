#include<bits/stdc++.h>
 
using namespace std;
 
long long comb(int n, int k)
{
	if(n == k)
		return 1;
	return (n * comb(n - 1, k)) / (n - k);
}
 
int main()
{
 
	int n, m , t;
	cin>>n>>m>>t;
	long long res = 0;
	for(int i = 4; i <= n; i++)
	{
		if(t - i > m || t - i < 1)
			continue;
		res +=  comb(n, i)*comb(m, t - i);
	}
	cout<<res<<endl;
	return 0;
}