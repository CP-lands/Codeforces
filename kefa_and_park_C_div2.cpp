//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/580/problem/C
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
	ll cat[n + 1];
	for(int i = 1; i <= n; i++)
		cin>>cat[i];
	vector<int> g[n + 1];
	vector<bool> visited(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int res = 0;
	while(!q.empty()){
		int start = q.front();
		q.pop();
		for(auto x : g[start]){
			if(!visited[x]){
				visited[x] = true;
				if(cat[start] >= 1 && cat[x] == 1) cat[x] += cat[start];
				if(cat[start] > m) cat[x] = cat[start];
				if(g[x].size() == 1 && cat[x] <= m) res++;
				else q.push(x);
			}
		}
	}
	cout<<res<<endl;

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
	return 0;
}
