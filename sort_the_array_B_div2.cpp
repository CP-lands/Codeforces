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
	int n, tmp;
	cin>>n;
	vector<int> v;
	v.push_back(INT_MIN);
	for(int i = 0; i < n; i++)
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	int start = 1;
	int end = 1;
	v.push_back(INT_MAX);

	for(int i = 1; i < n + 1; i++)
	{
		if(v[i] > v[i + 1] && v[i] > v[i - 1])
			start = i;
		if(start != 0 && v[i] < v[i - 1] && v[i] < v[i + 1])
		{
			end = i;
			break;
		}
	}
	tmp = v[end];
	v[end] = v[start];
	v[start] = tmp;
	for(int i = end; i < n + 1; i++)
		if(v[i] > v[i + 1])
		{
			cout<<"no"<<endl;
			return 0;
		}
	for(int i = 0; i <= start; i++)
		if(v[i] > v[i + 1])
		{
			cout<<"no"<<endl;
			return 0;
		}
	cout<<"yes"<<endl;
	cout<<start<<" "<<end<<endl;
	return 0;
}
