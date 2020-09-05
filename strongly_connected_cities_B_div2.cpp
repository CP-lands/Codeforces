//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/475/B
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
	vector<int> g[n * m];
	string hor, ver;
	cin>>hor>>ver;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			if(hor[i] == '<') g[i * m + j + 1].pb(i * m + j);
			else g[i * m + j].pb(i * m + j + 1);
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n - 1; j++){
			if(ver[i] == 'v') g[j * m + i].pb((j + 1) * m + i);
			else g[(j + 1) * m + i].pb(j * m + i);
		}
	}

	int res = 0;
	for(int i = 0; i < n * m; i++){
		int tmp = 1;
		queue<int> q;
		vector<bool> visited(n * m);
		q.push(i);
		visited[i] = true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(!visited[x]){
					visited[x] = true;
					tmp++;
					q.push(x);
				}
			}
		}
		if(tmp == n * m) res++;
	}
	if(res == n * m) cout<<"YES\n";
	else cout<<"NO\n";
 
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
