//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/277/problem/A
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
	vector<int> g[n + 1];
	vector<int> lang[m + 1];
	vector<int> people[n + 1];
	vector<bool> visited(n + 1);
	for(int i = 1; i <= n; i++){
		int num;
		cin>>num;
		while(num--){
			int k;
			cin>>k;
			lang[k].pb(i);
			people[i].pb(k);
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto x: people[i]){
			for(auto y: lang[x]){
				if(y != i) g[i].pb(y);
			}
		}
	}
	int count = 0;
	for(int i = 1; i <= m; i++){
		if(lang[i].size() == 0) count++;
	}
	if(count == m){
		cout<<n<<endl;
		return;
	}
	queue<int> q;
	int res = 0;
	for(int i = 1; i <= n; i++){
		q.push(i);
		if(!visited[i]) res++;
		visited[i] = true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(!visited[x]){
					visited[x] = true;
					q.push(x);
				}
			}
		}
  	}
	cout<<res - 1<<endl;

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
