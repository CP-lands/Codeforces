//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/659/problem/E
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
typedef long long ll;
 
const int N = 1e5 + 1;
 
vector<int> g[N];
void Solve(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<bool> vst(n + 1);
	vector<int> parent(n + 1);
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(vst[i]) continue;
		queue<int> q;
		q.push(i);
		vst[i] = true;
		bool cycle = false;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(vst[x] && parent[current] != x) cycle = true;
				if(!vst[x]){
					vst[x] = true;
					q.push(x);
					parent[x] = current;
				}
			}
		}
		if(!cycle) res++;
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