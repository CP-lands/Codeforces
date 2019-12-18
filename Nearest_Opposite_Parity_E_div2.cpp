//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1272/problem/E
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
	vector<int> v(n);
	vector<int> g[n];
	for(int i = 0; i < n; i++){
		cin>>v[i];
		if(i + v[i] < n) g[i + v[i]].pb(i);
		if(i - v[i] >= 0) g[i - v[i]].pb(i);
	}
	vector<int> res(n);
	queue<int> q;
	for(int i = 0; i < n; i++)
		res[i] = INT_MAX;
	vector<bool> visited(n);
	for(int i = 0; i < n; i++){
		if(v[i] % 2 != 0) continue;
		q.push(i);
		visited[i] = true;
	}
	vector<int> even(n);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				even[x] = even[current] + 1;
				res[x] = even[x];
			}
		}
	}
	vector<int> odd(n);
	vector<bool> visit(n);
	queue<int> qq;
	for(int i = 0; i < n; i++){
		if(v[i] % 2 == 0) continue;
		qq.push(i);
		visit[i] = true;
	}
	while(!qq.empty()){
		int current = qq.front();
		qq.pop();
		for(auto x: g[current]){
			if(!visit[x]){
				visit[x] = true;
				qq.push(x);
				odd[x] = odd[current] + 1;
				res[x] = odd[x];
			}
		}
	}
	for(auto x: res){
		if(x == INT_MAX) cout<<-1<<" ";
		else cout<<x<<" ";
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