//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/429/A
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
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> ini(n + 1), fin(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>ini[i];
	for(int i = 1; i <= n; i++)
		cin>>fin[i];
	vector<int> res;
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	vector<int> odd(n + 1), even(n + 1);
	vector<int> level(n + 1);
	if(ini[1] != fin[1]){
		even[1] = 1;
		res.pb(1);
	}
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				level[x] = level[current] + 1;
				if(ini[x] != fin[x]){
					if(level[x] % 2 == 0){
						if(even[current] % 2 == 0){
							res.pb(x);
							even[x] = even[current] + 1;
							odd[x] = odd[current];
						}
						else{
							even[x] = even[current];
							odd[x] = odd[current];
						}
					}
					else{
						if(odd[current] % 2 == 0){
							res.pb(x);
							odd[x] = odd[current] + 1;
							even[x] = even[current];
						}
						else{
							odd[x] = odd[current];
							even[x] = even[current];
						}
					}
				}
				else{
					if(level[x] % 2 == 0){
						if(even[current] % 2 != 0){
							res.pb(x);
							even[x] = even[current] + 1;
						}
						else even[x] = even[current];
						odd[x] = odd[current];
					}
					else{
						if(odd[current] % 2 != 0){
							res.pb(x);
							odd[x] = odd[current] + 1;
						}
						else odd[x] = odd[current];
						even[x] = even[current];
					}
				}
			}
		}
	}
	cout<<res.size()<<"\n";
	for(auto x: res)
		cout<<x<<"\n";

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
