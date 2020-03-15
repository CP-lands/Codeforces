//https://codeforces.com/contest/1176/problem/E
#include<bits/stdc++.h>
 
using namespace std;

void Solve(){
	int n, m;
	cin>>n>>m;
	vector<int> g[n + 1];
	while(m--){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> odd, even;
	vector<bool> dif(n + 1);
	queue<int> q;
	vector<bool> visited(n + 1);
	q.push(1);
	visited[1] = true;
	odd.push_back(1);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				if(!dif[current]) dif[x] = true;
				if(dif[x]) even.push_back(x);
				else odd.push_back(x);
			}
		}
	}
	if(odd.size() <= even.size()){
		cout<<odd.size()<<'\n';
		for(auto x: odd) cout<<x<<" ";
	}
	else{
		cout<<even.size()<<'\n';
		for(auto x: even) cout<<x<<" ";
	}
	cout<<'\n';
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Solve();
	}
}
