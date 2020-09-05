//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/687/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

vector<int> g[100001];
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> A, B;
	vector<int> val(100001);
	for(int i = 1; i <= n; i++){
		queue<int> q;
		q.push(i);
		if(val[i] != 0 || g[i].size() == 0) continue;
		if(i % 2 == 0) val[i] = 1;
		else val[i] = -1;
		while(!q.empty()){
			int start = q.front();
			q.pop();
			for(auto x : g[start]){
				if(val[x] == val[start]){
					cout<<-1<<endl;
					return;
				}
				if(val[x] == 0){
					val[x] = val[start] * -1;
					q.push(x);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(val[i] == 1) A.pb(i);
		if(val[i] == -1) B.pb(i);
	}
	cout<<A.size()<<endl;
	for(auto x: A)
		cout<<x<<" ";
	cout<<endl<<B.size()<<endl;
	for(auto x: B)
		cout<<x<<" ";

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
