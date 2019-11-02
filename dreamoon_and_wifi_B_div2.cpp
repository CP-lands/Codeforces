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
int sum = 0;
void backtrack(vector<vector<int>> &path, vector<int> &res, int st)
{
	for(auto i = 0; i < path[st].size(); i++)
	{
		int a = st;
		int b = i;
		sum += path[st][i];
		if(st == path.size() - 1) res.push_back(sum);
		else backtrack(path, res, st + 1);
		sum -= path[a][b];
	}
}

int main()
{
	string send, receive;
	cin>>send>>receive;
	int pos = 0;
	for(auto x : send)
	{
		if(x == '+') pos++;
		else pos--;
	}
	int count = 0;
	vector<vector<int>> path;
	vector<int> res;
	for(auto x : receive)
	{
		if(x == '-') path.push_back({-1});
		if(x == '+') path.push_back({1});
		if(x == '?') 
		{
			path.push_back({-1, 1});
			count++;
		}
	}
	int prob = pow(2, count);
	double k = 0;
	backtrack(path, res, 0);
	for(auto x : res)
		if(x == pos) k++;
	k = (double)k/prob;
	cout<<fixed<<setprecision(9)<<k<<endl;

	return 0;
}
/*
int main()
{
	int n, m, k, r, l;
	cin>>n>>m>>k;
	map<int, int> mp;
	for(int i = 0; i < k; i++)
	{
		cin>>r>>l;
		mp.insert({r, l});
	}
	for(auto x : mp)
		cout<<x.first<<" "<<x.second<<endl;
	return 0;

}
*/
/*
int main()
{
	int n, m, k, x, y;
	cin>>n>>m>>k;
	vector<vector<int>> map(n, vector<int> (m));
	for(int i = 0; i < k; i++)
	{
		cin>>x>>y;
		map[x - 1][y - 1] = 1;
	}
	x = 0;
	y = 0;
	int count = 0;
	int direct = 1;
	while(true)
	{
		map[y][x] = 1;
		count++;
		if(direct == 1 && x + 1 < m && map[y][x + 1] == 0)
			x++;
		else if(direct == 1 && y + 1 < n && map[y + 1][x] == 0)
		{
			y++;
			direct = 2;
		}
		else if(direct == 2 && y + 1 < n && map[y + 1][x] == 0)
			y++;
		else if(direct == 2 && x - 1 >= 0 && map[y][x - 1] == 0)
		{
			x--;
			direct = 3;
		}
		else if(direct == 3 && x - 1 >= 0 && map[y][x - 1] == 0)
			x--;
		else if(direct == 3 && y - 1 >= 0 && map[y - 1][x] == 0)
		{
			y--;
			direct = 4;
		}
		else if(direct == 4 && y - 1 >= 0 && map[y - 1][x] == 0)
			y--;
		else if(direct == 4 && x + 1 < m && map[y][x + 1] == 0)
		{
			x++;
			direct = 1;
		}
		else
			break;
	}
	cout<<count<<endl;
	if(n * m - count == k) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
*/