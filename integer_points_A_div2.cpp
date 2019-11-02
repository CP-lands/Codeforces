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
#include<iomanip>
#include<bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll; 
 
const int MOD = 1e9 + 7;
 
ll fact(int n)
{
	if(n == 0 || n == 1) return 1;
	ll res = 1;
	for(int i = 2; i <= n; i++)
		res *= i;
	return res;
}
ll comb(int n, int k)
{
	if(n == k) return 1;
	return ((n * comb(n - 1, k)) / (n - k)) % 1000000007;
}
bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i < n; i++)
		if(n % i == 0) return false;
	return true;
}
ll power(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a;
	ll tmp = power(a, k >> 1);
	tmp = (tmp * tmp) % MOD;
	return k % 2 ? (tmp * a) % MOD : tmp;
}
ll pow(int a, int n)
{
	if(n == 0) return 1;
	if(n == 1) return a;
	ll res = pow(a, n / 2);
	if(n % 2 == 0) res * res;
	else return res * res * a;
}
string int_to_string(int n)
{
	string res = "";
	while(n / 10 > 0)
	{
		res += n % 10 + '0';
		n /= 10;
	}
	res += n % 10 + '0';
	string ans = "";
	for(int i = res.size() - 1; i >= 0; i--)
		ans += res[i];
	return ans;
}
ll string_to_int(string s)
{
	ll res = 0;
	for(int i = 0; i < s.size(); i++)
		res += (s[i] - '0') * pow(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}
vector<int> common_divisors(int a, int b)
{
	int tmp = get_gcd(a, b);
	vector<int> res;
	for(int i = 1; i <= sqrt(tmp); i++)
		if(tmp % i == 0)
		{
			if(i * i == tmp) res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(tmp / i);
			}
		}
	return res;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, n, m;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int even1 = 0;
		int odd1 = 0;
		int even2 = 0;
		int odd2 = 0;
		scanf("%d", &n);
		int tmp;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			if(tmp % 2 == 0) even1++;
			else odd1++;
		}

		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			if(tmp % 2 == 0) even2++;
			else odd2++;
		}
		ll res = (ll)even1 * even2 + (ll)odd1 * odd2;
		printf("%lld\n", res);


	}
	return 0;
}