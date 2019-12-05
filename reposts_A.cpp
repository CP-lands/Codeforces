//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/522/problem/A
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

string to_lower(string s){
	string res = "";
	for(auto x: s)
		res += (char)tolower(x);
	return res;
}

void Anivia_kid(){
	int n;
	cin>>n;
	map<string, string> my_map;
	for(int i = 0; i < n; i++){
		string s1, s2, s3;
		cin>>s1>>s2>>s3;
		my_map[s1] = s3;
	}
	map<string, int> convert;
	convert["polycarp"] = 0;
	int i = 1;
	for(auto x: my_map)
		convert[to_lower(x.fi)] = i++;
	vector<int> g[n + 1];
	for(auto x: my_map){
		int u = convert[to_lower(x.fi)];
		int v = convert[to_lower(x.se)];
		g[u].pb(v);
		g[v].pb(u);
	}
	int res = 0;
	queue<int> q;
	q.push(0);
	vector<bool> visited(n + 1);
	visited[0] = true;
	vector<int> trace(n + 1);
	trace[0] = 1;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				trace[x] = trace[current] + 1;
			}
		}
	}
	for(auto x: trace)
		if(res < x) res = x;
	cout<<res<<"\n";

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