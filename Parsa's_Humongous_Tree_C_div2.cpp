#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1529/problem/C
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
const int N = 2e5 + 1;
vector<pair<int, int>> range(N);
vector<int> g[N];
 
ll mx[N];
ll mn[N];
 
void dfs(int u = 1, int v = -1){
	mx[u] = mn[u] = 0;
	for(auto x: g[u]){
		if(x == v) continue;
		dfs(x, u);
		ll maxx = max((ll)abs(range[u].se - range[x].se) + mx[x], (ll)abs(range[u].se - range[x].fi) + mn[x]);
		mx[u] += maxx;
		ll minn = max((ll)abs(range[u].fi - range[x].se) + mx[x], (ll)abs(range[u].fi - range[x].fi) + mn[x]);
		mn[u] += minn;
	}
}
 
void Solve(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>range[i].fi>>range[i].se;
	for(int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 0; i <= n; i++){
		mx[i] = 0;
		mn[i] = 0;
	}
	dfs();
	cout<<max(mn[1], mx[1])<<nl;
	for(int i = 1; i <= n; i++)
		g[i].clear();
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}