//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/689/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> g[n + 1];
	for(int i = 1; i <= n; i++){
		if(i != n){
			g[i].pb(i + 1);
			g[i + 1].pb(i);
		}
		int j;
		cin>>j;
		g[i].pb(j);
	}
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	vector<int> res(n + 1);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		visited[current] = true;
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				res[x] = res[current] + 1;
			}
		}
	}
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
}
