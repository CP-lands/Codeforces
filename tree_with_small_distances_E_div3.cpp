//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
//https://codeforces.com/contest/1029/problem/E
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here"<<nl
typedef long long ll;
 
const int N = 2e5 + 1;
 
vector<int> g[N];
vector<int> dist(N);
vector<bool> isLeaf(N);
 
void dfs(int u = 1, int v = -1){
	if(g[u].size() == 1) isLeaf[u] = true;
	for(auto x: g[u]){
		if(x == v) continue;
		dist[x] = dist[u] + 1;
		dfs(x, u);
	}
}
 
void Solve(){
	int n;
	cin>>n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs();
	set<pair<int, int>> s;
	vector<bool> vst(N);
	for(int i = 1; i <= n; i++){
		if(dist[i] > 2){
			s.insert({dist[i], i});
		}
		else vst[i] = true;
	}
	int res = 0;
	while(!s.empty()){
		pair<int, int> p = *s.rbegin();
		s.erase(p);
		if(isLeaf[p.se]){
			for(auto x: g[p.se]){
				s.insert({dist[x], x});
				s.erase({dist[x], x});
				dist[x] = 1;
				res++;
				vst[x] = true;
				for(auto y: g[x]){
					s.insert({dist[y], y});
					s.erase({dist[y], y});
					dist[y] = min(dist[y], 2);
					vst[y] = true;
				}
			}
		}
		else{
			dist[p.se] = 1;
			vst[p.se] = true;
			res++;
			for(auto x: g[p.se]){
				s.insert({dist[x], x});
				s.erase({dist[x], x});
				dist[x] = min(dist[x], 2);
				vst[x] = true;
			}
		}
	}
	cout<<res<<nl;
	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}