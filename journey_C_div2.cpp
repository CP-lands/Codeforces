//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/839/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
bool isPrime(ll n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
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
		res += (s[i] - '0') * power(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> g[n + 1];
	double res = 0;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<bool> visited(n + 1);
	vector<double> exp_val(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	exp_val[1] = (double)1 / (g[1].size());
	vector<double> len(n + 1);
	len[1] = 0;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				len[x] = len[current] + 1;
				visited[x] = true;
				if(g[x].size() == 1){
					res += (double)len[x] * exp_val[current];
				}
				else exp_val[x] = (double)exp_val[current] / (g[x].size() - 1);
				q.push(x);
			}
		}
	}

	cout<<fixed<<setprecision(6)<<res<<endl;

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}