//___1 WA == 5 Push up___
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<map>

//https://codeforces.com/problemset/problem/75/C
using namespace std;

typedef long long ll; 
const int MOD = 1e9 + 7;

int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}
int main()
{
	int a,b,n,low,high;
	vector<int> factors;
	cin>>a>>b>>n;
	int tmp = get_gcd(a, b);

	for(int i = 1; i <= sqrt(tmp); i++)
	{
		if(a % i == 0 && b % i == 0)
		{
			if(i * i == tmp) factors.push_back(i);
			else
			{
				factors.push_back(i);
				factors.push_back(tmp / i);
			}
		}
	}
	sort(factors.begin(), factors.end());

	for(int i = 0; i < n; i++)
	{
		cin>>low>>high;
		int it = upper_bound(factors.begin(), factors.end(), high) - factors.begin();
		if(factors[it - 1] >= low)
			cout<<factors[it - 1]<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
