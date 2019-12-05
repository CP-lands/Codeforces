//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/217/problem/A
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
map<pair<int, int>, int> my_map;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> col(1001), row(1001);
	vector<pair<int, int>> cor;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		cor.pb({x, y});
		my_map[{x, y}] = i;
	}

	int res = 0;
	vector<pair<int, int>> g[n];
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(cor[j].fi == cor[i].fi || cor[j].se == cor[i].se){
				g[i].pb({cor[j].fi, cor[j].se});
				g[j].pb({cor[i].fi, cor[i].se});
			}
		}
	}

	vector<bool> visited(n);
	queue<int> q;
	visited[0] = true;
	for(int i = 0; i < n; i++){
		q.push(i);
		if(!visited[i]) res++;
		visited[i] = true;
		while(!q.empty()){
			int start = q.front();
			q.pop();
			for(auto x: g[start]){
				if(!visited[my_map[{x.fi, x.se}]]){
					visited[my_map[{x.fi, x.se}]] = true;
					q.push(my_map[{x.fi, x.se}]);
				}
			}
		}
	}
	cout<<res<<endl;

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