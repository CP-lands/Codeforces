//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/456/problem/E
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int N = 3e5 + 1;
 
vector<int> g[N];
bool vst[N];
vector<pair<pair<int, int>, pair<int, int>>> path(N);
int center[N];
int middle = 0;
int diff = INT_MAX;
int longestPath = -1;
 
void ini(){
	for(int i = 0; i < N; i++){
		vst[i] = false;
		center[i] = -1;
	}
}
void dfs(int u, int v = -1){
	vst[u] = true;
	path[u] = {{0, 0}, {0, 0}};
	for(auto x: g[u]){
		if(x == v) continue;
		dfs(x, u);
	}
	vector<pair<int, int>> tmp;
	for(auto x: g[u]){
		if(x == v) continue;
		tmp.pb({path[x].fi.fi + 1, x});
	}
	sort(tmp.rbegin(), tmp.rend());
	if(tmp.size() > 0) path[u].fi = tmp[0];
	if(tmp.size() > 1) path[u].se = tmp[1];
}
void dfs1(int u, int v = -1){
	for(auto x: g[u]){
		if(x == v) continue;
		if(path[x].fi.fi == 0){
			if(path[u].fi.se != x) path[x].fi = {path[u].fi.fi + 1, u};
			else path[x].fi = {path[u].se.fi + 1, u};
		}
		else{
			if(path[u].fi.se != x && path[x].se.fi < path[u].fi.fi + 1) path[x].se = {path[u].fi.fi + 1, u};
			else if(path[x].se.fi < path[u].se.fi + 1) path[x].se = {path[u].se.fi + 1, u};
		}
		if(path[x].fi.fi < path[x].se.fi){
			pair<int, int> tmp = path[x].fi;
			path[x].fi = path[x].se;
			path[x].se = tmp;
		}
		dfs1(x, u);
	}
	if(path[u].fi.fi + path[u].se.fi == longestPath){
		int tmp = abs(path[u].fi.fi - path[u].se.fi);
		if(tmp < diff){
			diff = tmp;
			middle = u;
		}
	}
	if(path[u].fi.fi + path[u].se.fi > longestPath){
		middle = u;
		longestPath = path[u].fi.fi + path[u].se.fi;
		diff = abs(path[u].fi.fi - path[u].se.fi);
	}
}
void dfs2(int u, int v = -1){
	if(u != middle) center[u] = middle;
	for(auto x: g[u]){
		if(x == v) continue;
		dfs2(x, u);
	}
}
int root(int a){
    if(center[a] == -1) return a;
    return center[a] = root(center[a]);
}
void uni(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
		if(path[x].fi.fi + path[x].se.fi >= path[y].fi.fi + path[y].se.fi){
			center[y] = x;
			path[x].se.fi = max(path[x].se.fi, path[y].fi.fi + 1);
			if(path[x].fi.fi < path[x].se.fi){
				int tmp = path[x].fi.fi;
				path[x].fi.fi = path[x].se.fi;
				path[x].se.fi = tmp;
			}
		}
		else{
			center[x] = y;
			path[y].se.fi = max(path[y].se.fi, path[x].fi.fi + 1);
			if(path[y].fi.fi < path[y].se.fi){
				int tmp = path[y].fi.fi;
				path[y].fi.fi = path[y].se.fi;
				path[y].se.fi = tmp;
			}
		}
    }
void Solve(){
	int n, m, q;
	cin>>n>>m>>q;
	while(m--){
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	ini();
	for(int i = 1; i <= n; i++){
		if(vst[i]) continue;
		middle = i;
		dfs(i);
		dfs1(i);
		dfs2(i);
		longestPath = -1;
	}
	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int x;
			cin>>x;
			x = root(x);
			cout<<path[x].fi.fi + path[x].se.fi<<nl;
		}
		else{
			int x, y;
			cin>>x>>y;
			uni(x, y);
		}
	}
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}