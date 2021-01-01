#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1139/problem/C
using namespace std;
 
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> g[N];
vector<bool> vst(N + 5);
map<pair<int, int>, int> color;
long long res = 1;
long long ans = 0;
 
void dfs(int u){
	ans++;
	vst[u] = true;
	for(auto x: g[u]){
		if(vst[x] || color[{u, x}] == 1) continue;
		dfs(x);
	}
}
void Solve(){
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n - 1; i++){
		int u, v, c;
		cin>>u>>v>>c;
		g[u].push_back(v);
		g[v].push_back(u);
		color[{u, v}] = color[{v, u}] = c;
	}
	for(int i = 0; i < k; i++){
		res *= (long long)n;
		res = res % MOD;
	}
	long long sub = 0;
	for(int i = 1; i <= n; i++){
		if(!vst[i]){
			ans = 0;
			long long a = 1;
			dfs(i);
			for(int i = 0; i < k; i++){
				a *= ans;
				a = a % MOD;
			}
			sub += a;
			sub = sub % MOD;
			//cout<<ans<<endl;
		}
	}
	res -= sub;
	if(res < 0) res += MOD;
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}