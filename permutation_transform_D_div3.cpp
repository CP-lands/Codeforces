#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1490/problem/D
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
const int N = 105;
vector<int> g[N];
 
int dist[N];
 
void dfs(int u){
	for(auto x: g[u]){
		dist[x] = dist[u] + 1;
		dfs(x);
	}
}
 
void Solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> index(n + 1);
	for(int i = 0; i < n; i++){
		cin>>v[i];
		index[v[i]] = i;
	}
	vector<bool> vst(n + 1);
	vst[index[n]] = true;
	for(int i = n - 1; i > 0; i--){
		int idx = index[i];
		int parent = n;
		for(int j = idx + 1; j < n; j++){
			if(v[j] > i) parent = min(parent, v[j]);
			if(vst[j]) break;
		}
		for(int j = idx - 1; j >= 0; j--){
			if(v[j] > i) parent = min(parent, v[j]);
			if(vst[j]) break;
		}
		g[parent].pb(i);
		vst[idx] = true;
	}
	dist[n] = 0;
	dfs(n);
	for(int i = 0; i < n; i++){
		cout<<dist[v[i]]<<" ";
	}
	cout<<nl;
	for(int i = 0; i < N; i++){
		g[i].clear();
		dist[i] = 0;
	}
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}