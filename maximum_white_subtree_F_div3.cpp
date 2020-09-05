#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/1324/F
using namespace std;

const int N = 200001;
int a[N], dp[N], ans[N];
vector<int> g[N];

void dfs(int u, int v = -1){
	dp[u] = a[u];
	for(auto x: g[u]){
		if(x == v) continue;
		dfs(x, u);
		dp[u] += max(0, dp[x]);
	}
	return;
}
void dfs2(int u, int v = -1){
	ans[u] = dp[u];
	for(auto x: g[u]){
		if(x == v) continue;
		dp[u] -= max(0, dp[x]);
		dp[x] += max(0, dp[u]);
		dfs2(x, u);
		dp[x] -= max(0, dp[u]);
		dp[u] += max(0, dp[x]);
	}
	return;
}

void Solve(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] == 0) a[i] = -1;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dp, 0, N);
	dfs(1);
	dfs2(1);
	for(int i = 1; i <= n; i++)
		cout<<ans[i]<<" ";

	return;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
}
