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
	vector<int> pipe(n + 1);
	vector<int> tmp(n + 1);
	int dd[n + 1];
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin>>u>>v>>d;
		pipe[u] = v;
		tmp[u]++;
		tmp[v]--;
		dd[u] = d;
	}
	vector<pair<pair<int, int>, int>> v;
	for(int i = 1; i <= n; i++){
		if(tmp[i] != 1) continue;
		int j = i;
		int maxx = dd[i];
		while(pipe[j] != 0){
			if(maxx > dd[j]) maxx = dd[j];
			j = pipe[j];
		}
		v.pb({{i, j}, maxx});
	}
	cout<<v.size()<<"\n";
	for(auto x: v){
		cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se<<"\n";
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
