#include<bits/stdc++.h>  

//https://codeforces.com/contest/1454/problem/E
using namespace std; 
const int N = 2e5 + 1;
pair<int, int> inter;
vector<int> g[N];
long long paths[N];
int childs[N];
long long res = 0;
int parents[N];
void dfs(int u, int v = -1){
	for(auto x: g[u]){
		if(x == v || x == inter.second) continue;
		parents[x] = u;
		dfs(x, u);
		childs[u] += childs[x];
	}
}
void Solve(){
	int n;
	cin>>n;
	res = 0;
	for(int i = 1; i <= n; i++){
		childs[i] = 1;
	}
	for(int i = 0; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	vector<bool> vst(n + 1);
	q.push(1);
	vst[1] = true;
	map<int, int> parent;
	parent[1] = 0;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		bool exit = false;
		for(auto x: g[current]){
			if(vst[x] && parent[current] != x){
				vector<int> tmp1, tmp2;
				for(auto y: g[current]){
					if(y != x) tmp1.push_back(y);
				}
				for(auto y: g[x]){
					if(y != current) tmp2.push_back(y);
				}
				g[current].clear();
				g[current] = tmp1;
				g[x].clear();
				g[x] = tmp2;
				inter = {x, current};
				exit = true;
				break;
			}
			else if(vst[x]) continue;
			q.push(x);
			vst[x] = true;
			parent[x] = current;
		}
		if(exit) break;
	}
	for(int i = 1; i <= n; i++) childs[i] = 1;
	parents[inter.second] = 0; 
	childs[0] = 0;     
	dfs(inter.second);
	res = (long long)n * (n - 1) / 2;
	int now = inter.first;
	int pre = 0;
	while(true){
		res += (long long)(childs[now] - childs[pre]) * (childs[inter.second] - childs[now]);
		pre = now;
		now = parents[now];
		if(now == inter.second || now == 0) break;
	}
	cout<<res<<'\n';
	for(int i = 1; i <= n; i++) g[i].clear();
}
int main()  
{  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}
