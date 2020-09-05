//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/522/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

string to_lower(string s){
	string res = "";
	for(auto x: s)
		res += (char)tolower(x);
	return res;
}

void Anivia_kid(){
	int n;
	cin>>n;
	map<string, string> my_map;
	for(int i = 0; i < n; i++){
		string s1, s2, s3;
		cin>>s1>>s2>>s3;
		my_map[s1] = s3;
	}
	map<string, int> convert;
	convert["polycarp"] = 0;
	int i = 1;
	for(auto x: my_map)
		convert[to_lower(x.fi)] = i++;
	vector<int> g[n + 1];
	for(auto x: my_map){
		int u = convert[to_lower(x.fi)];
		int v = convert[to_lower(x.se)];
		g[u].pb(v);
		g[v].pb(u);
	}
	int res = 0;
	queue<int> q;
	q.push(0);
	vector<bool> visited(n + 1);
	visited[0] = true;
	vector<int> trace(n + 1);
	trace[0] = 1;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				trace[x] = trace[current] + 1;
			}
		}
	}
	for(auto x: trace)
		if(res < x) res = x;
	cout<<res<<"\n";

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
