//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/601/A
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
	set<int> s[n + 1];
	vector<int> train[n + 1];
	vector<int> bus[n + 1];
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		train[u].pb(v);
		train[v].pb(u);
		s[u].insert(v);
		s[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i].find(j) == s[i].end() && j != i) bus[i].pb(j);
		}
	}
	queue<int> q1;
	vector<bool> visited1(n + 1);
	q1.push(1);
	visited1[1] = true;
	vector<int> path1(n + 1);
	path1[1] = 0;
	while(!q1.empty()){
		int current = q1.front();
		q1.pop();
		for(auto x: train[current]){
			if(!visited1[x]){
				visited1[x] = true;
				q1.push(x);
				path1[x] = path1[current] + 1;
			}
		}
	}
	queue<int> q2;
	vector<bool> visited2(n + 1);
	q2.push(1);
	visited2[1] = true;
	vector<int> path2(n + 1);
	path2[1] = 0;
	while(!q2.empty()){
		int current = q2.front();
		q2.pop();
		for(auto x: bus[current]){
			if(!visited2[x]){
				visited2[x] = true;
				q2.push(x);
				path2[x] = path2[current] + 1;
			}
		}
	}
	if(path2[n] == 0 || path1[n] == 0){
		cout<<-1<<"\n";
		return;
	}
	cout<<max(path1[n], path2[n])<<"\n";
 
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
