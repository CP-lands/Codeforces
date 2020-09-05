//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/839/problem/C
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
	double res = 0;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<bool> visited(n + 1);
	vector<double> exp_val(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	exp_val[1] = (double)1 / (g[1].size());
	vector<double> len(n + 1);
	len[1] = 0;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				len[x] = len[current] + 1;
				visited[x] = true;
				if(g[x].size() == 1){
					res += (double)len[x] * exp_val[current];
				}
				else exp_val[x] = (double)exp_val[current] / (g[x].size() - 1);
				q.push(x);
			}
		}
	}

	cout<<fixed<<setprecision(6)<<res<<endl;

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
