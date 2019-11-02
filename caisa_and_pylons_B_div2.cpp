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
	int n;
	cin>>n;
	vector<int> res(n + 1);
	res[0] = 0;
	for(int i = 1; i <= n; i++)
		cin>>res[i];
	ll ener = 0;
	ll dollar = 0;
	for(int i = 1; i <= n; i++)
	{
		ener += res[i - 1] - res[i];
		if(ener < 0)
		{
			dollar += -ener;
			ener = 0;
		}
	}
	
	cout<<dollar<<endl;

	return 0;
}
/*
int main()
{
	ll n, p , w, d;
	cin>>n>>p>>w>>d;
	ll tmp = (w * n - p) / (w - d);
	ll x, y, z;
	for(ll i = tmp; i >= 0; i--)
	{
		y = i;
		x = (p - y * d) / w;
		z = n - x - y;
		if(x + y + z == n && w * x + d * y == p && x >=0 && y >= 0 && z >= 0)
		{
			cout<<x<<" "<<y<<" "<<z<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}*/
/*
int main()
{
	ll n, k;
	cin>>n>>k;
	vector<int> res(n);
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin>>tmp;
		res[i] = tmp;
	}
	sort(res.begin(), res.end());
	int count = 0;
	tmp = 1;
	while(count < k)
	{
		if(res[0] == res[res.size() - 1])
		{
			cout<<count<<endl;
			return 0;
		}
		if(tmp == 1)
		{
			res[0]++;
			count++;
		}
		else if(tmp == -1)
		{
			res[res.size() - 1]--;
			count++;
		}
		int temp = res[0];
		int temp2 = res[res.size() - 1];
		sort(res.begin(), res.end());
		if(temp != res[0] || temp2 != res[res.size() - 1]) tmp *= -1; 
	}
	cout<<res[res.size() - 1] - res[0]<<endl;
	return 0;
} 
*/