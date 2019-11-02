//___1 WA == 5 Push up___
//------Anivia_kid----------
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
		string s;
		cin>>s;
		string a, b;
		for(auto x : s)
		{
			if((x - '0') % 2 == 0) a += x;
			else b += x;
		}
		int m = 0;
		int n = 0;
		while(m <= a.size() || n <= b.size())
		{
			if(m == a.size())
			{
				for(int i = n; i < b.size(); i++)
					cout<<b[i];
				break;
			}
			if(n == b.size())
			{
				for(int i = m; i < a.size(); i++)
					cout<<a[i];
				break;
			}
			if(a[m] - '0' < b[n] - '0')
				cout<<a[m++];
			else
				cout<<b[n++];
		}
		cout<<endl;
	}

	return 0;
}