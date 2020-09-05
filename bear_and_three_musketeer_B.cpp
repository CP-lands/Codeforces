//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/574/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	set<int> s[n + 1];
	vector<int> g[n + 1];
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		s[u].insert(v);
		s[v].insert(u);
	}
	ll res = INT_MAX;
	for(int i = 1; i <= n; i++){
		vector<bool> visited(n + 1);
		ll tmp = 0;
		int current = i;
		visited[i] = true;
			for(auto x: g[current]){
				if(!visited[x]){
					for(auto y: g[x]){
						if(s[current].find(y) != s[current].end()){
							tmp = g[current].size() + g[x].size() + g[y].size() - 6;
							if(res > tmp) res = tmp;
						}
					}
					visited[x] = true;
				}
			}
	}
	if(res == INT_MAX) cout<<-1<<"\n";
	else cout<<res<<"\n";
 	
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
