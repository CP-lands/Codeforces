//___1 WA == 5 Push up___
//------Anivia_kid----------
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
	int q;
	cin>>q;
	for(int j = 0; j < q; j++)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin>>v[i];
		sort(v.begin(), v.end());
		int tmp = 1;
		for(int i = 0; i < n - 1; i++)
		{
			if(v[i + 1] - v[i] == 1)
			{
				tmp = 0;
				cout<<2<<endl;
				break;
			}
		}
		if(tmp == 1) cout<<1<<endl;
	}
 
 
	return 0;
}