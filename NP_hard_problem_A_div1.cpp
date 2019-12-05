//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/687/problem/A
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
vector<int> g[100001];
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> A, B;
	vector<int> val(100001);
	for(int i = 1; i <= n; i++){
		queue<int> q;
		q.push(i);
		if(val[i] != 0 || g[i].size() == 0) continue;
		if(i % 2 == 0) val[i] = 1;
		else val[i] = -1;
		while(!q.empty()){
			int start = q.front();
			q.pop();
			for(auto x : g[start]){
				if(val[x] == val[start]){
					cout<<-1<<endl;
					return;
				}
				if(val[x] == 0){
					val[x] = val[start] * -1;
					q.push(x);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(val[i] == 1) A.pb(i);
		if(val[i] == -1) B.pb(i);
	}
	cout<<A.size()<<endl;
	for(auto x: A)
		cout<<x<<" ";
	cout<<endl<<B.size()<<endl;
	for(auto x: B)
		cout<<x<<" ";

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