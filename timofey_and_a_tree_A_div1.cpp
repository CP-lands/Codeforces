//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/763/A
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
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> color(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>color[i];
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int root[2] = {1, 1};
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				if(color[x] != color[current]){
					root[0] = x;
					root[1] = current;
					break;
				}
			}
			if(root[0] != 1) break;
		}
		if(root[0] != 1) break;
	}

	int res[2] = {0, 0};
	int ans;
	for(int i = 0; i < 2; i++){
		vector<bool> visit(n + 1);
		queue<int> q2;
		visit[root[i]] = true;
		for(auto x: g[root[i]]){
			q2.push(x);
			visit[x] = true;
			while(!q2.empty()){
				int current = q2.front();
				q2.pop();
				for(auto y : g[current]){
					if(!visit[y]){
						visit[y] = true;
						q2.push(y);
						if(color[y] != color[current]){
							res[i]++;
							ans = root[i];
						}
					}
				}
			}
		}
	}
	if(res[0] > 0 && res[1] > 0) cout<<"NO\n";
	else{
		cout<<"YES\n";
		if(ans == root[0]) cout<<root[1]<<"\n";
		else cout<<root[0]<<"\n";
	}
 
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
}
