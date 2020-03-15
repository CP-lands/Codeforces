#include<bits/stdc++.h>

//https://codeforces.com/contest/1325/problem/C
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    if(n == 2){
        cout<<0<<'\n';
        return;
    }
    vector<int> g[n + 1];
    vector<pair<int, int>> res;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        res.push_back({u, v});
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1){
            for(auto x: g[i]){
                mp[{i, x}] = mp[{x, i}] = count++;
            }
        }
    }
    vector<bool> visited(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
 
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto x: g[current]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                if(!mp.count({x, current})) mp[{x, current}] = mp[{current, x}] = count++;
            }
        }
    }
 
    for(auto x: res){
        cout<<mp[{x.first, x.second}]<<'\n';
    }
 
	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}