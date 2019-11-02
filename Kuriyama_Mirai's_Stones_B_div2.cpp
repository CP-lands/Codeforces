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
	return (n * comb(n - 1, k)) / (n - k);
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
ll pow(int a, int b)
{
	if(b == 0) return 1;
	if(b == 1) return a;
	ll res = 1;
	for(int i = 0; i < b; i++)
		res *= a;
	return res;
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
int main()
{
	int n, m, type, l, r;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	vector<ll> v(n), u(n);
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		v[i] = sum;
	}
	sort(a.begin(), a.end());
	sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		u[i] = sum;
	}

	cin>>m;
	for(int i = 0; i < m; i++)
	{
		cin>>type>>l>>r;
		if(type == 1)
		{
			if(l > 1)
				cout<<(ll)v[r - 1] - v[l - 2]<<endl;
			else
				cout<<(ll)v[r - 1]<<endl;
		}
		else
		{
			if(l > 1)
				cout<<(ll)u[r - 1] - u[l - 2]<<endl;
			else
				cout<<(ll)u[r -1]<<endl;
		}
	}

	return 0;
}
