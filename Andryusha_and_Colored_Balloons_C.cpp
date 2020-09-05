//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/780/C
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
	int n;
	cin>>n;
	vector<int> g[n + 1];
	int numb_color = 0;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int x = 1; x <= n; x++)
		if(numb_color <= g[x].size()) numb_color = g[x].size() + 1;
	vector<bool> visited(n + 1);
	vector<int> res(n + 1);
	res[1] = 1;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int color = 1;
	int trace[n + 1];
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				trace[x] = res[current];
				color++;
				if(color > numb_color) color = 1;
				while(color == trace[current] || color == res[current]){
					color++;
					if(color > numb_color) color = 1;
				}
				res[x] = color;
			}
		}
	}
	cout<<numb_color<<"\n";
	for(int i = 1; i <= n; i++)
		cout<<res[i]<<" ";

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
