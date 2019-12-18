//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1277/problem/E
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, m, a, b;
	cin>>n>>m>>a>>b;
	vector<int> A[n + 1];
	vector<int> B[n + 1];
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		if(u != a && v != a){
			B[u].pb(v);
			B[v].pb(u);
		}
		if(u != b && v != b){
			A[u].pb(v);
			A[v].pb(u);
		}
	}

	set<int> res_a;
	set<int> res_b;
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(a);
	visited[a] = true;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: A[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				res_a.insert(x);
			}
		}
	}
	vector<bool> visit(n + 1);
	queue<int> q1;
	q1.push(b);
	visit[b] = true;
	while(!q1.empty()){
		int current = q1.front();
		q1.pop();
		for(auto x: B[current]){
			if(!visit[x]){
				visit[x] = true;
				q1.push(x);
				res_b.insert(x);
			}
		}
	}
	int count = 0;
	while(!res_a.empty()){
		int x = *res_a.begin();
		if(res_b.find(x) == res_b.end()){
			count++;
		}
		else res_b.erase(x);
		res_a.erase(x);
	}
	ll res = (ll)count * (ll)res_b.size();
	cout<<res<<"\n";
 
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
		Anivia_kid();
	}
}
