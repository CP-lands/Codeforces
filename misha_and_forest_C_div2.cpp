//--------------------My dream = Phuong + Husky + Alaska-------------------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/501/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int N = 7e4;
vector<int> g[N];
bool vst[N];
 
vector<pair<int, int>> res;
 
void dfs(int u, int nxt = -1){
	vst[u] = true;
	for(auto x: g[u]){
		if(x == nxt) continue;
		res.pb({u, x});
		dfs(x, u);
	}
}
 
void Alice(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
		vst[i] = false;
	vector<pair<int, pair<int, int>>> v(n);
	set<pair<int, pair<int, int>>> s;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin>>a>>c;
		b = i;
		v[i] = {a, {b, c}};
		if(a > 0) s.insert({a, {b, c}});
	}
	while(!s.empty()){
		pair<int, pair<int, int>> p = *s.begin();
		//cout<<p.fi<<" "<<p.se.se<<" "<<p.se.fi<<nl;
		s.erase(s.begin());
		int u = p.se.fi;
		int a = 0;
		for(auto x: g[u]){
			a ^= x;
		}
		int k = a ^ p.se.se;
		g[u].pb(k);
		g[k].pb(u);
		s.erase(v[k]);
		v[k].fi--;
		if(v[k].fi > 0) s.insert(v[k]);
	}
	for(int i = 0; i < n; i++){
		if(vst[i]) continue;
		dfs(i);
	}
	cout<<res.size()<<nl;
	for(auto x: res){
		cout<<x.fi<<" "<<x.se<<nl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Alice();
	}
}