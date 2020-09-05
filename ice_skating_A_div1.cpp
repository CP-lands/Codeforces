//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/217/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

map<pair<int, int>, int> my_map;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> col(1001), row(1001);
	vector<pair<int, int>> cor;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		cor.pb({x, y});
		my_map[{x, y}] = i;
	}

	int res = 0;
	vector<pair<int, int>> g[n];
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(cor[j].fi == cor[i].fi || cor[j].se == cor[i].se){
				g[i].pb({cor[j].fi, cor[j].se});
				g[j].pb({cor[i].fi, cor[i].se});
			}
		}
	}

	vector<bool> visited(n);
	queue<int> q;
	visited[0] = true;
	for(int i = 0; i < n; i++){
		q.push(i);
		if(!visited[i]) res++;
		visited[i] = true;
		while(!q.empty()){
			int start = q.front();
			q.pop();
			for(auto x: g[start]){
				if(!visited[my_map[{x.fi, x.se}]]){
					visited[my_map[{x.fi, x.se}]] = true;
					q.push(my_map[{x.fi, x.se}]);
				}
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
