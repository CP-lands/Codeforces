//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/763/A
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
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> color(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>color[i];
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int root[2] = {1, 1};
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				if(color[x] != color[current]){
					root[0] = x;
					root[1] = current;
					break;
				}
			}
			if(root[0] != 1) break;
		}
		if(root[0] != 1) break;
	}

	int res[2] = {0, 0};
	int ans;
	for(int i = 0; i < 2; i++){
		vector<bool> visit(n + 1);
		queue<int> q2;
		visit[root[i]] = true;
		for(auto x: g[root[i]]){
			q2.push(x);
			visit[x] = true;
			while(!q2.empty()){
				int current = q2.front();
				q2.pop();
				for(auto y : g[current]){
					if(!visit[y]){
						visit[y] = true;
						q2.push(y);
						if(color[y] != color[current]){
							res[i]++;
							ans = root[i];
						}
					}
				}
			}
		}
	}
	if(res[0] > 0 && res[1] > 0) cout<<"NO\n";
	else{
		cout<<"YES\n";
		if(ans == root[0]) cout<<root[1]<<"\n";
		else cout<<root[0]<<"\n";
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
