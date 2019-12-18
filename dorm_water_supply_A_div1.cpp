//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/107/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<int> g[n + 1];
	vector<int> tmp(n + 1);
	int dd[n + 1];
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin>>u>>v>>d;
		g[u].pb(v);
		dd[u] = d;
		tmp[u]++;
		tmp[v]--;
	}
	int maxx[n + 1][n + 1];
	vector<pair<int, int>> res;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(tmp[i] != 1) continue;
		int mass = dd[i];
		q.push(i);
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(g[x].size() == 0){
					res.pb({i, x});
					maxx[i][x] = mass;
				}
				else{
					q.push(x);
					if(mass > dd[x]) mass = dd[x];
				}
			}
		}
	}
	cout<<res.size()<<"\n";
	for(auto x: res){
		cout<<x.fi<<" "<<x.se<<" "<<maxx[x.fi][x.se]<<"\n";
	}
 	
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
