//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/246/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

set<int> c;
set<int> res[100001];
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<int> color(n + 1);
	for(int i = 1; i <= n; i++){
		cin>>color[i];
		c.insert(color[i]);
	}
	vector<int> g[n + 1];
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<bool> visited(n + 1);
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
		if(visited[i]) continue;
		visited[i] = true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(color[current] != color[x]) res[color[current]].insert(color[x]);
				if(!visited[x]){
					visited[x] = true;
					q.push(x);
				}
			}
		}
	}

	int ans = *c.begin();
	int size = 0;
	while(!c.empty()){
		int tmp = *c.begin();
		c.erase(tmp);
		if(size < res[tmp].size()){
			size = res[tmp].size();
			ans = tmp;
		}
	}
	cout<<ans<<"\n";
 	
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
